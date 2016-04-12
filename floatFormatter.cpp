#include "./floatFormatter.hpp"

int main(){
    std::cout << "\"" << FloatFormatter(0, 1) << "\"" << "\n";
    std::cout << "\"" << FloatFormatter(0, 2) << "\"" << "\n";
    std::cout << "\"" << FloatFormatter(0, 3) << "\"" << "\n\n";

    std::cout << "\"" << FloatFormatter(0.00000012, 5) << "\"" << "\n";
    std::cout << "\"" << FloatFormatter(0.00000012, 6) << "\"" << "\n";
    std::cout << "\"" << FloatFormatter(0.00000012, 7) << "\"" << "\n";
    std::cout << "\"" << FloatFormatter(0.00000012, 8) << "\"" << "\n";
    std::cout << "\"" << FloatFormatter(0.00000012, 9) << "\"" << "\n\n";

    std::cout << "\"" << FloatFormatter(0.12345678, 5) << "\"" << "\n";
    std::cout << "\"" << FloatFormatter(0.12345678, 6) << "\"" << "\n";
    std::cout << "\"" << FloatFormatter(0.12345678, 7) << "\"" << "\n";
    std::cout << "\"" << FloatFormatter(0.12345678, 8) << "\"" << "\n";
    std::cout << "\"" << FloatFormatter(0.12345678, 9) << "\"" << "\n\n";

    std::cout << "\"" << FloatFormatter(123456.789, 5) << "\"" << "\n";
    std::cout << "\"" << FloatFormatter(123456.789, 6) << "\"" << "\n";
    std::cout << "\"" << FloatFormatter(123456.789, 7) << "\"" << "\n";
    std::cout << "\"" << FloatFormatter(123456.789, 8) << "\"" << "\n";
    std::cout << "\"" << FloatFormatter(123456.789, 9) << "\"" << "\n\n";
}
