/*
 * Website:
 *      https://github.com/wo3kie/cxxdojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++20 matrix.mul.perf.cpp -o matrix.mul.perf
 *
 * Usage:
 *      $ ./matrix.mul.perf
 *      nmp: 743355µs
 *      npm: 1925037µs
 *      mnp: 721955µs
 *      mpn: 793389µs
 *      pnm: 1738803µs
 *      pmn: 962802µs
 */

/*
 * multiply( [N][M] * [P][N] ) : [P][M]
 *
 *             <---- P ---->
 *             ^ .
 *             |   .
 *             N     .
 *             |        .
 *             V           .
 *
 * <-- N -->   <---- P ---->
 * ^.          ^ .
 * |  .        |   .
 * M   .       M     .
 * |     .     |        .
 * V       .   V           .
 *
 *
 *         Avg.   | 1     | 2     | 3     | 4     | 5     | 6     | 7     |
 *
 * N M P    472116  468465  466858  466395  465372  483760  478316  475649
 * M N P    450503  446093  447004  448114  450932  457181  454447  449752
 *
 * M P N    680446  492579  969800  923971  605525  527605  503998  739647
 * P M N    793965  632770  1033893 985312  656934  640927  715452  892465
 *
 * P N M   1349704 1391133 1103441 1152507 1610877 1365716 1402298 1421957
 * N P M   1342003 1359540 1098046 1159678 1589834 1410942 1357497 1418485
 *
 */

#include <cstdlib>

#include <chrono>
#include <iostream>

template<int N, int M, typename F>
void fill(int (&matrix)[N][M], F f) {
  for(int n = 0; n < N; ++n)
    for(int m = 0; m < M; ++m)
      matrix[n][m] = f();
}

template<int N, int M, int P>
void multiply1(int (&matrix1)[N][M], int (&matrix2)[P][N], int (&result)[P][M]) {
  for(int n = 0; n < N; ++n)
    for(int m = 0; m < M; ++m)
      for(int p = 0; p < P; ++p)
        result[m][p] += matrix1[m][n] * matrix2[n][p];
}

template<int N, int M, int P>
void multiply2(int (&matrix1)[N][M], int (&matrix2)[P][N], int (&result)[P][M]) {
  for(int n = 0; n < N; ++n)
    for(int p = 0; p < P; ++p)
      for(int m = 0; m < M; ++m)
        result[m][p] += matrix1[m][n] * matrix2[n][p];
}

template<int N, int M, int P>
void multiply3(int (&matrix1)[N][M], int (&matrix2)[P][N], int (&result)[P][M]) {
  for(int m = 0; m < M; ++m)
    for(int n = 0; n < N; ++n)
      for(int p = 0; p < P; ++p)
        result[m][p] += matrix1[m][n] * matrix2[n][p];
}

template<int N, int M, int P>
void multiply4(int (&matrix1)[N][M], int (&matrix2)[P][N], int (&result)[P][M]) {
  for(int m = 0; m < M; ++m)
    for(int p = 0; p < P; ++p)
      for(int n = 0; n < N; ++n)
        result[m][p] += matrix1[m][n] * matrix2[n][p];
}

template<int N, int M, int P>
void multiply5(int (&matrix1)[N][M], int (&matrix2)[P][N], int (&result)[P][M]) {
  for(int p = 0; p < P; ++p)
    for(int n = 0; n < N; ++n)
      for(int m = 0; m < M; ++m)
        result[m][p] += matrix1[m][n] * matrix2[n][p];
}

template<int N, int M, int P>
void multiply6(int (&matrix1)[N][M], int (&matrix2)[P][N], int (&result)[P][M]) {
  for(int p = 0; p < P; ++p)
    for(int m = 0; m < M; ++m)
      for(int n = 0; n < N; ++n)
        result[m][p] += matrix1[m][n] * matrix2[n][p];
}

int main() {
  int matrix1[400][600];
  int matrix2[600][400];
  int matrix3[600][600];

  fill(matrix1, rand);
  fill(matrix2, rand);
  fill(matrix3, []() {
    return 0;
  });

  using namespace std::chrono;

  {
    const auto start = high_resolution_clock::now();
    multiply1(matrix1, matrix2, matrix3);
    const auto end = high_resolution_clock::now();

    std::cout << "nmp: " << duration_cast<microseconds>(end - start).count() << "µs" << std::endl;
  }

  {
    const auto start = high_resolution_clock::now();
    multiply2(matrix1, matrix2, matrix3);
    const auto end = high_resolution_clock::now();

    std::cout << "npm: " << duration_cast<microseconds>(end - start).count() << "µs" << std::endl;
  }

  {
    const auto start = high_resolution_clock::now();
    multiply3(matrix1, matrix2, matrix3);
    const auto end = high_resolution_clock::now();

    std::cout << "mnp: " << duration_cast<microseconds>(end - start).count() << "µs" << std::endl;
  }

  {
    const auto start = high_resolution_clock::now();
    multiply4(matrix1, matrix2, matrix3);
    const auto end = high_resolution_clock::now();

    std::cout << "mpn: " << duration_cast<microseconds>(end - start).count() << "µs" << std::endl;
  }

  {
    const auto start = high_resolution_clock::now();
    multiply5(matrix1, matrix2, matrix3);
    const auto end = high_resolution_clock::now();

    std::cout << "pnm: " << duration_cast<microseconds>(end - start).count() << "µs" << std::endl;
  }

  {
    const auto start = high_resolution_clock::now();
    multiply6(matrix1, matrix2, matrix3);
    const auto end = high_resolution_clock::now();

    std::cout << "pmn: " << duration_cast<microseconds>(end - start).count() << "µs" << std::endl;
  }
}
