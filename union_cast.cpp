/*
 * Website:
 *      https://github.com/wo3kie/dojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++11 union_cast.cpp -o union_cast
 *
 * Usage:
 *      $ ./union_cast
 */

#include <cassert>

#include "./union_cast.hpp"

struct S1{
    int i_;
};

struct S2{
    float f_;
};

int main()
{
    {
        S1 s1{ 123 };
        assert( union_cast< S1 >( union_cast< S2 >( s1 ) ).i_ == 123 );
    }

    {
        S1 const s1{ 123 };
        assert( union_cast< S1 >( union_cast< S2 >( s1 ) ).i_ == 123 );
    }  

    {
        assert( union_cast< S1 >( union_cast< S2 >( S1{ 123 } ) ).i_ == 123 );
    }  
}

