/*
 * Website:
 *      https://github.com/wo3kie/dojo
 *
/*
 * Website:
 *      https://github.com/wo3kie/dojo
 *
 * Author:
 *      Lukasz Czerwinski
 */

#ifndef __CXX_DOJO_FOLD_HPP__
#define __CXX_DOJO_FOLD_HPP__

#include <functional>
#include <iostream>

/*
 * rfold(f, a, b, c, d) == f(a, f(b, f(c, d)))
 */

template<typename R, typename T>
R rfold(std::function<R (T, T)> f, T t1, T t2){
    return f(std::forward<T>(t1), std::forward<T>(t2));
}

template<typename R, typename T, typename ... Ts>
R rfold(std::function<R (T, T)> f, T t, Ts ... tail){
    return f(std::forward<T>(t), rfold(f, std::forward<Ts>(tail)...));
}

/*
 * lfold(f, a, b, c, d) == f( f( f(a, b), c), d)
 */

template<typename R, typename T>
R lfold(std::function<R (T, T)> f, T t1, T t2){
    return f(std::forward<T>(t1), std::forward<T>(t2));
}

template<typename R, typename T, typename ... Ts>
R lfold(std::function<R (T, T)> f, T t1, T t2, Ts ... tail){
    return lfold(f, f(std::forward<T>(t1), std::forward<T>(t2)), std::forward<Ts>(tail)...);
}

#endif
