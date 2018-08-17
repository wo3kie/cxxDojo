/*
 * Website:
 *      https://github.com/wo3kie/dojo
 *
 * Author:
 *      Lukasz Czerwinski
 */

#ifndef __CXX_DOJO_FUNCTIONAL_HPP__
#define __CXX_DOJO_FUNCTIONAL_HPP__

#include <iterator>
#include <functional>

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

template<typename R, typename T, typename I>
R lfold(
    std::function<R (T, T)> f,
    I begin, 
    I end
){
    return _lfold(f, *begin, std::next(begin), end);
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

template<typename R, typename T, typename I>
R rfold(
    std::function<R (T, T)> f,
    I begin, 
    I end
){
    return _rfold(f, *begin, std::next(begin), end);
}

template<typename I>
typename std::iterator_traits<I>::value_type sum(I begin, I end){
    typedef typename std::iterator_traits<I>::value_type value_type;
    
    std::function<value_type (value_type, value_type)> f
        = [](value_type lhs, value_type rhs) -> value_type { return lhs + rhs; };
    
    return lfold(
        f,
        begin,
        end
    );
}

template<typename I>
typename std::iterator_traits<I>::value_type product(I begin, I end){
    typedef typename std::iterator_traits<I>::value_type value_type;
    
    std::function<value_type (value_type, value_type)> f
        = [](value_type lhs, value_type rhs) -> value_type { return lhs * rhs; };
    
    return lfold(
        f,
        begin,
        end
    );
}

template<typename I>
typename std::iterator_traits<I>::value_type min(I begin, I end){
    typedef typename std::iterator_traits<I>::value_type value_type;
    
    std::function<value_type (value_type, value_type)> f
        = [](value_type lhs, value_type rhs) -> value_type { return lhs < rhs ? lhs : rhs; };
    
    return lfold(
        f,
        begin,
        end
    );
}

template<typename I>
typename std::iterator_traits<I>::value_type max(I begin, I end){
    typedef typename std::iterator_traits<I>::value_type value_type;
    
    std::function<value_type (value_type, value_type)> f
        = [](value_type lhs, value_type rhs) -> value_type { return lhs < rhs ? rhs : lhs; };
    
    return lfold(
        f,
        begin,
        end
    );
}

}

#endif
