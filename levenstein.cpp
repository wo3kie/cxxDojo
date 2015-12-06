/*
 * Website:
 *      https://github.com/wo3kie/dojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++11 levenstein.cpp -o levenstein
 *
 * Usage:
 *      $ ./levenstein distance distant
 *      2
 */

#include <cassert>
#include <iostream>
#include <string>
#include <vector>

namespace utils
{
    template< typename T >
    T min( T const & t1, T const & t2, T const & t3 ){
        return std::min( std::min( t1, t2 ), t3 );
    }
}   

template< typename ArrayT >
std::size_t levensteinDistance(
    ArrayT const & array1,
    ArrayT const & array2
)
{
    std::size_t const array1Size = array1.size();
    std::size_t const array2Size = array2.size();

    if( array1Size == 0 ) {
        return array2Size;
    }

    if( array2Size == 0 ) {
        return array1Size;
    }

    std::vector< std::vector< std::size_t > > partialResults;

    std::size_t const partialResultsColumnsNo = array1Size + 1;
    std::size_t const partialResultsRowsNo = array2Size + 1;

    partialResults.resize( partialResultsRowsNo );

    for( std::size_t index = 0 ; index < partialResultsRowsNo ; ++ index ){
        partialResults[ index ].resize( partialResultsColumnsNo );
    }

    for( std::size_t index = 0 ; index < partialResultsRowsNo ; ++ index ){
        partialResults[ index ][ 0 ] = index;
    }

    for( std::size_t index = 0 ; index < partialResultsColumnsNo ; ++ index ){
        partialResults[ 0 ][ index ] = index;
    }

    for( std::size_t array1Index = 0 ; array1Index < array1Size ; ++ array1Index ){
        for( std::size_t array2Index = 0 ; array2Index < array2Size ; ++ array2Index ){
            if( array1[ array1Index ] == array2[ array2Index ] ) {
                partialResults[ array2Index + 1 ][ array1Index + 1 ]
                    = partialResults[ array2Index + 1 - 1 ][ array1Index + 1 - 1 ];
            }
            else {
                partialResults[ array2Index + 1 ][ array1Index + 1 ] = 1 + utils::min(
                    partialResults[ array2Index + 1 - 1 ][ array1Index + 1 - 1 ],
                    partialResults[ array2Index + 1 - 1 ][ array1Index + 1     ],
                    partialResults[ array2Index + 1     ][ array1Index + 1 - 1 ]
                );
            }
        }
    }

    return partialResults.back().back();
}

namespace test
{

    void levensteinDistance_test_1(){
        assert( 0 == levensteinDistance< std::string >( "", "" ) );
        assert( 0 == levensteinDistance< std::string >( "euler", "euler" ) );
    }

    void levensteinDistance_test_2(){
        assert( 1 == levensteinDistance< std::string >( "", "e" ) );

        assert( 1 == levensteinDistance< std::string >( "euler", "uler" ) );
        assert( 1 == levensteinDistance< std::string >( "euler", "eler" ) );
        assert( 1 == levensteinDistance< std::string >( "euler", "euer" ) );
        assert( 1 == levensteinDistance< std::string >( "euler", "eulr" ) );
        assert( 1 == levensteinDistance< std::string >( "euler", "eule" ) );

        assert( 1 == levensteinDistance< std::string >( "euler", "_euler" ) );
        assert( 1 == levensteinDistance< std::string >( "euler", "e_uler" ) );
        assert( 1 == levensteinDistance< std::string >( "euler", "eu_ler" ) );
        assert( 1 == levensteinDistance< std::string >( "euler", "eul_er" ) );
        assert( 1 == levensteinDistance< std::string >( "euler", "eule_r" ) );
        assert( 1 == levensteinDistance< std::string >( "euler", "euler_" ) );

        assert( 1 == levensteinDistance< std::string >( "euler", "_uler" ) );
        assert( 1 == levensteinDistance< std::string >( "euler", "e_ler" ) );
        assert( 1 == levensteinDistance< std::string >( "euler", "eu_er" ) );
        assert( 1 == levensteinDistance< std::string >( "euler", "eul_r" ) );
        assert( 1 == levensteinDistance< std::string >( "euler", "eule_" ) );
    }

    void levensteinDistance_test_3(){
        assert( 2 == levensteinDistance< std::string >( "c++", "c++++" ) );
        assert( 2 == levensteinDistance< std::string >( "c++", "++c++" ) );

        assert( 2 == levensteinDistance< std::string >( "c++", "c" ) );
        assert( 2 == levensteinDistance< std::string >( "c++", "+" ) );

        assert( 2 == levensteinDistance< std::string >( "c++", "c__" ) );
        assert( 2 == levensteinDistance< std::string >( "c++", "_+_" ) );
        assert( 2 == levensteinDistance< std::string >( "c++", "__+" ) );
    }

    void levensteinDistance_test_4(){
        assert( 3 == levensteinDistance< std::string >( "c++", "___" ) );
        assert( 3 == levensteinDistance< std::string >( "Levenshtein", "Le_ensteins" ) );
    }
}

int main( int argc, char* argv[] ){
    test::levensteinDistance_test_1();
    test::levensteinDistance_test_2();
    test::levensteinDistance_test_3();
    test::levensteinDistance_test_4();

    if( argc != 3 ){
        std::cerr << "Usage " << argv[0] << " word word\n";
        return 1;
    }

    std::cout << levensteinDistance< std::string >( argv[1], argv[2] ) << std::endl;
}

