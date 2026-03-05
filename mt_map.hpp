#pragma once

/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cxxdojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 */

#include <cassert>
#include <mutex>
#include <optional>
#include <stdexcept>
#include <string>
#include <unordered_map>

/*
 * BucketPolicy
 */

struct BucketPolicy {
  constexpr static size_t SIZE = ('Z' - 'A' + 1) + ('9' - '0' + 1);

  constexpr static size_t get(const char key) {
    assert(std::isupper(key) || std::isdigit(key));

    if(key >= 'A' && key <= 'Z') {
      return key - 'A';
    } else if(key >= '0' && key <= '9') {
      return ('Z' - 'A' + 1) + (key - '0');
    } else {
      assert(false);
    }
  }
};

/*
 * MTMap (Multi-Threaded Map)
 */

template<typename V, typename B = BucketPolicy>
struct MTMap {
private:
  using TKey = std::string;
  using TValue = V;
  using TBucketPolicy = B;
  using TMap = std::unordered_map<TKey, TValue>;

private:
  struct Bucket {
    std::mutex mtx;
    TMap map;
  };

  Bucket buckets[TBucketPolicy::SIZE];

public:
  using key_type = TKey;
  using mapped_type = TValue;
  using value_type = std::pair<const TKey, TValue>;

public:
  MTMap() = default;
  MTMap(const MTMap&) = delete;
  MTMap(MTMap&&) = delete;

  ~MTMap() = default;

  MTMap& operator=(MTMap&&) = delete;
  MTMap& operator=(const MTMap&) = delete;

public:
  bool insert(const TKey& key, const TValue& value) {
    assert(key.size() > 0);

    const size_t bucket_index = TBucketPolicy::get(key[0]);
    std::lock_guard<std::mutex> lock(buckets[bucket_index].mtx);
    auto& bucket_map = buckets[bucket_index].map;

    return _insert(bucket_map, key, value);
  }

  size_t erase(const TKey& key) {
    const size_t bucket_index = TBucketPolicy::get(key[0]);
    std::lock_guard<std::mutex> lock(buckets[bucket_index].mtx);
    auto& bucket_map = buckets[bucket_index].map;

    return _erase(bucket_map, key);
  }

  std::optional<TValue> get(const TKey& key) {
    const size_t bucket_index = TBucketPolicy::get(key[0]);
    std::lock_guard<std::mutex> lock(buckets[bucket_index].mtx);
    auto& bucket_map = buckets[bucket_index].map;

    return _get(bucket_map, key);
  }

  bool update(const TKey& key, const TValue& value) {
    const size_t bucket_index = TBucketPolicy::get(key[0]);
    std::lock_guard<std::mutex> lock(buckets[bucket_index].mtx);
    auto& bucket_map = buckets[bucket_index].map;

    return _update(bucket_map, key, value);
  }

private:
  static bool _insert(TMap& map, const TKey& key, const TValue& value) {
    return map.insert({key, value}).second;
  }

  static size_t _erase(TMap& map, const TKey& key) {
    return map.erase(key);
  }

  static std::optional<TValue> _get(TMap& map, const TKey& key) {
    auto it = map.find(key);

    if(it == map.end()) {
      return std::nullopt;
    } else {
      return {it->second};
    }
  }

  static bool _update(TMap& map, const TKey& key, const TValue& value) {
    auto it = map.find(key);

    if(it == map.end()) {
      return false;
    } else {
      it->second = value;
      return true;
    }
  }
};