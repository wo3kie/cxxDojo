/*
 * Website:
 *      https://github.com/wo3kie/dojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++11 entropy.cpp -o entropy
 *
 * Usage:
 *      $ ./entropy
 */

/*
 * From Wikipedia, https://en.wikipedia.org/wiki/Entropy_(information_theory)
 */

#include <cmath>
#include <iterator>
#include <map>

template<typename Iterator>
double entropy(Iterator const begin, Iterator const end){
    typedef typename std::iterator_traits<Iterator>::value_type value_type;

    unsigned totalCount = 0;
    std::map<value_type, unsigned> histogram;

    for(Iterator current = begin; current != end; ++current){
        histogram[*current] += 1;
        totalCount += 1;
    }

    double entropy;

    for(auto const & pair: histogram){
        entropy -= (1.0 * pair.second / totalCount) * log2(1.0 * pair.second / totalCount);
    }

    return entropy;
}

#include <cassert>
#include <iostream>
#include <vector>

#include "./feq.hpp"

void entropy_test(){
    {
        std::vector<int> array({1, 2});
        assert(entropy(array.begin(), array.end()) == 1);
    }
    {
        std::vector<int> array({1, 2, 2, 2});
        assert(feq(entropy(array.begin(), array.end()), 0.811278));
    }
    {
        std::vector<int> array({1, 1, 1, 1, 1});
        assert(feq(entropy(array.begin(), array.end()), 0));
    }
}

int main(){
    entropy_test();
}

