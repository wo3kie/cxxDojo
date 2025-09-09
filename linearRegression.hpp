/*
 * Website:
 *      https://github.com/wo3kie/cxxdojo
 *
 * Author:
 *      Lukasz Czerwinski
 */

#ifndef CXX_DOJO_LINEAR_REGRESSION
#define CXX_DOJO_LINEAR_REGRESSION

#include <cassert>
#include <vector>

#include "./feq.hpp"

struct Point {
  double x;
  double y;
};

inline bool linearRegression(std::vector<Point> const& points, double& a, double& b) {
  if(points.empty()) {
    return false;
  }

  double sumXi = 0;
  double sumYi = 0;
  double sumX2i = 0;
  double sumXiYi = 0;

  for(Point const& p : points) {
    sumXi += p.x;
    sumYi += p.y;
    sumX2i += p.x * p.x;
    sumXiYi += p.x * p.y;
  }

  double const sumXi2 = sumXi * sumXi;
  double const n = points.size();
  double const denominator = n * sumX2i - sumXi2;

  if(fabs(denominator - 0.0000) < 0.00001) {
    return false;
  }

  a = (n * sumXiYi - sumXi * sumYi) / denominator;

  double const avgYi = sumYi / n;
  double const avgXi = sumXi / n;

  b = avgYi - a * avgXi;

  return true;
}

/*
 https://www.khanacademy.org/math/statistics-probability/
     describing-relationships-quantitative-data/
    residuals-least-squares-rsquared/v/
    proof-part-4-minimizing-squared-error-to-regression-line

 SE = (y1 - (a*x1+b))^2 + (y2-a*x2+b))^2 + ... + (yn - (a*xn+b))^2
     																		=>
 y1^2 - 2*y1 * (a*x1+b) + (a*x1+b)^2 +
 y2^2 - 2*y2 * (a*x2+b) + (a*x2+b)^2 +
 ... +
 yn^2 - 2*yn * (a*xn+b) + (a*xn+b)^2
     																		=>
  A   | B         | C      | D        | E        | F
 y1^2 - 2*y1*a*x1 - 2*y1*b + a^2*x1^2 + 2*a*x1*b + b^2
 y2^2 - 2*y2*a*x2 - 2*y2*b + a^2*x2^2 + 2*a*x2*b + b^2
 ... +
 yn^2 - 2*yn*a*xn - 2*yn*b + a^2*xn^2 + 2*a*xn*b + b^2
     																		=>
 A) (y1^2 + y2^2 + ... yn^2) +
 B) -2*a * (x1*y1 + x2*y2 + ... + xn*yn) +
 C) -2*b * (y1 + y2 + ... + yn) +
 D) a^2 * (x1^2 + x2^2 + ... + nx^2) +
 E) 2*a*b * (x1 + x2 + ... + xn) +
 F) n*b^2
     																		=>
 y2Mean = (y1^2 + y2^2 + ... + yn^2)/n
 xyMean = (x1*y1 + x2*y2 + ... + xn*yn)/n
 x2Mean = (x1^2 + x2^2 + ... + xn^2)/n
     																		=>
 A) (n*y2Mean) +
 B) -2*a*(n*xyMean) +
 C) -2*b*(n*yMean) +
 D) a^2*(n*x2Mean) +
 E) 2*a*b*(n*xMean) +
 F) n*b^2
     																		=>
 Minimum: dSE/da = 0, dSE/db = 0
     																		=>
 dSE/da = -2*n*xyMean + 2*n*x2Mean * a+2*b*n*xMean = 0
 dSF/db = -2*n*yMean + 2*a*n*xMean + 2*b*n = 0
     																		=>
 dSE/da = -xyMean + a*x2Mean + b*xMean = 0
 dSF/db = -yMean + a*xMean + b = 0
     																		=>
 a*x2Mean + b*xMean = xyMean
 a*xMean + b = yMean
     																		=>
 a = (xMean * yMean - xyMean) / (xMean^2 - x2Mean)
 b = yMean - a*xMean
*/

inline bool linearRegression2(std::vector<Point> const& points, double& a, double& b) {
  if(points.empty()) {
    return false;
  }

  double xMean = 0;
  double yMean = 0;
  double xyMean = 0;
  double x2Mean = 0;
  unsigned const n = points.size();

  for(Point const& p : points) {
    xMean += p.x;
    yMean += p.y;
    xyMean += p.x * p.y;
    x2Mean += p.x * p.x;
  }

  xMean /= n;
  yMean /= n;
  xyMean /= n;
  x2Mean /= n;

  double const denominator = xMean * xMean - x2Mean;

  if(fabs(denominator - 0.0000) < 0.00001) {
    return false;
  }

  a = (xMean * yMean - xyMean) / denominator;
  b = yMean - a * xMean;

  return true;
}

#endif
