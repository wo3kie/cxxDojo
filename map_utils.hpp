#pragma once

/*
 * Website:
 *      https://github.com/wo3kie/cxxdojo
 *
 * Author:
 *      Lukasz Czerwinski
 */

#include <functional>
#include <map>
#include <type_traits>
#include <vector>

#include "./tuple_utils.hpp"

template<typename Iter, typename KeyGetter>
auto groupBy(Iter begin, Iter const end, KeyGetter getKey) {
  typedef typename std::iterator_traits<Iter>::value_type ValueType;
  typedef typename std::result_of<KeyGetter(ValueType)>::type KeyType;
  typedef std::map<KeyType, std::vector<ValueType>> ResultType;

  ResultType grouped;

  for(/* empty */; begin != end; ++begin) {
    grouped[getKey(*begin)].push_back(*begin);
  }

  return grouped;
}

template<typename Iter, typename KeyGetter, typename ValueGetter, typename ValuesMerger, typename MergedValues>
auto groupBy(
    Iter begin, Iter const end, KeyGetter getKey, ValueGetter getValue, ValuesMerger mergeValues, MergedValues init) {
  typedef typename std::iterator_traits<Iter>::value_type ObjectType;
  typedef typename std::result_of<ValueGetter(ObjectType)>::type ValueType;
  typedef typename std::result_of<KeyGetter(ObjectType)>::type KeyType;
  typedef std::map<KeyType, MergedValues> ResultType;

  ResultType grouped;

  for(/* empty */; begin != end; ++begin) {
    KeyType const& key = getKey(*begin);
    ValueType const& value = getValue(*begin);

    auto const keyIter = grouped.find(key);

    if(keyIter == grouped.end()) {
      grouped.insert(std::make_pair(key, mergeValues(init, value)));
    } else {
      keyIter->second = mergeValues(keyIter->second, value);
    }
  }

  return grouped;
}

/*
 * nested_key
 */

template <typename Mapped>
struct _nested_key {
  using type = std::tuple<>;
};

template <typename Key, typename Mapped>
struct _nested_key<std::map<Key, Mapped>> {
  using type = typename tuple::merge<std::tuple<Key>, typename _nested_key<Mapped>::type>::type;
};

template <typename MMap>
struct nested_key {
  using type = typename tuple::merge<std::tuple<typename MMap::key_type>, typename _nested_key<typename MMap::mapped_type>::type>::type;
};

/*
 * nested_mapped
 */

template <typename Mapped>
struct _nested_mapped {
  using type = Mapped;
};

template <typename Key, typename Mapped>
struct _nested_mapped<std::map<Key, Mapped>> {
  using type = typename _nested_mapped<Mapped>::type;
};

template <typename MMap>
struct nested_mapped {
  using type = typename _nested_mapped<typename MMap::mapped_type>::type;
};

/*
 * index
 */
template <typename Map, typename Keys>
constexpr typename nested_mapped<Map>::type& index(Map& map, const Keys& keys) {
  if constexpr (std::tuple_size<Keys>::value == 1) {
    return map.at(std::get<0>(keys));
  } else {
    return index(map.at(tuple::head(keys)), tuple::tail(keys));
  }
}

template <typename Map, typename Keys>
constexpr const typename nested_mapped<Map>::type& index(const Map& map, const Keys& keys) {
  if constexpr (std::tuple_size<Keys>::value == 1) {
    return map.at(std::get<0>(keys));
  } else {
    return index(map.at(tuple::head(keys)), tuple::tail(keys));
  }
}

/*
 * TransformedMap
 */
 
template <typename Map, typename Mapped>
struct TransformedMap {
 public:
  using key_type = typename Map::key_type;
  using mapped_type = Mapped;
 
  using iterator = typename Map::iterator;
  using const_iterator = typename Map::const_iterator;
 
  using Transform = std::function<mapped_type&(typename Map::mapped_type&)>;
 
 public:
  TransformedMap(Map& map, Transform transform)
    : m_map(map)
    , m_transform(transform) {}
 
  Mapped& operator[](const key_type& key) {
    return m_transform(m_map[key]);
  }
 
  const Mapped& operator[](const key_type& key) const {
    return m_transform(m_map[key]);
  }
 
 private:
  Map& m_map;
  Transform m_transform;
};
 
/*
 * FlattenMap
 */
 
template <typename Map>
struct FlattenMap {
 public:
  using key_type = typename nested_key<Map>::type;
  using mapped_type = typename nested_key<Map>::type;
 
  using iterator = typename Map::iterator;
  using const_iterator = typename Map::const_iterator;
 
 public:
  FlattenMap(Map& map)
    : m_map(map) {}
 
  mapped_type& operator[](const key_type& keys) {
    return index(m_map, keys);
  }
 
  const mapped_type& operator[](const key_type& keys) const {
    return index(m_map, keys);
  }
 
 private:
  Map& m_map;
};


