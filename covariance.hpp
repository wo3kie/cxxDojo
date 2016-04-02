/*
 * Website:
 *      https://github.com/wo3kie/dojo
 *
 * Author:
 *      Lukasz Czerwinski
 */

#ifndef CXX_DOJO_COVARIANCE_HPP
#define CXX_DOJO_COVARIANCE_HPP

#include <vector>

#include "./mean.hpp"

template<typename Iterator1, typename Iterator2>
double covariance(
    Iterator1 xBegin, Iterator1 const xEnd,
    Iterator2 yBegin, Iterator2 const yEnd
){
    unsigned counter = 0;
    double totalSum = 0;
    double const xMean = mean(xBegin, xEnd);
    double const yMean = mean(yBegin, yEnd);

    for( ; xBegin != xEnd; ++xBegin, ++yBegin){
        counter += 1;
        totalSum += (*xBegin - xMean) * (*yBegin - yMean);
    }

    return (1.0 / (counter - 1)) * totalSum;
}

template<typename T>
double covariance(
    std::vector<T> const & xs,
    std::vector<T> const & ys
){
    return covariance(
        xs.begin(), xs.end(),
        ys.begin(), ys.end()
    );
}

#endif
