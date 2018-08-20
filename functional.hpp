/*
 * Website:
 *      https://github.com/wo3kie/dojo
 *
 * Author:
 *      Lukasz Czerwinski
 */

#ifndef __CXX_DOJO_FUNCTIONAL_HPP__
#define __CXX_DOJO_FUNCTIONAL_HPP__

#include <algorithm>
#include <iterator>
#include <functional>

#include "./container.hpp"

namespace dojo {

template<typename R, typename T, typename I>
R _lfold(
    std::function<R (T, T)> f,
    R init,
    I begin, 
    I end
){
    if(begin == end){
        return init;
    }
    else{
        return _lfold(f, f(init, *begin), std::next(begin), end);
    }

}

template<typename Return, typename Container>
Return lfold(
    Container c,
    std::function<Return (typename Container::value_type, typename Container::value_type)> f
){
    return _lfold(f, *c.begin(), std::next(c.begin()), c.end());
}

template<typename R, typename T, typename I>
R _rfold(
    std::function<R (T, T)> f,
    R init,
    I begin, 
    I end
){
    if(std::distance(begin, end) == 2){
        return f(*begin, *std::next(begin));
    }
    else{
        return f(init, _rfold(f, init, std::next(begin), end));
    }
}

template<typename Return, typename Container>
Return rfold(
    Container c,
    std::function<Return (typename Container::value_type, typename Container::value_type)> f
){
    return _rfold(f, *c.begin(), std::next(c.begin()), c.end());
}

template<typename Container>
typename Container::value_type sum(Container container){
    typedef typename Container::value_type value_type;
    
    std::function<value_type (value_type, value_type)> f
        = [](value_type lhs, value_type rhs) -> value_type { return lhs + rhs; };
    
    return lfold(
        container,
        f
    );
}

template<typename Container>
typename Container::value_type product(Container container){
    typedef typename Container::value_type value_type;
    
    std::function<value_type (value_type, value_type)> f
        = [](value_type lhs, value_type rhs) -> value_type { return lhs * rhs; };
    
    return lfold(
        container,
        f
    );
}

template<typename Container>
typename Container::value_type min(Container container){
    typedef typename Container::value_type value_type;
    
    std::function<value_type (value_type, value_type)> f
        = [](value_type lhs, value_type rhs) -> value_type { return lhs < rhs ? lhs : rhs; };
    
    return lfold(
        container,
        f
    );
}

template<typename Container>
typename Container::value_type max(Container container){
    typedef typename Container::value_type value_type;
    
    std::function<value_type (value_type, value_type)> f
        = [](value_type lhs, value_type rhs) -> value_type { return lhs < rhs ? rhs : lhs; };
    
    return lfold(
        container,
        f
    );
}

template<typename Container>
Container & filter(Container & container, std::function<bool (typename Container::value_type)> predicate){
    typename Container::iterator toBeRemoved = std::partition(
        container.begin(),
        container.end(),
        predicate
    );

    container.erase(toBeRemoved, container.end());

    return container;
}

template<typename Container>
Container filter_copy(Container const & container, std::function<bool (typename Container::value_type)> predicate){
    Container result;

    for(const typename Container::value_type & item: container){
        if(predicate(item)){
            result.push_back(item);
        }
    }

    return result;
}

template<typename Return, typename Container>
auto map(Container container, std::function<Return (typename Container::value_type)> functor) 
    -> typename ContainerTraits<Container>::template rebind<Return>::type
{
    typename ContainerTraits<Container>::template rebind<Return>::type result;

    for(typename Container::value_type const & item: container){
        result.push_back(functor(item));
    }

    return result;
}

}

#endif
