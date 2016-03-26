/*
 * Website:
 *      https://github.com/wo3kie/dojo
 *
 * Author:
 *      Lukasz Czerwinski
 */

#ifndef CXX_DOJO_VARIANCE_HPP
#define CXX_DOJO_VARIANCE_HPP

#include <vector>

#include "./mean.hpp"

template<typename Iterator>
double variance(Iterator begin, Iterator const end){
    double meanValue = mean(begin, end);
    double totalSum = 0;
    unsigned counter = 0;

    for( ; begin != end; ++begin){
        double const meanValueDiff = meanValue - *begin;
        totalSum += meanValueDiff * meanValueDiff;
        counter += 1;
    }

    return totalSum / (counter - 1);
}

template<typename T>
double variance(std::vector<T> const & array){
    return variance(array.begin(), array.end());
}

#endif
