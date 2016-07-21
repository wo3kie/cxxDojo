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

std::set<std::set<int>> getAllSubsetsImpl(
    std::set<std::set<int>> & sets1,
    std::set<int> set
){
    if(set.empty()){
        return sets1;
    }

    int item = * set.begin();
    set.erase(set.begin());

    std::set<std::set<int>> sets2;

    for(std::set<int> s : sets1){
        s.insert(item);
        sets2.insert(s);
    }

    std::set<std::set<int>> subsets1 = getAllSubsetsImpl(sets1, set);
    std::set<std::set<int>> subsets2 = getAllSubsetsImpl(sets2, set);

    subsets1.insert(
        subsets2.begin(),
        subsets2.end()
    );

    return subsets1;
}

std::set<std::set<int>> getAllSubsets(std::set<int> const & set){
    std::set<std::set<int>> sets;
    sets.insert(std::set<int>());
    return getAllSubsetsImpl(sets, set);
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

