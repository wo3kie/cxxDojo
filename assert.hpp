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
 * _ExpressionDecomposerBinary
 */

template<typename Actual, typename Expected>
struct _ExpressionDecomposerBinary {
  _ExpressionDecomposerBinary(const char* const file, int line, const char* const op, bool result, Actual actual, Expected expected)
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

  ~_ExpressionDecomposerBinary() {
    if(*this) {
      // empty
    } else {
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
 * _ExpressionDecomposerUnary
 */

template<typename Actual>
struct _ExpressionDecomposerUnary {
  _ExpressionDecomposerUnary(const char* const file, int line, Actual actual)
      : _unary{true}
      , _actual(actual) 
      , _line(line)
      , _file(file)
  {
    on_error([](const char* file, int line, Actual actual) -> void {
      if constexpr (requires { std::cerr << actual; }) {
        std::cerr << file << ':' << line << " Assertion failed" 
          "\n\tactual  : " << actual << 
          "\n\texpected: true" << std::endl;
      } else {
        std::cerr << file << ':' << line << " Assertion failed" << std::endl;
      }
      std::abort();
    });
  }

  ~_ExpressionDecomposerUnary(){
    if (_unary) {
      if constexpr (std::is_convertible_v<Actual, bool>) {
        if (_actual) {
          // empty
        } else {
          _f(_file, _line, _actual);
        }
      } else {
      }
    }

  }

  template<typename Expected>
  _ExpressionDecomposerBinary<Actual, Expected> operator==(Expected expected) {
    _unary = false;
    return {_file, _line, "==", _actual == expected, _actual, expected};
  }

  template<typename Expected>
  _ExpressionDecomposerBinary<Actual, Expected> operator!=(Expected expected) {
    _unary = false;
    return {_file, _line, "!=", _actual == expected, _actual, expected};
  }

  template<typename Expected>
  _ExpressionDecomposerBinary<Actual, Expected> operator<(Expected expected) {
    _unary = false;
    return {_file, _line, "<", _actual < expected, _actual, expected};
  }

  template<typename Expected>
  _ExpressionDecomposerBinary<Actual, Expected> operator<=(Expected expected) {
    _unary = false;
    return {_file, _line, "<=", _actual <= expected, _actual, expected};
  }

  template<typename Expected>
  _ExpressionDecomposerBinary<Actual, Expected> operator>(Expected expected) {
    _unary = false;
    return {_file, _line, ">", _actual > expected, _actual, expected};
  }

  template<typename Expected>
  _ExpressionDecomposerBinary<Actual, Expected> operator>=(Expected expected) {
    _unary = false;
    return {_file, _line, ">=", _actual >= expected, _actual, expected};
  }

  void on_error(std::function<void(const char* /* file */, int /* line */, Actual /* actual */)> f) {
    _f = f;
  }

  std::function<void(const char*, int, Actual)> _f;

  bool _unary;
  Actual _actual;
  
  int _line;
  const char* const _file;
};

/*
 * operator<<
 */

template<typename Actual>
_ExpressionDecomposerUnary<Actual> operator<<(const _ExpressionDecomposerStart& e, Actual value) {
  return _ExpressionDecomposerUnary<Actual>(e._file, e._line, value);
}

/*
 * operator<<
 */

} // namespace impl

/*
 * Assert
 */

#ifdef NDEBUG
#define Assert(__expression__) (static_cast<void>(0))
#else
#define Assert(__expression__) (impl::_ExpressionDecomposerStart(__FILE__, __LINE__) << __expression__)
#endif
