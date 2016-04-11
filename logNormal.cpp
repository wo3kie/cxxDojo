/*
 * Website:
 *      https://github.com/wo3kie/dojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++11 logNormal.cpp -o logNormal
 *
 * Usage:
 *      $ ./logNormal
 */

#include <cmath>
#include <functional>
#include <iostream>
#include <iomanip>
#include <limits>
#include <map>
#include <random>

std::random_device rd;
std::mt19937 gen(rd());

double getLogNormalRandom(){
    return std::exp(std::normal_distribution<>(0, 1)(gen));
}

double getNormalRandom(double mu, double sigma){
    return std::log(getLogNormalRandom()) * sigma + mu;
}

std::map<int, int> getDistribution(std::function<double ()> const & f){
    std::map<int, int> result;

    for(int i = 0; i < 50 * 1000; i++){
        result[ std::round(f()) ] += 1;
    }

    for(auto & pair : result){
        pair.second /= 200;
    }

    return result;
}

void printDistrubution(std::map<int, int> const & map){
    for(auto const & pair : map){
        std::cout << std::fixed << std::setprecision(1) << std::setw(2)
            << pair.first << " " << std::string(pair.second, '*') << std::endl;
    }
}

int main(){
    std::cout << "Normal Distrubution" << std::endl;
    printDistrubution(getDistribution([](){return getNormalRandom(10, 3);}));

    std::cout << "\nLog Normal Distribution" << std::endl;
    printDistrubution(getDistribution([](){return getLogNormalRandom();}));
}
