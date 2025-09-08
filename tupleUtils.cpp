/*
 * Website:
 *      https://github.com/wo3kie/dojo
 * 
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++17 tupleUtils.cpp -o tupleUtils
 *
 * Usage:
 *      $ ./tupleUtils
 */

#include <cassert>

#include "tupleUtils.hpp"

void foldl_test() {
    std::tuple<bool, int, double> tcid{true, 2, 3.3};
    
    const auto fl = [](int acc, auto a) -> int {
        return acc + int(a);
    };
    
    assert(tuple::foldl(fl, 0, tcid) == 1 + 2 + 3);
}

void foldr_test() {
    std::tuple<bool, int, double> tcid{true, 2, 3.3};

    const auto fr = [](auto a, int acc) -> int {
        return int(a) + acc;
    };

    assert(tuple::foldr(fr, 0, tcid) == 1 + 2 + 3);
}

void hash_test() {
    std::tuple<bool> tb{false};
    tuple::hash(tb);

    std::tuple<bool, int> tbi{false, 1};
    tuple::hash(tbi);

    std::tuple<bool, int, float> tbif{false, 1, 1.11};
    tuple::hash(tbif);
}

template<typename T>
struct IsBig : std::conditional_t<(sizeof(T) > 4), std::true_type, std::false_type> {
};

void IsBig_test() {
    static_assert(IsBig<char>::value == false);
    static_assert(IsBig<double>::value == true);
}

void All_test() {
    static_assert(tuple::All<IsBig, std::tuple<char, int, float>>::value == false);
    static_assert(tuple::All<IsBig, std::tuple<double, long, long double>>::value == true);
}

void Any_test() {
    static_assert(tuple::Any<IsBig, std::tuple<char, int, float>>::value == false);
    static_assert(tuple::Any<IsBig, std::tuple<char, int, double>>::value == true);
}  

void None_test() {
    static_assert(tuple::None<IsBig, std::tuple<char, int, float>>::value == true);
    static_assert(tuple::None<IsBig, std::tuple<char, int, double>>::value == false);
}

void Foldl_test() {
    std::tuple<bool, int, float> tbif{false, 1, 1.11};

    static_assert(std::is_same_v<int, tuple::Foldl<std::common_type, std::tuple<short, int>>::type>);
    static_assert(std::is_same_v<double, tuple::Foldl<std::common_type, std::tuple<short, int, double>>::type>);
}

int main() {
    foldl_test();
    foldr_test();
    hash_test();

    IsBig_test();
    All_test();
    Any_test();
    None_test();
    Foldl_test();
}
