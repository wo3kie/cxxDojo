/*
 * Website:
 *      https://github.com/wo3kie/dojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++11 gcd.cpp -o gcd
 *
 * Usage:
 *      $ ./gcd
 */

constexpr unsigned gcd(unsigned a, unsigned b){
	return b == 0
		? a
		: gcd(b, a % b);
}

template<unsigned A, unsigned B>
struct Gcd {
	enum { value = Gcd<B, A % B>::value };
};

template<unsigned A>
struct Gcd<A, 0> {
	enum { value = A };
};

void gcd_test(){
	static_assert(gcd( 0, 7) == 7, "");
	static_assert(gcd( 1, 7) == 1, "");
	static_assert(gcd( 2, 7) == 1, "");
	static_assert(gcd( 3, 7) == 1, "");
	static_assert(gcd( 4, 7) == 1, "");
	static_assert(gcd( 5, 7) == 1, "");
	static_assert(gcd( 6, 7) == 1, "");
	static_assert(gcd( 7, 7) == 7, "");
	static_assert(gcd( 8, 7) == 1, "");
	static_assert(gcd( 9, 7) == 1, "");
	static_assert(gcd(10, 7) == 1, "");
	static_assert(gcd(11, 7) == 1, "");
	static_assert(gcd(12, 7) == 1, "");
	static_assert(gcd(13, 7) == 1, "");
	static_assert(gcd(14, 7) == 7, "");
}

void Gcd_test(){
	static_assert(Gcd< 0, 7>::value == 7, "");
	static_assert(Gcd< 1, 7>::value == 1, "");
	static_assert(Gcd< 2, 7>::value == 1, "");
	static_assert(Gcd< 3, 7>::value == 1, "");
	static_assert(Gcd< 4, 7>::value == 1, "");
	static_assert(Gcd< 5, 7>::value == 1, "");
	static_assert(Gcd< 6, 7>::value == 1, "");
	static_assert(Gcd< 7, 7>::value == 7, "");
	static_assert(Gcd< 8, 7>::value == 1, "");
	static_assert(Gcd< 9, 7>::value == 1, "");
	static_assert(Gcd<10, 7>::value == 1, "");
	static_assert(Gcd<11, 7>::value == 1, "");
	static_assert(Gcd<12, 7>::value == 1, "");
	static_assert(Gcd<13, 7>::value == 1, "");
	static_assert(Gcd<14, 7>::value == 7, "");
}

int main(){
}

