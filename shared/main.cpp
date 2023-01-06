// g++ --std=c++11 -g3 -L. -lshared -ldl main.cpp -o main

#include "shared.h"

#include <dlfcn.h>
#include <stdexcept>
#include <string>

class SharedLibrary {
public:
  explicit SharedLibrary(std::string const& libraryName, int const options = RTLD_LAZY)
      : m_library(dlopen(libraryName.c_str(), options)) {
    if(m_library == nullptr) {
      throw std::runtime_error(dlerror());
    }
  }

  SharedLibrary(SharedLibrary const& other) = delete;

  SharedLibrary(SharedLibrary&& other)
      : m_library(other.m_library) {
    other.m_library = nullptr;
  }

  ~SharedLibrary() noexcept {
    dlclose(m_library);
  }

  SharedLibrary& operator=(SharedLibrary const& other) = delete;

  SharedLibrary& operator=(SharedLibrary&& other) noexcept {
    dlclose(m_library);

    m_library = other.m_library;
    other.m_library = nullptr;
  }

  void swap(SharedLibrary& other) noexcept {
    void* const temp = other.m_library;
    other.m_library = m_library;
    m_library = temp;
  }

  template<typename FunctionT>
  FunctionT* get(std::string const& functionName) const {
    FunctionT* result = nullptr;

    void* const symbol = dlsym(m_library, functionName.c_str());

    if(symbol == nullptr) {
      throw std::runtime_error(dlerror());
    }

    *(void**)(&result) = symbol;

    return result;
  }

private:
  void* m_library;
};

void test1() {
  void* library = dlopen("./libshared.so", RTLD_LAZY);
  void* symbol = dlsym(library, "helloWorld");

  /*
     * there is no cast between 
     * void * -> void (*)()
     */

  void (*function)() = 0;
  *(void**)(&function) = symbol;

  function();

  dlclose(library);
}

void test2() {
  SharedLibrary sl("./libshared.so");

  sl.get<void()>("helloWorld")();
}

int main() {
  test1();
  test2();
}
