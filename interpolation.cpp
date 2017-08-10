/*
 * Website:
 *      https://github.com/wo3kie/dojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++11 interpolation.cpp -o interpolation
 *
 * Usage:
 *      $ ./interpolation
 */

#include <map>
#include <vector>

struct Point {
    double x_;
    double y_;
};

std::pair<std::vector<double> /* xs */, std::vector<double> /* coefficients */>
newtonDividedDifference(std::vector<Point> const & points){
    unsigned const size = points.size();

    std::vector<double> xs(size, 0);
    std::vector<double> cs(size, 0);
    std::map<unsigned, std::map<unsigned, double>> vs;

    for(unsigned j = 0; j < size; ++j){
        vs[j][0] = points[j].y_;
    }

    for(unsigned i = 1; i < size; ++i){
        for(unsigned j = 0; j < size - i; ++j){
            double const y2 = vs[j+1][i-1];
            double const y1 = vs[j][i-1];
            double const x2 = points[j+i].x_;
            double const x1 = points[j].x_;

            vs[j][i] = (y2 - y1) / (x2 - x1);
        }
    }

    for(unsigned i = 0; i < size; ++i){
        xs[i] = points[i].x_;
        cs[i] = vs[0][i];
    }

    return std::make_pair(xs, cs);
}

double newtonDividedDifferencePolynominal(
    std::pair<
        std::vector<double> /* xs */,
        std::vector<double> /* cs */
    > xs_cs,
    double x
){
    double result = 0;

    for(unsigned i = 0; i < xs_cs.second.size(); ++i){
        double factor = 1;
        
        for(unsigned j = 0; j < i; ++j){
            factor *= (x - xs_cs.first[j]);
        }

        result += xs_cs.second[i] * factor;
    }

    return result;
}

#include <cassert>

int main(){
    {
        std::vector<Point> points({{0, 1}, {2, 2}, {3, 4}});

        std::pair<std::vector<double>, std::vector<double>> const xs_cs
            = newtonDividedDifference(points);

        std::pair<std::vector<double>, std::vector<double>> const expected
            = {{0, 2, 3}, {1, 0.5, 0.5}};

        assert(xs_cs == expected);

        for(Point const & point : points){
            assert(newtonDividedDifferencePolynominal(xs_cs, point.x_) == point.y_);
        }
    }

    {
        std::vector<Point> points({{-1, -5}, {0, -1}, {2, 1}, {3, 11}});

        std::pair<std::vector<double>, std::vector<double>> const xs_cs
            = newtonDividedDifference(points);

        std::pair<std::vector<double>, std::vector<double>> const expected
            = {{-1, 0, 2, 3}, {-5, 4, -1, 1}};

        assert(xs_cs == expected);

        for(Point const & point : points){
            assert(newtonDividedDifferencePolynominal(xs_cs, point.x_) == point.y_);
        }
    }
}
