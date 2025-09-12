#pragma once

/*
 * Website:
 *      https://github.com/wo3kie/cxxdojo
 *
 * Author:
 *      Lukasz Czerwinski
 */

#include <cassert>
#include <cmath>
#include <functional>
#include <vector>

enum { None = 0, Maybe = 1 };

/*
 * optimalNumberOfHashFunctions
 */

inline unsigned optimalNumberOfHashFunctions(long items, long bits) {
  using std::ceil;
  using std::log2;

 /*
  * https://en.wikipedia.org/wiki/Bloom_filter
  */

  return ceil((1.0 * bits / items) * log(2));
}

/*
 * optimalNumberOfBits
 */

inline unsigned optimalNumberOfBits(int items, double probFalsePositive) {
  using std::ceil;
  using std::log2;
  using std::pow;

  const double e = 2.71828;

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

  return ceil(items / log(2.0) * log(probFalsePositive) / log(1.0 - pow(e, -log(2.0))));
}

/*
 * BloomFilter
 */

template<typename T>
class BloomFilter {
public:
  typedef std::function<size_t(const T&)> HashFunction;

public:
  BloomFilter(size_t numberOfBits = 1024)
      : m_bits(numberOfBits) {
  }

  ~BloomFilter() = default;

  BloomFilter(const BloomFilter&) = delete;
  BloomFilter(BloomFilter&&) = default;

  BloomFilter& operator=(const BloomFilter&) = delete;
  BloomFilter& operator=(BloomFilter&&) = default;

  void addHash(const HashFunction& h) {
    m_filters.push_back(h);
  }

  template<typename F>
  void addHash(F&& f) {
    m_filters.emplace_back(std::forward<F>(f));
  }

  void insert(const T& t) {
    for(const HashFunction& filter : m_filters) {
      const size_t bit = filter(t) % m_bits.size();
      m_bits[bit] = true;
    }
  }

  int find(const T& t) const {
    for(const HashFunction& filter : m_filters) {
      const size_t bit = filter(t) % m_bits.size();
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

private:
  std::vector<bool> m_bits;
  std::vector<HashFunction> m_filters;
};
