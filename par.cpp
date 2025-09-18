/*
 * Website:
 *      https://github.com/wo3kie/cxxdojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++20 par.cpp -o par -pthread
 *
 * Usage:
 *      $ echo {1..10} > 1-10-file
 *      $ sed -i 's/ /\n/g' 1-10-file
 *      $
 *      $ cat 1-10-file | ./par echo
 *      140556950165248: 1
 *      140556941772544: 2
 *      140556950165248: 3
 *      140556941772544: 4
 *      140556950165248: 5
 *      140556941772544: 6
 *      140556950165248: 7
 *      140556941772544: 8
 *      140556941772544: 10
 *      140556950165248: 9
 *
 *  GNU parallel:
 *      http://www.gnu.org/software/parallel/
 */

#include <chrono>
#include <functional>
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>

/*
 * Buffer
 */

template<typename T>
class Buffer {
public:
  void push(const T& t) {
    std::unique_lock<std::mutex> lock(m_mutex);
    m_queue.push(t);
  }

  bool get(T& result) {
    std::unique_lock<std::mutex> lock(m_mutex);

    if(m_queue.empty()) {
      return false;
    }

    result = m_queue.front();
    m_queue.pop();

    return true;
  }

private:
  std::mutex m_mutex;
  std::queue<T> m_queue;
};

/*
 * exec
 */

bool exec(const char* const command, const std::function<void(const char*)> onRead) {
  FILE* const pipe = popen(command, "r");

  if(! pipe) {
    return false;
  }

  char buffer[4 * 1024];

  while(! feof(pipe)) {
    if(fgets(buffer, sizeof(buffer), pipe)) {
      onRead(buffer);
    }
  }

  pclose(pipe);

  return true;
}

/*
 * producer
 */

void producer(Buffer<std::string>& buffer) {
  std::string line;

  while(std::getline(std::cin, line)) {
    buffer.push(line);
  }
}

/*
 * consumer
 */

void consumer(const std::string& command, Buffer<std::string>& buffer) {
  const auto print = [](const std::string& text) {
    std::cout << std::this_thread::get_id() << ": " << text;
  };

  std::string args;

  while(true) {
    if(buffer.get(args) == false) {
      std::this_thread::sleep_for(std::chrono::milliseconds(100));

      if(buffer.get(args) == false) {
        return;
      }
    }

    exec((command + args).c_str(), print);
  }
}

/*
 * main
 */

int main(int argc, char* argv[]) {
  std::string command;

  for(unsigned i = 1; i < argc; ++i) {
    command += std::string(argv[i]) + " ";
  }

  Buffer<std::string> buffer;
  std::vector<std::thread> threads;

  threads.push_back(std::thread(&producer, std::ref(buffer)));

  const unsigned cores = std::thread::hardware_concurrency();

  for(unsigned i = 0; i < 2 * cores; ++i) {
    threads.push_back(std::thread(&consumer, command, std::ref(buffer)));
  }

  for(std::thread& t : threads) {
    t.join();
  }

  return 0;
}
