/*
 * Website:
 *      https://github.com/wo3kie/dojo
 *
 * Author:
 *      Lukasz Czerwinski
 */

#ifndef CXX_DOJO_MAP_UTILS
#define CXX_DOJO_MAP_UTILS

#include <map>
#include <type_traits>
#include <vector>

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

#endif
