/*
 * Website:
 *      https://github.com/wo3kie/dojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++11 container.cpp -o container
 *
 */      

#include <cassert>

#include "./container.hpp"

void rebind_test(){
    typedef std::vector<int> VI;

    static_assert(
        std::is_same<
            ContainerTraits<VI>::rebind<float>::type,
            std::vector<float>
        >::value,
        ":("
    );
}

void insert_test(){
    {
        std::vector<int> vi;
        insert(vi, 5);
        assert(vi[0] == 5);
    }

    {
        std::list<int> li;
        insert(li, 5);
        assert(li.front() == 5);
    }
}

int main(){
    insert_test();
}
