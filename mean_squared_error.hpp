/*
 * Website:
 *      https://github.com/wo3kie/cxxdojo
 *
 * Author:
 *      Lukasz Czerwinski
 */

/*
 * meanSquaredError
 */

template<typename Iterator, typename Iterator2>
double meanSquaredError(Iterator expectedBegin, Iterator expectedEnd, Iterator2 actualBegin) {
  std::size_t counter = 0;
  double error2Sum = 0;

  for(/* empty */; expectedBegin != expectedEnd; ++expectedBegin, ++actualBegin) {
    const double error = *expectedBegin - *actualBegin;
    const double error2 = error * error;

    counter += 1;
    error2Sum += error2;
  }

  return error2Sum / counter;
}