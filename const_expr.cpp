/*
 * Website:
 *      https://github.com/wo3kie/dojo
 *
 * Taylor's theorem
 *      https://en.wikipedia.org/wiki/Taylor%27s_theorem
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++11 const_expr -o const_expr
 *
 * Usage:
 *      $ ./const_expr
 */

namespace const_expr
{
    constexpr long unsigned factorial(unsigned x){
        return x == 0 ? 1 : x * factorial(x - 1);
    }

    void factorial_test(){
        static_assert(factorial(0) == 1, "");
        static_assert(factorial(1) == 1, "");
        static_assert(factorial(2) == 2, "");
        static_assert(factorial(3) == 6, "");
        static_assert(factorial(4) == 24, "");
        static_assert(factorial(5) == 24*5, "");
    }

    constexpr double exp(double x, unsigned e){
        return e == 0 ? 1 : x * exp(x, e - 1);
    }

    constexpr double pi(){
        return 3.141592;
    }

    void exp_test(){
        static_assert(exp(7, 0) == 1, "");
        static_assert(exp(7, 1) == 7, "");
        static_assert(exp(7, 2) == 49, "");
        static_assert(exp(7, 3) == 49*7, "");
        static_assert(exp(7, 4) == 49*49, "");
    }

    constexpr double rad(double rad){
        return rad / 180 * pi();
    }

    void rad_test(){
        static_assert(rad(0) == 0, "");
        static_assert(rad(90) == pi()/2, "");
        static_assert(rad(180) == pi(), "");
        static_assert(rad(360) == 2 * pi(), "");
    }

    constexpr double fabs(double x){
        return x<0 ? -x : x;
    }

    void fabs_test(){
        static_assert(fabs(1.0) == 1.0, "");
        static_assert(fabs(-1.0) == 1.0, "");
    }

    constexpr double sin(double x){
        return
            x
            - (exp(x, 3) / factorial(3))
            + (exp(x, 5) / factorial(5))
            - (exp(x, 7) / factorial(7));
    }

    void sin_test(){
        static_assert(fabs(sin(rad(0)) - 0) < 0.001, "");
        static_assert(fabs(sin(rad(30)) - 0.5) < 0.001, "");
        static_assert(fabs(sin(rad(45)) - 0.707106) < 0.001, "");
        static_assert(fabs(sin(rad(60)) - 0.866017) < 0.001, "");
        static_assert(fabs(sin(rad(90)) - 1) < 0.001, "");
    }

    constexpr double cos(double x){
        return
            1
            - (exp(x, 2) / factorial(2))
            + (exp(x, 4) / factorial(4))
            - (exp(x, 6) / factorial(6));
    }

    void cos_test(){
        static_assert(fabs(cos(rad(0)) - 1) < 0.001, "");
        static_assert(fabs(cos(rad(30)) - 0.86602) < 0.001, "");
        static_assert(fabs(cos(rad(45)) - 0.707106) < 0.001, "");
        static_assert(fabs(cos(rad(60)) -  0.5) < 0.001, "");
        static_assert(fabs(cos(rad(90)) - 0) < 0.001, "");
    }

    void tests(){
        factorial_test();
        exp_test();
        sin_test();
        cos_test();
    }
}

int main(int argc, char * argv[]){
    // no need to run it, compilation is enough
    const_expr::tests();

    return 0;
}

