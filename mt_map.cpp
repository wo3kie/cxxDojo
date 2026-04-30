/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cpp-dojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 */

#include "./mt_map.hpp"
#include "./timer.hpp"

#include <iostream>
#include <thread>
#include <vector>

template<typename TBucketPolicy, typename TMutexPolicy = MutexPolicy>
void mt_map_test() {
  auto make_key = [](int thread_id, int i) -> std::string {
    const char prefix = static_cast<char>('A' + (thread_id % 26));
    return std::string{prefix} + std::to_string(i);
  };

  constexpr int tasks = 8;
  constexpr int iterations = 10'000;

  MTMap<int, TBucketPolicy, TMutexPolicy> map;
  std::vector<std::thread> threads;

  {
    for(int t = 0; t < tasks; ++t) {
      threads.emplace_back([t, &map, &make_key]() {
        for(int i = 0; i < iterations; ++i) {
          const std::string key = make_key(t, i);
          map.insert(key, i);
        }
      });
    }

    for(auto& th : threads) {
      th.join();
    }

    threads.clear();
  }

  assert(map.size() == (tasks * iterations));

  {
    for(int t = 0; t < tasks; ++t) {
      threads.emplace_back([t, &map, &make_key]() {
        for(int i = 0; i < iterations; ++i) {
          const std::string key = make_key(t, i);
          map.update(key, 10 * i);
        }
      });
    }

    for(auto& th : threads) {
      th.join();
    }

    threads.clear();
  }

  assert(map.size() == (tasks * iterations));

  {
    for(int t = 0; t < tasks; ++t) {
      for(int i = 0; i < iterations; ++i) {
        const std::string key = make_key(t, i);
        const std::optional<int> val = map.get(key);
        assert(val.has_value());
        assert(*val == i * 10);
      }
    }

    for(auto& th : threads) {
      th.join();
    }

    threads.clear();
  }

  assert(map.size() == (tasks * iterations));

  {
    for(int t = 0; t < tasks; ++t) {
      for(int i = 0; i < iterations; ++i) {
        const std::string key = make_key(t, i);
        assert(map.erase(key) == 1);
      }
    }

    for(auto& th : threads) {
      th.join();
    }

    threads.clear();
  }

  assert(map.size() == 0);
}

int main() {
  timer([]() -> void { mt_map_test<OneBucketPolicy>(); }).log([](long int /* ns */, const std::string& fmt) {
    std::cout << "OneBucketPolicy: " << fmt << std::endl;
  });

  timer([]() -> void { mt_map_test<AZBucketPolicy>(); }).log([](long int /* ns */, const std::string& fmt) {
    std::cout << "AZBucketPolicy: " << fmt << std::endl;
  });

  timer([]() -> void { mt_map_test<AZBucketPolicy, NoMutexPolicy>(); }).log([](long int /* ns */, const std::string& fmt) {
    std::cout << "AZBucketPolicy/NoMutexPolicy: " << fmt << std::endl;
  });
}
