#include <iostream>

char modulo10(int r, int t){
    return '0' + (r % 10);
}

char hash(int r, int t){
    return (r >= t) ? '#' : ' ';
}

char asciiArt(int r, int t){
    char const * const ascii = " .,:;^*&#@";
    return ascii[ r % 10 ];
}

void mandelbrot( char (*getAscii)(int, int) ){
    double scale = 1;

    int width = scale * 150;
    double const wStep = 4.0 / width;

    int height = scale * 60;
    double const hStep = 4.0 / height;

    int const threshold = 50;

    for( int h = 0 ; h < height ; ++h ){
        for( int w = 0 ; w < width ; ++w ){
            double const n = wStep * w - 2;
            double const u = hStep * h - 2;
            
            int r = 0;
            double x = 0;
            double y = 0;

            for( r = 0 ; x * x + y * y < 4 && r < threshold ; ++r ){
                double const temp = x * x - y * y + n;
                y = 2 * x * y + u;
                x = temp;
            }

            std::cout << getAscii(r, threshold);
        }

        std::cout << std::endl;
    }
}

int main(){
    mandelbrot( & modulo10 );
    mandelbrot( & hash );
    mandelbrot( & asciiArt );
}
