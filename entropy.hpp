/*
 * Website:
 *      https://github.com/wo3kie/cxxdojo
 *
 * Author:
 *      Lukasz Czerwinski
 */


#include <cmath>
#include <iterator>
#include <map>

template<typename Iterator>
double entropy(Iterator const begin, Iterator const end) {
  typedef typename std::iterator_traits<Iterator>::value_type value_type;

  double entropy = 0.0;
  unsigned totalCount = 0;

  std::map<value_type, unsigned> histogram;

  for(Iterator current = begin; current != end; ++current) {
    histogram[*current] += 1;
    totalCount += 1;
  }

  for(auto const& pair : histogram) {
    entropy -= (1.0 * pair.second / totalCount) * log2(1.0 * pair.second / totalCount);
  }

  return entropy;
}

