/*
 * Website:
 *      https://github.com/wo3kie/dojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++11 page_rank.cpp -o page_rank -lgsl -lgslcblas -lm
 *
 * Usage:
 *      $ ./page_rank
 */

/*
 * Algorithm from the book "Markowe wykłady z matematyki, algebra z geometrią", Marek Zakrzewski, page 173
 */

#include <complex>
#include <tuple>
#include <vector>

#include <gsl/gsl_eigen.h>
#include <gsl/gsl_math.h>

/*
 * Let's describe links between pages as a matrix "A"
 *
 *      [0 1 1 1 1]
 *      [0 0 1 1 1]
 *  A = [0 0 0 1 1]
 *      [0 0 1 0 1]
 *      [1 0 0 0 0]
 *
 *  and define "i"'s page ranking "r(i)" as proportional
 *  to rankings of all pages pointing to the "i" page
 *  multiply by some attractiveness coefficient "a"
 *
 *  r1 = a(r2 + r3 + r4 + r5)
 *  r2 = a(r3 + r4 + r5)
 *  r3 = a(r3 + r4)
 *  r4 = a(r3 + r5)
 *  r5 = a(r1)
 *
 *  where a is unknown ring rage coefficient
 *
 *  [r1]     [0 1 1 1 1] [r1]
 *  [r2]     [0 0 1 1 1] [r2]
 *  [r3] = a [0 0 0 1 1] [r3]
 *  [r4]     [0 0 1 0 1] [r4]
 *  [r5]     [1 0 0 0 0] [r5]
 *
 *  so, r = aMr, Mr = (1/a)r, r is a eigenvector, (1/a) is eigenvalue
 */

std::vector<std::tuple<std::complex<double>, std::vector<std::complex<double>>>>
eigen(double* const data, unsigned rows, unsigned columns) {
  std::vector<std::tuple<std::complex<double>, std::vector<std::complex<double>>>> result;

  gsl_matrix_view matrix = gsl_matrix_view_array(data, rows, columns);
  gsl_vector_complex* const values = gsl_vector_complex_alloc(columns);
  gsl_matrix_complex* const vectors = gsl_matrix_complex_alloc(rows, columns);
  gsl_eigen_nonsymmv_workspace* const w = gsl_eigen_nonsymmv_alloc(rows);

  gsl_eigen_nonsymmv(&matrix.matrix, values, vectors, w);
  gsl_eigen_nonsymmv_free(w);
  gsl_eigen_nonsymmv_sort(values, vectors, GSL_EIGEN_SORT_ABS_DESC);

  for(int i = 0; i < columns; ++i) {
    std::vector<std::complex<double>> vector;
    gsl_vector_complex_view _view = gsl_matrix_complex_column(vectors, i);

    for(int j = 0; j < rows; ++j) {
      gsl_complex _value = gsl_vector_complex_get(&_view.vector, j);
      vector.push_back(std::complex<double>(GSL_REAL(_value), GSL_IMAG(_value)));
    }

    gsl_complex _value = gsl_vector_complex_get(values, i);
    std::complex<double> value(GSL_REAL(_value), GSL_IMAG(_value));
    result.push_back(std::make_tuple(value, vector));
  }

  gsl_vector_complex_free(values);
  gsl_matrix_complex_free(vectors);

  return result;
}

#include <iostream>

int getSign(double d) {
  if(d > 0) {
    return 1;
  } else if(d < 0) {
    return -1;
  } else {
    return 0;
  }
}

bool makePerronEigenvector(std::vector<std::complex<double>>& vector) {
  int sign = 0;

  for(auto const& complex : vector) {
    if(complex.imag() != 0) {
      return false;
    }

    if(sign == 0) {
      sign = getSign(complex.real());
    } else if(sign == 1 && getSign(complex.real()) == -1) {
      return false;
    } else if(sign == -1 && getSign(complex.real()) == 1) {
      return false;
    }
  }

  if(sign == -1) {
    for(auto& complex : vector) {
      complex.real(-complex.real());
    }
  }

  double sum = 0;

  for(auto& complex : vector) {
    sum += complex.real();
  }

  if(sum == 0) {
    return false;
  }

  for(auto& complex : vector) {
    complex.real(complex.real() / sum);
  }

  return true;
}

int main() {

  /*
     * website -points to-> websites
     *
     * 0 ->         4
     * 1 -> 0
     * 2 -> 0 1   3
     * 3 -> 0 1 2
     * 4 -> 0 1 2 3
     */

  double data[] = {
      //  0  1  2  3  4
      0, 1, 1, 1, 1, // 0
      0, 0, 1, 1, 1, // 1
      0, 0, 0, 1, 1, // 2
      0, 0, 1, 0, 1, // 3
      1, 0, 0, 0, 0  // 4
  };

  auto eigen_values_vectors = eigen(data, 5, 5);

  for(auto& eigen_value_vector : eigen_values_vectors) {
    std::complex<double>& value = std::get<0>(eigen_value_vector);
    std::vector<std::complex<double>>& vector = std::get<1>(eigen_value_vector);

    if(value.imag() != 0) {
      continue;
    }

    if(makePerronEigenvector(vector) == false) {
      continue;
    }

    for(unsigned i = 0; i < vector.size(); ++i) {
      std::cout << "Site (" << i << ") has rank: " << vector[i].real() << std::endl;
    }
  }

  return 0;
}
