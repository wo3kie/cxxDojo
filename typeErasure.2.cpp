/*
 * Website:
 *      https://github.com/wo3kie/dojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++20 typeErasure.2.cpp -o typeErasure.2
 *
 * Usage:
 *      $ ./typeErasure
 */

#include <cassert>
#include <cmath>
#include <functional>
#include <iostream>
#include <memory>
#include <string>
#include <vector>

/*
 *
 */

struct S {
    char doIt(int i, double d) {
        return 's';
    }
};

struct T {
    char doIt(int i, double d){
        return 't';
    }
};

/*
 * DoIt_TypeErasure
 */

struct DoIt_TypeErasure {
    template<typename R>
    DoIt_TypeErasure(R& r)
        : _ptr(&r)
        , _doIt([this](void* ptr) -> std::function<char (int, double)> {
            return [p = static_cast<R*>(this->_ptr)](int i, double d) -> char { return p->doIt(i, d); };
        })
    {
    }

    char doIt(int i, double d) {
        return _doIt(_ptr)(i, d);
    }

    void* _ptr;
    std::function<std::function<char (int, double)> (void*)> _doIt;
};

/*
 * test
 */

char f(DoIt_TypeErasure r) {
    return r.doIt(1, 2.3);
}

void test() {
    S s;
    assert(f(DoIt_TypeErasure{s}) == 's');
   
    T t;
    assert(f(DoIt_TypeErasure{t}) == 't');
}

/*
 * main
 */

int main() {
  test();
}
