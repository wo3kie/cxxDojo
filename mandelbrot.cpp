/*
 * Website:
 *      https://github.com/wo3kie/dojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++11 mandelbrot.cpp -o mandelbrot
 *
 * Usage:
 *      $ ./mandelbrot
 */

#include <iostream>

char digit(int iteration, int maxIteration){
    return '0' + (iteration % 10);
}

char hash(int iteration, int maxIteration){
    return (iteration >= maxIteration) ? '#' : ' ';
}

char asciiArt1(int iteration, int maxIteration){
    char const * const ascii = " .,:;^*&#@";
    return ascii[ iteration % 10 ];
}

char asciiArt2(int iteration, int maxIteration){
    char const * const ascii = "@#&*^;:,. ";
    return ascii[ iteration % 10 ];
}

void mandelbrot( char (*getAscii)(int, int) ){
    double scale = 1;

    int width = scale * 150;
    double const wStep = 4.0 / width;

    int height = scale * 60;
    double const hStep = 4.0 / height;

    int const maxIteration = 50;

    for( int h = 0 ; h < height ; ++h ){
        for( int w = 0 ; w < width ; ++w ){
            double const x0 = wStep * w - 2;
            double const y0 = hStep * h - 2;
            
            int iteration = 0;
            double x = 0;
            double y = 0;

            for( ; x * x + y * y < 4 && iteration < maxIteration ; ++iteration ){
                double const temp = x * x - y * y + x0;
                y = 2 * x * y + y0;
                x = temp;
            }

            std::cout << getAscii(iteration, maxIteration);
        }

        std::cout << std::endl;
    }
}

int main(){
    mandelbrot( & digit );
    mandelbrot( & hash );
    mandelbrot( & asciiArt1 );
    mandelbrot( & asciiArt2 );
}
