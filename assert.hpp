#pragma once

/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cxxdojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 */

#include <cassert>
#include <functional>
#include <iostream>

#include "./output.hpp"

namespace impl {

/*
 * _ExpressionDecomposerStart
 */

struct _ExpressionDecomposerStart {
  const char* const _file;
  int _line;
};

/*
 * _ExpressionDecomposerResult
 */

template<typename Actual, typename Expected>
struct _ExpressionDecomposerResult {
  _ExpressionDecomposerResult(const char* const file, int line, const char* const op, bool result, Actual actual, Expected expected)
      : _file(file)
      , _line(line)
      , _op(op)
      , _result(result)
      , _actual(actual)
      , _expected(expected) {
    on_error([](const char* file, int line, const char* op, Actual actual, Expected expected) -> void {
      if constexpr (requires { std::cerr << actual << expected; }) {
        std::cerr << file << ':' << line << " Assertion failed" 
          "\n\tactual  : " << actual << 
          "\n\texpected: " << expected << std::endl;
      } else {
        std::cerr << file << ':' << line << " Assertion failed" << std::endl;
      }
      std::abort();
    });
  }

  ~_ExpressionDecomposerResult() {
    if(! *this) {
      _f(_file, _line, _op, _actual, _expected);
    }
  }

  operator bool() const {
    return _result;
  }

  void on_error(std::function<void(const char* /* file */, int /* line */, const char* /* op */, Actual /* actual */, Expected /* expected */)> f) {
    _f = f;
  }

  const char* const _file;
  int _line;
  const char* const _op;
  bool _result;
  Actual _actual;
  Expected _expected;
  std::function<void(const char*, int, const char*, Actual, Expected)> _f;
};

/*
 * _ExpressionDecomposer
 */

template<typename Actual>
struct _ExpressionDecomposer {
  _ExpressionDecomposer(const char* const file, int line, Actual actual)
      : _file(file)
      , _line(line)
      , _actual(actual) {
  }

  template<typename Expected>
  _ExpressionDecomposerResult<Actual, Expected> operator==(Expected expected) {
    return {_file, _line, "==", _actual == expected, _actual, expected};
  }

  template<typename Expected>
  _ExpressionDecomposerResult<Actual, Expected> operator!=(Expected expected) {
    return {_file, _line, "!=", _actual == expected, _actual, expected};
  }

  template<typename Expected>
  _ExpressionDecomposerResult<Actual, Expected> operator<(Expected expected) {
    return {_file, _line, "<", _actual < expected, _actual, expected};
  }

  template<typename Expected>
  _ExpressionDecomposerResult<Actual, Expected> operator<=(Expected expected) {
    return {_file, _line, "<=", _actual <= expected, _actual, expected};
  }

  template<typename Expected>
  _ExpressionDecomposerResult<Actual, Expected> operator>(Expected expected) {
    return {_file, _line, ">", _actual > expected, _actual, expected};
  }

  template<typename Expected>
  _ExpressionDecomposerResult<Actual, Expected> operator>=(Expected expected) {
    return {_file, _line, ">=", _actual >= expected, _actual, expected};
  }

  const char* const _file;
  int _line;
  Actual _actual;
};

/*
 * operator<<
 */

template<typename Actual>
_ExpressionDecomposer<Actual> operator<<(const _ExpressionDecomposerStart& e, Actual value) {
  return _ExpressionDecomposer<Actual>(e._file, e._line, value);
}

/*
 * operator<<
 */

inline _ExpressionDecomposerResult<bool, bool> operator<<(const _ExpressionDecomposerStart& e, bool b) {
  return {e._file, e._line, "==", b, b, true};
}

} // namespace impl

/*
 * Assert
 */

#ifdef NDEBUG
#define Assert(__expression__) (static_cast<void>(0))
#else
#define Assert(__expression__) (impl::_ExpressionDecomposerStart(__FILE__, __LINE__) << __expression__)
#endif
