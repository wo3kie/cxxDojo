/*
 * Website:
 *      https://github.com/wo3kie/dojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++11 qr.cpp -o qr
 *
 * Usage:
 *      $ ./qr
 */

#include <cmath>
#include <vector>

#include "./feq.hpp"
#include "./gramSchmidt.hpp"
#include "./matrix.hpp"

void qr(Matrix const& a, Matrix& q, Matrix& r) {
  q = gramSchmidt(a);
  r = transpose(q) * a;
}

int main() {
  {
    Matrix q;
    Matrix r;
    Matrix a = {{1, 1, 2}, {1, 1, 0}, {1, 0, 0}};

    qr(a, q, r);

    assert(q * r == a);
  }

  {
    Matrix q;
    Matrix r;
    Matrix a = {{12, -51, 4}, {6, 167, -68}, {-4, 24, -41}};

    qr(a, q, r);

    assert(q * r == a);
  }

  return 0;
}
