#pragma once

/*
 * Project:
 *      CxxDojo (https://github.com/wo3kie/cxxdojo)
 *
 * Author:
 *      Lukasz Czerwinski (https://www.lukaszczerwinski.pl/)
 */

/*
 * Overload
 */

template<typename... Ts>
struct Overload: Ts... {
  using Ts::operator()...;
};

/*
 * Overload CTAD
 */

template<typename... Ts>
Overload(Ts...) -> Overload<Ts...>;
