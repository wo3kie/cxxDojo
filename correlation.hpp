/*
 * Website:
 *      https://github.com/wo3kie/dojo
 *
 * Author:
 *      Lukasz Czerwinski
 */

#ifndef CXX_DOJO_CORRELATION_HPP
#define CXX_DOJO_CORRELATION_HPP

#include <cmath>
#include <vector>

#include "./standardDeviation.hpp"

template<typename Iterator1, typename Iterator2>
double correlation(
    Iterator1 xBegin, Iterator1 const xEnd,
    Iterator2 yBegin, Iterator2 const yEnd
){
    unsigned counter = 0;
    double totalSum = 0;
    double const xMean = mean(xBegin, xEnd);
    double const yMean = mean(yBegin, yEnd);
    double const xStdDev = stdDev(xBegin, xEnd);
    double const yStdDev = stdDev(yBegin, yEnd);

    for( ; xBegin != xEnd; ++xBegin, ++yBegin){
        counter += 1;
        totalSum += (*xBegin - xMean) * (*yBegin - yMean);
    }

    return (1.0 / (counter - 1)) * totalSum / (xStdDev * yStdDev);
}

template<typename T>
double correlation(
    std::vector<T> const & xs,
    std::vector<T> const & ys
){
    return correlation(
        xs.begin(), xs.end(),
        ys.begin(), ys.end()
    );
}

#endif
