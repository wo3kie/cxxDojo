/*
 * Website:
 *      https://github.com/wo3kie/dojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++14 mapUtils.cpp -o mapUtils
 *
 * Usage:
 *      $ ./mapUtils
 */

#include "mapUtils.hpp"

#include <cassert>
#include <set>

struct Data {
    int i;
    char c;
};

bool operator==( Data const & lhs, Data const & rhs){
    return lhs.i == rhs.i && lhs.c == rhs.c;
}

void test_groupBy_1(){
    std::vector<Data> array{
        Data{ 1, 'a' },
        Data{ 1, 'b' },
        Data{ 2, 'c' },
        Data{ 2, 'd' },
        Data{ 3, 'e' },
        Data{ 4, 'f' },
        Data{ 1, 'g' }
    };

    std::map<int, std::vector<Data>> const actual = groupBy(
        array.begin(), 
        array.end(), 
        [](Data data){ return data.i; }
    );

    std::map<int, std::vector<Data>> const expected = {
        {1, { Data{ 1, 'a' }, Data{ 1, 'b' }, Data{ 1, 'g' } } },
        {2, { Data{ 2, 'c' }, Data{ 2, 'd' } } },
        {3, { Data{ 3, 'e' } } },
        {4, { Data{ 4, 'f' } } }
    };

    assert(actual == expected);
}

void test_groupBy_2(){
    std::vector<Data> array{
        Data{ 1, 'a' },
        Data{ 2, 'b' },
        Data{ 3, 'c' },
        Data{ 4, 'a' },
        Data{ 5, 'b' },
        Data{ 6, 'c' },
        Data{ 7, 'a' }
    };

    std::map<char, int> const actual = groupBy(
        array.begin(), 
        array.end(), 
        [](Data data){ return data.c; },
        [](Data data){ return 10 * data.i; },
        [](int merged, int value){ return merged + value; },
        0
    );

    std::map<char, int> const expected = {
        {'a', 10 + 40 + 70},
        {'b', 20 + 50},
        {'c', 30 + 60}
    };

    assert(actual == expected);
}

void test_groupBy_3(){
    std::vector<Data> array{
        Data{ 1, 'a' },
        Data{ 2, 'b' },
        Data{ 3, 'c' },
        Data{ 4, 'a' },
        Data{ 5, 'b' },
        Data{ 6, 'c' },
        Data{ 7, 'a' }
    };

    std::map<char, std::set<int>> const actual = groupBy(
        array.begin(), 
        array.end(), 
        [](Data data){ return data.c; },
        [](Data data){ return 10 * data.i; },
        [](std::set<int> set, int value){ set.insert(value); return set; },
        std::set<int>()
    );

    std::map<char, std::set<int>> const expected = {
        {'a', {10, 40, 70} },
        {'b', {20, 50} },
        {'c', {30, 60} }
    };

    assert(actual == expected);
}

int main(){
    test_groupBy_1();
    test_groupBy_2();
    test_groupBy_3();
}
