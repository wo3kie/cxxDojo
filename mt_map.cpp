/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cxxdojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 *
 * Usage:
 *      $ ./build/bin/mt_map
 */

#include "./mt_map.hpp"

#include <thread>
#include <vector>

void mt_map_test() {
  auto make_key = [](int thread_id, int i) -> std::string {
    const char prefix = static_cast<char>('A' + (thread_id % 26));
    return std::string{prefix} + std::to_string(i);
  };

  constexpr int writer_threads = 7;
  constexpr int reader_threads = 1;
  constexpr int iterations = 1000;

  MTMap<int> map;
  std::vector<std::thread> threads;

  for(int t = 0; t < writer_threads; ++t) {
    threads.emplace_back([t, &map, &make_key]() {
      for(int i = 0; i < iterations; ++i) {
        const std::string key = make_key(t, i);
        map.insert(key, i);
        const bool updated = map.update(key, i * 10);
        assert(updated);
      }
    });
  }

  threads.emplace_back([&map, &make_key]() {
    for(int i = 0; i < iterations; ++i) {
      for(int t = 0; t < writer_threads; ++t) {
        const std::string key = make_key(t, i);
        const std::optional<int> val = map.get(key);

        if(val.has_value()) {
          assert((*val % 10) == 0);
        }
      }

      std::this_thread::sleep_for(std::chrono::microseconds(10));
    }
  });

  for(auto& th : threads) {
    th.join();
  }

  for(int t = 0; t < writer_threads; ++t) {
    for(int i = 0; i < iterations; ++i) {
      const std::string key = make_key(t, i);
      const std::optional<int> val = map.get(key);
      assert(val.has_value());
      assert(*val == i * 10);
    }
  }
}

#include <iostream>

int main() {
  mt_map_test();
  std::cout << "Ok" << std::endl;
}
