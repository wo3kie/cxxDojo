#pragma once

/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cpp-dojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 */

#include <array>
#include <cassert>
#include <mutex>
#include <optional>
#include <stdexcept>
#include <shared_mutex>
#include <string>
#include <unordered_map>

/*
 * +-----+ -> +-------+-----------------------------+  
 * |  A  | -> | mutex | {["ALICE", 1], ["ALAN", 2]} | 
 * +-----+ -> +-------+-----------------------------+  
 * |  B  | -> | mutex | {["BOB", 3]}                | 
 * +-----+ -> +-------+-----------------------------+  
 * |  C  | -> | mutex | {}                          | 
 * +-----+ -> +-------+-----------------------------+  
 *   ...       
 * +-----+ -> +-------+-----------------------------+  
 * |  Z  | -> | mutex | {["ZACHARY", 99]}           | 
 * +-----+ -> +-------+-----------------------------+  
 */

/*
 * BucketPolicy
 */

struct OneBucketPolicy {
  constexpr static size_t SIZE = 1;

  static size_t get(const std::string&) {
    return 0;
  }
};

struct AZBucketPolicy {
  constexpr static size_t SIZE = ('Z' - 'A' + 1);

  static size_t get(const std::string& key) {
    assert(!key.empty());
    assert(std::isupper(key[0]));

    if(key[0] >= 'A' && key[0] <= 'Z') {
      return key[0] - 'A';
    } else {
      assert(false);
    }
  }
};

/*
 * MutexPolicy
 */

struct NoMutexPolicy {
  using MutexType = void*;
  using ReadLockType = void*;
  using WriteLockType = void*;

  NoMutexPolicy(void*) {
  }
};

struct MutexPolicy {
  using MutexType = std::mutex;
  using ReadLockType = std::lock_guard<std::mutex>;
  using WriteLockType = std::lock_guard<std::mutex>;
};

struct SharedMutexPolicy {
  using MutexType = std::shared_mutex;
  using ReadLockType = std::shared_lock<std::shared_mutex>;
  using WriteLockType = std::unique_lock<std::shared_mutex>;
};

/*
 * MTMap (Multi-Threaded Map)
 */

template<typename V, typename TBucketPolicy = AZBucketPolicy, typename TMutexPolicy = MutexPolicy>
struct MTMap {
private:
  using KeyType = std::string;
  using ValueType = V;
  using MapType = std::unordered_map<KeyType, ValueType>;

  using MutexType = typename TMutexPolicy::MutexType;
  using ReadLockType = typename TMutexPolicy::ReadLockType;
  using WriteLockType = typename TMutexPolicy::WriteLockType;

private:
  struct Bucket {
    MutexType mtx;
    MapType map;
  };

  std::array<Bucket, TBucketPolicy::SIZE> buckets;

public:
  using key_type = KeyType;
  using value_type = ValueType;

public:
  MTMap() = default;
  MTMap(const MTMap&) = delete;
  MTMap(MTMap&&) = delete;

  ~MTMap() = default;

  MTMap& operator=(MTMap&&) = delete;
  MTMap& operator=(const MTMap&) = delete;

public:
  bool insert(const KeyType& key, const ValueType& value) {
    Bucket& bucket = buckets[_index(key)];
    MutexType& mtx = bucket.mtx;
    MapType& map = bucket.map;
    
    WriteLockType lock(mtx);
    return _insert(map, key, value);
  }

  bool update(const KeyType& key, const ValueType& value) {
    Bucket& bucket = buckets[_index(key)];
    MutexType& mtx = bucket.mtx;
    MapType& map = bucket.map;
    
    WriteLockType lock(mtx);
    return _update(map, key, value);
  }

  size_t erase(const KeyType& key) {
    Bucket& bucket = buckets[_index(key)];
    MutexType& mtx = bucket.mtx;
    MapType& map = bucket.map;
    
    WriteLockType lock(mtx);
    return _erase(map, key);
  }

  std::optional<ValueType> get(const KeyType& key) {
    Bucket& bucket = buckets[_index(key)];
    MutexType& mtx = bucket.mtx;
    MapType& map = bucket.map;
    
    ReadLockType lock(mtx);
    return _get(map, key);
  }

  size_t size() {
    size_t total_size = 0;

    for(Bucket& bucket : buckets) {
      MutexType& mtx = bucket.mtx;
      MapType& map = bucket.map;

      ReadLockType lock(mtx);
      total_size += _size(map);
    }

    return total_size;
  }

private:
  static size_t _index(const KeyType& key) {
    return TBucketPolicy::get(key);
  }

  static bool _insert(MapType& map, const KeyType& key, const ValueType& value) {
    return map.insert({key, value}).second;
  }

  static size_t _erase(MapType& map, const KeyType& key) {
    return map.erase(key);
  }

  static bool _update(MapType& map, const KeyType& key, const ValueType& value) {
    auto it = map.find(key);

    if(it == map.end()) {
      return false;
    } else {
      it->second = value;
      return true;
    }
  }

  static std::optional<ValueType> _get(MapType& map, const KeyType& key) {
    auto it = map.find(key);

    if(it == map.end()) {
      return std::nullopt;
    } else {
      return {it->second};
    }
  }

  static size_t _size(MapType& map) {
    return map.size();
  }
};
