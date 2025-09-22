#pragma once

/*
* Website:
*      https://github.com/wo3kie/cxxdojo
*
* Author:
*      Lukasz Czerwinski
*/

#include <type_traits>
#include <utility>

/*
 * Type
 */

template<typename T, typename Tag = decltype([](T)->void{})>
struct Type {
    using type = std::decay_t<T>;
    using tag = Tag;

    Type()
     : _t()
    {
    }

    Type(const T& t)
     : _t(t)
    {
    }

    Type(type&& t)
     : _t(std::move(t))
    {
    }

    Type& operator=(const Type& other) = default;
    Type& operator=(Type&&) = default;

    operator type& () {
        return _t;
    }

    operator const type& () const {
        return _t;
    }

    type& get() {
        return _t;
    }

    const type& get() const {
        return _t;
    }

    type& operator*() {
        return _t;
    }

    const type& operator*() const {
        return _t;
    }

    type _t;
};
