/*
 * Website:
 *      https://github.com/wo3kie/dojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++11 linear.regression.cpp -o linear.regression
 *
 * Usage:
 *      $ ./linear.regression
 */


#include <cassert>
#include <cmath>
#include <iostream>
#include <vector>

struct Point
{
    double x;
    double y;
};

bool linearRegression( 
    std::vector<Point> const & points,
    double & a,
    double & b
 ){
    if( points.empty() ){
        a = 0;
        b = 0;

        return false;
    }

    double sumXi = 0;
    double sumYi = 0;
    double sumX2i = 0;
    double sumXiYi = 0;

    for( Point const & p : points ){
        sumXi += p.x;
        sumYi += p.y;
        sumX2i += p.x * p.x;
        sumXiYi += p.x * p.y;
    }

    double const sumXi2 = sumXi * sumXi;
    double const n = points.size();
    double const denominator = n * sumX2i - sumXi2;

    if( fabs( denominator - 0.0000 ) < 0.00001 ){
        return false;
    }

    a =  ( n * sumXiYi - sumXi * sumYi ) / denominator;

    double const avgYi = sumYi / n;
    double const avgXi = sumXi / n;

    b = avgYi - a * avgXi;

    return true;
}

int main(){
    {
        double a;
        double b;
        std::vector<Point> const points{
            { 1, 10 },
            { 2, 20 },
            { 3, 20 },
            { 3, 25 },
            { 4, 30 }
        };

        assert( linearRegression( points, a, b ) );
        assert( fabs( a - 6.1539 ) < 0.0001 );
        assert( fabs( b - 5.0000 ) < 0.0001 );
    }

    {
        double a;
        double b;
        std::vector<Point> const points{
            { 1, 1 },
            { 2, 1 },
            { 3, 1 },
            { 4, 1 },
            { 5, 1 }
        };

        assert( linearRegression( points, a, b ) );
        assert( fabs( a - 0.0000 ) < 0.0001 );
        assert( fabs( b - 1.0000 ) < 0.0001 );
    }

    {
        double a;
        double b;
        std::vector<Point> const points{
            { 1, 1 },
            { 1, 2 },
            { 1, 3 },
            { 1, 4 },
            { 1, 5 }
        };

        assert( ! linearRegression( points, a, b ) );
    }
}

