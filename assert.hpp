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
#include <memory>

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

template<typename First, typename Second>
struct _ExpressionDecomposerResult {
  _ExpressionDecomposerResult(const char* const file, int line, const char* const op, bool result, const First& first, const Second& second)
      : _file(file)
      , _line(line)
      , _op(op)
      , _result(result)
      , _first(first)
      , _second(second) {
    on_error([](const char* file, int line, const char* op, const First& first, const Second& second) -> void {
      std::cerr << file << ':' << line << " Assertion failed " << first << ' ' << op << ' ' << second << std::endl;
      std::abort();
    });
  }

  ~_ExpressionDecomposerResult() {
    if(! *this) {
      _f(_file, _line, _op, _first, _second);
    }
  }

  operator bool() const {
    return _result;
  }

  void on_error(std::function<void(const char* /* file */, int /* line */, const char* /* op */, const First& /* first */, const Second& /* second */)> f) {
    _f = f;
  }

  const char* const _file;
  int _line;
  const char* const _op;
  bool _result;
  const First& _first;
  const Second& _second;
  std::function<void(const char*, int, const char*, const First&, const Second&)> _f;
};

/*
 * _ExpressionDecomposer
 */

template<typename First>
struct _ExpressionDecomposer {
  _ExpressionDecomposer(const char* const file, int line, const First& first)
      : _file(file)
      , _line(line)
      , _first(first) {
  }

  template<typename Second>
  _ExpressionDecomposerResult<First, Second> operator==(const Second& second) {
    return {_file, _line, "==", _first == second, _first, second};
  }

  template<typename Second>
  _ExpressionDecomposerResult<First, Second> operator!=(const Second& second) {
    return {_file, _line, "!=", _first == second, _first, second};
  }

  template<typename Second>
  _ExpressionDecomposerResult<First, Second> operator<(const Second& second) {
    return {_file, _line, "<", _first < second, _first, second};
  }

  template<typename Second>
  _ExpressionDecomposerResult<First, Second> operator<=(const Second& second) {
    return {_file, _line, "<=", _first <= second, _first, second};
  }

  template<typename Second>
  _ExpressionDecomposerResult<First, Second> operator>(const Second& second) {
    return {_file, _line, ">", _first > second, _first, second};
  }

  template<typename Second>
  _ExpressionDecomposerResult<First, Second> operator>=(const Second& second) {
    return {_file, _line, ">=", _first >= second, _first, second};
  }

  const char* const _file;
  int _line;
  const First& _first;
};

/*
 * operator<<
 */

template<typename First>
_ExpressionDecomposer<First> operator<<(const _ExpressionDecomposerStart& e, const First& value) {
  return _ExpressionDecomposer<First>(e._file, e._line, value);
}

/*
 * operator<<
 */

inline _ExpressionDecomposerResult<bool, bool> operator<<(const _ExpressionDecomposerStart& e, const bool& b) {
  return {e._file, e._line, b ? "!!" : "!", b, b, b};
}

} // namespace impl

/*
 * Assert
 */

#define Assert(__expression__) (impl::_ExpressionDecomposerStart(__FILE__, __LINE__) << __expression__)
