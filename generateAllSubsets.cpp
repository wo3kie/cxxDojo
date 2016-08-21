/*
 * Website:
 *      https://github.com/wo3kie/dojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++11 generateAllSubsets.cpp -o generateAllSubsets
 *
 * Usage:
 *      $ ./generateAllSubsets
 */

#include <cassert>
#include <iostream>
#include <set>
#include <vector>

#include "./output.hpp"

std::set<std::set<int>> getAllSubsets(
    std::set<int> set
){
    std::set<std::set<int>> result;
    result.insert(std::set<int>());

    if(set.size() == 0){
        return result;
    }

    int item = * set.begin();
    set.erase(set.begin());
    std::set<std::set<int>> subsets = getAllSubsets(set);

    for(std::set<int> subset : subsets){
        result.insert(subset);
        subset.insert(item);
        result.insert(subset);
    }

    return result;
}

int main()
{
    std::set<std::set<int>> actual = getAllSubsets(std::set<int>{ 1, 2, 3 });

    std::set<std::set<int>> expected = std::set<std::set<int>>{
        std::set<int>(), 
        {1}, {2}, {3}, 
        {1, 2}, {1, 3}, {2, 3}, 
        {1, 2, 3}
    };

    assert(actual == expected);
}

