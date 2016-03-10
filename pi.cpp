/*
 * Website:
 *      https://github.com/wo3kie/dojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++11 pi.cpp -o pi
 *
 * Usage:
 *      $ ./pi
 */

#include <iostream>

double getPi(unsigned const iterations){
    unsigned inside = 0;
    
    for(int i = 0; i < iterations; ++i){
        double const x = (2.0 * rand() / RAND_MAX) - 1.0;
        double const y = (2.0 * rand() / RAND_MAX) - 1.0;
        
        if(x*x + y*y <= 1){
            inside += 1;
        }
    }

    return 4.0 * inside / iterations;
}

int main(int argc, char* argv[]){
    std::cout << getPi(10) << std::endl;
    std::cout << getPi(100) << std::endl;
    std::cout << getPi(1000) << std::endl;
    std::cout << getPi(10000) << std::endl;
    std::cout << getPi(100000) << std::endl;
}

