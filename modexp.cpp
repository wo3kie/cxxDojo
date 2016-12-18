/*
 * Website:
 *      https://github.com/wo3kie/dojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++11 modexp.cpp -o modexp
 *
 * Usage:
 *      $ ./modexp
 */

#include <cassert>
#include <cmath>
#include <iostream>

constexpr unsigned pow2(unsigned a){
	return a * a;
}

constexpr unsigned modexp(unsigned a, unsigned exp, unsigned mod){
	return exp == 0
		? 1
		
		//: exp % 2 == 0
		//	? (    pow2(modexp(a, exp/2, mod))) % mod
		//	: (a * pow2(modexp(a, exp/2, mod))) % mod;

		: ( (exp % 2 == 0 ? 1 : a) * pow2(modexp(a, exp/2, mod)) % mod );
}

void modexp_test(){
	for(unsigned a = 1; a < 10; ++a){
		for(unsigned exp = 1; exp < 10; ++exp){
			for(unsigned mod = 1; mod < 10; ++mod){
				assert(modexp(a, exp, mod) == (unsigned)std::pow(a, exp) % mod);
			}
		}
	}
}

int main(){
	modexp_test();
}

