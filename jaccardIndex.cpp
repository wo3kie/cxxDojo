/*
 * Website:
 *      https://github.com/wo3kie/dojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++11 jaccardIndex.cpp -o jaccardIndex
 *
 * Usage:
 *      $ ./jaccardIndex
 */

#include <algorithm>
#include <cassert>
#include <iterator>
#include <type_traits>

#include "./feq.hpp"

template<typename Iterator1, typename Iterator2>
double jaccardIndex(
    Iterator1 begin1,
    Iterator1 end1,
    Iterator2 begin2,
    Iterator2 end2
){
    typedef typename std::iterator_traits<Iterator1>::value_type type1;
    typedef typename std::iterator_traits<Iterator2>::value_type type2;

    static_assert(std::is_same<type1, type2>::value, "type1 != type2");

    std::vector<type1> set_intersection;
    std::set_intersection(begin1, end1, begin2, end2, std::back_inserter(set_intersection));

    std::vector<type1> set_union;
    std::set_union(begin1, end1, begin2, end2, std::back_inserter(set_union));

    if(set_union.empty()){
        return 1;
    }

    return 1.0 * set_intersection.size() / set_union.size();
}

template<typename T>
double jaccardIndex(
    std::vector<T> const & vector1,
    std::vector<T> const & vector2
){
    return jaccardIndex(vector1.begin(), vector1.end(), vector2.begin(), vector2.end());
}

int main(){
    assert(jaccardIndex<int>({1, 2, 3, 4, 5}, {1, 2, 3, 4, 5}) == 1);
    assert(jaccardIndex<int>({1, 2, 3, 4, 5}, {6, 7, 8, 9   }) == 0);
    assert(feq(jaccardIndex<int>({1, 2, 3, 4, 5}, {1, 3, 5, 7, 9}), 3.0 / 7));
}
