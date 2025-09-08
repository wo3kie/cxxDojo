/*
 * Website:
 *      https://github.com/wo3kie/dojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++20 bloom.cpp -o bloom
 *
 * Usage:
 *      $ ./bloom
 */

#include <cassert>
#include <cmath>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

struct Bloom {
  enum { None = 0, Maybe = 1 };

  static unsigned optimalNumberOfHashFunctions(
      long i /* expected number of items */, long b /* number of bits */
  ) {
    using std::ceil;
    using std::log2;

    /*
         * https://en.wikipedia.org/wiki/Bloom_filter
         */

    return ceil((1.0 * b / i) * log(2));
  }

  static unsigned optimalNumberOfBits(
      int i /* expected number of items */, double pe /* expected probability of false positive */
  ) {
    using std::ceil;
    using std::log2;
    using std::pow;

    double const e = 2.71828;

    /*
         * https://en.wikipedia.org/wiki/Bloom_filter
         *
         * pe = (1-e^(-i/b))^k
         * k = b/i*ln(2)
         *
         * pe = (1-e^ln(2))^(b/i*ln(2))  /ln
         * ln(pe) = ln((1-e^ln(2))^(b/i*ln(2)))
         * ln(pe) = (b/i*ln(2))*ln(1-e^ln(2))
         * (b/i*ln(2) = ln(pe)/ln(1-e^ln(2))
         * b = i/ln(2)*ln(pe)/ln(1-e^ln(2))
         */

    return ceil(i / log(2) * log(pe) / log(1 - pow(e, -log(2))));
  }

  template<typename T>
  class Filter {
  public:
    typedef std::function<int(T const&)> HashFunction;

  public:
    Filter(unsigned numberOfBits = 1024)
        : m_bits(numberOfBits) {
    }

    ~Filter() = default;

    Filter(Filter const&) = default;
    Filter(Filter&&) = default;

    Filter& operator=(Filter const&) = default;
    Filter& operator=(Filter&&) = default;

    void addHash(HashFunction const& f) {
      m_filters.push_back(f);
    }

    template<typename Hash_>
    void addHash(Hash_&& f) {
      m_filters.emplace_back(std::forward<Hash_>(f));
    }

    void insert(T const& t) {
      for(HashFunction const& filter : m_filters) {
        unsigned const bit = filter(t) % m_bits.size();
        m_bits[bit] = true;
      }
    }

    int find(T const& t) const {
      for(HashFunction const& filter : m_filters) {
        unsigned const bit = filter(t) % m_bits.size();
        if(m_bits[bit] == false) {
          return None;
        }
      }

      return Maybe;
    }

    void clear() {
      m_bits.clear();
      m_filters.clear();
    }

    bool empty() const {
      return m_bits.empty() && m_filters.empty();
    }

    void swap(Filter& other) {
      std::swap(m_bits, other.m_bits);
      std::swap(m_filters, other.m_filters);
    }

  private:
    std::vector<bool> m_bits;
    std::vector<HashFunction> m_filters;
  };
};

int main() {
  Bloom::Filter<std::string> bloom(32);

  auto hash1 = [](std::string const& s) {
    int result = 0;

    for(char c : s) {
      result += c;
    }

    return result;
  };

  auto hash2 = [](std::string const& s) {
    int result = 0;

    for(unsigned i = 0; i < s.size(); ++i) {
      result += (i * s[i]);
    }

    return result;
  };

  auto hash3 = [](std::string const& s) {
    return std::hash<std::string>()(s);
  };

  bloom.addHash(hash1);
  bloom.addHash(hash2);
  bloom.addHash(hash3);

  bloom.insert("c++");
  bloom.insert("python");
  bloom.insert("haskell");

  assert(bloom.find("c++") == Bloom::Maybe);
  assert(bloom.find("python") == Bloom::Maybe);
  assert(bloom.find("haskell") == Bloom::Maybe);

  assert(bloom.find("java") == Bloom::None);
  assert(bloom.find("c#") == Bloom::None);
  assert(bloom.find("perl") == Bloom::None);

  assert(Bloom::optimalNumberOfBits(1e3, 0.01) == 9586 /* 1.2kB */);
  assert(Bloom::optimalNumberOfBits(1e3, 0.001) == 14378 /* 1.7kB */);
  assert(Bloom::optimalNumberOfBits(1e3, 0.0001) == 19171 /* 2.3kB */);

  assert(Bloom::optimalNumberOfHashFunctions(1e3, 9586) == 7);
  assert(Bloom::optimalNumberOfHashFunctions(1e3, 14378) == 10);
  assert(Bloom::optimalNumberOfHashFunctions(1e3, 19171) == 14);

  assert(Bloom::optimalNumberOfBits(1e6, 0.001) == 14377578 /* 1.7MB */);
  assert(Bloom::optimalNumberOfBits(1e6, 0.0001) == 19170104 /* 2.3MB */);
  assert(Bloom::optimalNumberOfBits(1e6, 0.00001) == 23962630 /* 2.9MB */);

  assert(Bloom::optimalNumberOfHashFunctions(1e6, 14377578) == 10);
  assert(Bloom::optimalNumberOfHashFunctions(1e6, 19170104) == 14);
  assert(Bloom::optimalNumberOfHashFunctions(1e6, 23962630) == 17);

  assert(Bloom::optimalNumberOfBits(1e9, 0.001) == 1492676007 /* 177MB */);
  assert(Bloom::optimalNumberOfBits(1e9, 0.0001) == 1990234676 /* 237MB */);
  assert(Bloom::optimalNumberOfBits(1e9, 0.00001) == 2487793345 /* 296MB */);

  assert(Bloom::optimalNumberOfHashFunctions(1e9, 1492676007) == 2);
  assert(Bloom::optimalNumberOfHashFunctions(1e9, 1990234676) == 2);
  assert(Bloom::optimalNumberOfHashFunctions(1e9, 2487793345) == 2);
}
