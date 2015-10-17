/*
 * Website:
 *      https://github.com/wo3kie/dojo
 *
 *  Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++11 bloom.cpp -o bloom
 *
 *  Usage:
 *      $ ./bloom
 */

#include <cassert>
#include <functional>
#include <iostream>
#include <string>
#include <vector>

template< typename T >
class Bloom
{
public:
    enum
    {
        None = 0,
        Maybe = 1
    };

    typedef std::function< int ( T const & ) noexcept > Filter;

public:
    Bloom( unsigned numberOfBits = 1024 )
        : m_bits( numberOfBits )
    {
    }

    ~Bloom() = default;

    Bloom( Bloom const & ) = default;
    Bloom( Bloom && ) = default;

    Bloom & operator=( Bloom const & ) = default;
    Bloom & operator=( Bloom && ) = default;

    void addFilter( Filter const & f )
    {
        m_filters.push_back( f );
    }

    template< typename Filter_ >
    void addFilter( Filter_ && f )
    {
        m_filters.emplace_back( std::forward< Filter_ >( f ) );
    }

    void insert( T const & t ) noexcept
    {
        for( Filter const & filter : m_filters )
        {
            unsigned const bit = filter( t ) % m_bits.size();
            m_bits[ bit ] = true;
        }
    }

    int find( T const & t ) const noexcept
    {
        for( Filter const & filter : m_filters )
        {
            unsigned const bit = filter( t ) % m_bits.size();
            if( m_bits[ bit ] == false ){
                return None;
            }
        }

        return Maybe;
    }

    void clear() noexcept
    {
        m_bits.clear();
        m_filters.clear();
    }

    bool empty() const noexcept
    {
        return
            m_bits.empty() && m_filters.empty();
    }

    void swap( Bloom & other )
    {
        std::swap( m_bits, other.m_bits );
        std::swap( m_filters, other.m_filters );
    }

private:
    std::vector< bool > m_bits;
    std::vector< Filter > m_filters;
};

int main()
{
    Bloom< std::string > bloom( 32 );

    auto hash1 = []( std::string const & s ) noexcept
    {
        int result = 0;

        for( char c : s ){
            result += c;
        }

        return result;
    };
    
    auto hash2 = []( std::string const & s ) noexcept
    {
        int result = 0;

        for( unsigned i = 0; i < s.size(); ++i ){
            result += (i * s[i]);
        }

        return result;
    };

    auto hash3 = []( std::string const & s ) noexcept
    {
        return std::hash< std::string >()( s );
    };

    bloom.addFilter( hash1 );
    bloom.addFilter( hash2 );
    bloom.addFilter( hash3 );

    bloom.insert( "c++" );
    bloom.insert( "python" );
    bloom.insert( "haskell" );

    assert( bloom.find( "c++" ) == Bloom< std::string >::Maybe );
    assert( bloom.find( "python" ) == Bloom< std::string >::Maybe );
    assert( bloom.find( "haskell" ) == Bloom< std::string >::Maybe );

    assert( bloom.find( "java" ) == Bloom< std::string >::None );
    assert( bloom.find( "c#" ) == Bloom< std::string >::None );
    assert( bloom.find( "perl" ) == Bloom< std::string >::None );
}

