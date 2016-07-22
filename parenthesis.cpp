/*
 * Website:
 *      https://github.com/wo3kie/dojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++11 parenthesis.cpp -o parenthesis
 *
 * Usage:
 *      $ ./parenthesis
 */

#include <iostream>
#include <fstream>
#include <map>
#include <string>

#include "./output.hpp"

std::vector<std::string> parenthesisImpl(
    int open,
    int close,
    int maxOpen,
    int maxClose,
    std::vector<std::string> solutions1
){
    std::vector<std::string> solutions2 = solutions1;

    if(close + 1 <= open){
        for(std::string & s : solutions1){
            s += ")";
        }

        solutions1 = parenthesisImpl(open, close + 1, maxOpen, maxClose, solutions1);
    }

    if(open + 1 <= maxOpen){
        for(std::string & s : solutions2){
            s += "(";
        }

        solutions2 = parenthesisImpl(open + 1, close, maxOpen, maxClose, solutions2);

        solutions1.insert(
            solutions1.end(),
            solutions2.begin(),
            solutions2.end()
        );
    }

    return solutions1;
}

std::vector<std::string> parenthesis(int number){
    std::vector<std::string> strings;
    strings.push_back("");

    return parenthesisImpl(
        0,
        0,
        number, 
        number,
        strings
    );
}


int main(int argc, char * argv[]){
    std::cout << parenthesis(1) << std::endl;
    std::cout << parenthesis(2) << std::endl;
    std::cout << parenthesis(3) << std::endl;
}

