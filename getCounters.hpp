/*
 * Website:
 *      https://github.com/wo3kie/dojo
 *
 * Author:
 *      Lukasz Czerwinski
 */

#ifndef CXX_DOJO_GET_COUNTERS_HPP
#define CXX_DOJO_GET_COUNTERS_HPP

#include <iterator>
#include <map>

template< typename Iterator >
std::map<
    typename std::iterator_traits< Iterator >::value_type, 
    unsigned 
> 
getCounters( Iterator begin, Iterator const end ){
    std::map<
        typename std::iterator_traits< Iterator >::value_type,
        unsigned
    > result;

    for( /* empty */ ; begin != end ; ++ begin ){
        result[ * begin ] += 1;
    }

    return result;
}

#endif
