/*
 * Website:
 *      https://github.com/wo3kie/dojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++11 output.cpp -o output
 *
 * Usage:
 *      $ ./output
 */

#include <cassert>
#include <array>
#include <iostream>
#include <list>
#include <map>
#include <set>
#include <sstream>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

template< typename Iterator >
std::ostream & printImpl(
    std::ostream & out,
    char const beginning,
    Iterator begin,
    char const separator,
    Iterator const end,
    char const ending
){
    out << beginning;

    if( begin != end ){
        out << * begin;
        
        while( ++ begin != end ){
            out << separator << * begin;
        }
    }

    return out << ending;
}

template< typename Iterator >
std::ostream & printVector( std::ostream & out, Iterator begin, Iterator end ){
    return printImpl( out, '[', begin, ',', end, ']' );
}

template< typename T >
std::ostream & operator<<( std::ostream & out, std::vector< T > const & v ){
    return printVector( out, v.begin(), v.end() );
}

template< typename T, std::size_t Size >
std::ostream & operator<<( std::ostream & out, std::array< T, Size > const & a ){
    return printVector( out, a.begin(), a.end() );
}

template< typename Iterator >
std::ostream & printList( std::ostream & out, Iterator begin, Iterator end ){
    return printImpl( out, '(', begin, ',', end, ')' );
}

template< typename T >
std::ostream & operator<<( std::ostream & out, std::list< T > const & v ){
    return printList( out, v.begin(), v.end() );
}

template< typename T1, typename T2 >
std::ostream & printPair( std::ostream & out, std::pair< T1, T2 > const & p ){
    return out << '{' << p.first << ',' << p.second << '}';
}

template< typename T1, typename T2 >
std::ostream & operator<<( std::ostream & out, std::pair< T1, T2 > const & p ){
    return printPair( out, p );    
}

template< typename Iterator >
std::ostream & printMap( std::ostream & out, Iterator begin, Iterator end ){
    return printImpl( out, '{', begin, ',', end, '}' );
}

template< typename T1, typename T2 >
std::ostream & operator<<( std::ostream & out, std::map< T1, T2 > const & m ){
    return printMap( out, m.begin(), m.end() );
}

template< typename Iterator >
std::ostream & printSet( std::ostream & out, Iterator begin, Iterator end ){
    return printImpl( out, '{', begin, ',', end, '}' );
}

template< typename T >
std::ostream & operator<<( std::ostream & out, std::set< T > const & s ){
    return printSet( out, s.begin(), s.end() );
}

template< typename T1, typename T2 >
std::ostream & operator<<( std::ostream & out, std::unordered_map< T1, T2 > const & u ){
    return printMap( out, u.begin(), u.end() );
}

template< typename T >
std::ostream & operator<<( std::ostream & out, std::unordered_set< T > const & s ){
    return printSet( out, s.begin(), s.end() );
}

int main()
{
    {
        std::ostringstream oss; oss << std::vector< int >();
        assert( std::string( "[]" ) == oss.str() );
    }
    {
        std::ostringstream oss; oss << std::vector< int >{ 1 };
        assert( std::string( "[1]" ) == oss.str() );
    }
    {
        std::ostringstream oss; oss << std::vector< int >{ 1, 2 };
        assert( std::string( "[1,2]" ) == oss.str() );
    }
    {
        std::ostringstream oss; oss << std::vector< int >{ 1, 2, 3 };
        assert( std::string( "[1,2,3]" ) == oss.str() );
    }

    {
        std::ostringstream oss; oss << std::array< int, 0 >();
        assert( std::string( "[]" ) == oss.str() );
    }
    {
        std::ostringstream oss; oss << std::array< int, 1 >{ 1 };
        assert( std::string( "[1]" ) == oss.str() );
    }
    {
        std::ostringstream oss; oss << std::array< int, 2 >{ 1, 2 };
        assert( std::string( "[1,2]" ) == oss.str() );
    }
    {
        std::ostringstream oss; oss << std::array< int, 3 >{ 1, 2, 3 };
        assert( std::string( "[1,2,3]" ) == oss.str() );
    }

    {
        std::ostringstream oss; oss << std::list< int >();
        assert( std::string( "()" ) == oss.str() );
    }
    {
        std::ostringstream oss; oss << std::list< int >{ 1 };
        assert( std::string( "(1)" ) == oss.str() );
    }
    {
        std::ostringstream oss; oss << std::list< int >{ 1, 2 };
        assert( std::string( "(1,2)" ) == oss.str() );
    }
    {
        std::ostringstream oss; oss << std::list< int >{ 1, 2, 3 };
        assert( std::string( "(1,2,3)" ) == oss.str() );
    }

    {
        std::ostringstream oss; oss << std::make_pair( 1, 2 );
        assert( std::string( "{1,2}" ) == oss.str() );
    }

    {
        std::ostringstream oss; oss << std::map< int, int >();
        assert( std::string( "{}" ) == oss.str() );
    }
    {
        std::ostringstream oss; oss << std::map< int, int >{ { 1 , 2 } };
        assert( std::string( "{{1,2}}" ) == oss.str() );
    }
    {
        std::ostringstream oss; oss << std::map< int, int >{ { 1 , 2 }, { 3, 4 } };
        assert( std::string( "{{1,2},{3,4}}" ) == oss.str() );
    }
    {
        std::ostringstream oss; oss << std::map< int, int >{ { 1 , 2 }, { 3, 4 }, { 5, 6 } };
        assert( std::string( "{{1,2},{3,4},{5,6}}" ) == oss.str() );
    }

    {
        std::ostringstream oss; oss << std::set< int >();
        assert( std::string( "{}" ) == oss.str() );
    }
    {
        std::ostringstream oss; oss << std::set< int >{ 1 };
        assert( std::string( "{1}" ) == oss.str() );
    }
    {
        std::ostringstream oss; oss << std::set< int >{ 1, 2 };
        assert( std::string( "{1,2}" ) == oss.str() );
    }
    {
        std::ostringstream oss; oss << std::set< int >{ 1, 2, 3 };
        assert( std::string( "{1,2,3}" ) == oss.str() );
    }

    {
        std::ostringstream oss; oss << std::unordered_map< int, int >();
        assert( std::string( "{}" ) == oss.str() );
    }
    {
        std::ostringstream oss; oss << std::unordered_map< int, int >{ { 1 , 2 } };
        assert( std::string( "{{1,2}}" ) == oss.str() );
    }

    {
        std::ostringstream oss; oss << std::unordered_set< int >();
        assert( std::string( "{}" ) == oss.str() );
    }
    {
        std::ostringstream oss; oss << std::unordered_set< int >{ 1 };
        assert( std::string( "{1}" ) == oss.str() );
    }
}

