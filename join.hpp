#pragma once

/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cpp-dojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 */

 /*
 * `join` implementation for `std::ranges`
 */

#include <ranges>
#include <string>
#include <string_view>
#include <type_traits>

template<std::ranges::input_range R>
  requires std::convertible_to<std::ranges::range_value_t<R>, std::string_view>
size_t _join_range_calc_length(R&& range) {
  size_t count = 0;
  size_t total_len = 0;

  for(auto&& r : range) {
    count += 1;
    total_len += std::string_view{r}.size();
  }

  if(count > 1) {
    total_len += (count - 1);
  }

  return total_len;
}

template<std::ranges::input_range R>
  requires std::convertible_to<std::ranges::range_value_t<R>, std::string_view>
std::string join(R&& range, char sep) {
  std::string result;
  result.reserve(_join_range_calc_length(range));

  auto begin = std::ranges::begin(range);
  const auto end = std::ranges::end(range);

  if (begin == end) {
    return result;
  }

  {
    result += *begin++;
  }

  while(begin != end) {
    result += sep;
    result += *begin++;
  }

  return result;
}

/* 
 * `join` implementation for variadic templates
 */

template<typename... Ts>
size_t _join_variadic_calc_length(bool skip_empty, Ts&&... ts) {
  size_t count = 0;
  size_t total_len = 0;

  auto count_len = [&](std::string_view s) {
    if(skip_empty && s.empty()) {
      return;
    }

    count += 1;
    total_len += s.size();
  };

  (count_len(std::string_view(ts)), ...);

  if(count > 1) {
    total_len += 1 * (count - 1);
  }

  return total_len;
}

template<typename... Ts>
std::string join(bool skip_empty, char sep, Ts&&... ts) {
  std::string result;
  result.reserve(_join_variadic_calc_length(skip_empty, ts...));

  bool first = true;

  auto append = [&](std::string_view s) -> void {
    if(skip_empty && s.empty()) {
      return;
    }

    if(! first) {
      result += sep;
    }

    result += s;
    first = false;
  };

  (append(ts), ...);

  return result;
}
