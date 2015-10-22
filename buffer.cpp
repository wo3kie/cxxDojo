/*
 * Website:
 *      https://github.com/wo3kie/dojo
 *
 *  Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++11 buffer.cpp -o buffer -pthread
 *
 *  Usage:
 *      $ ./buffer
 *      OK
 */

#include <cassert>
#include <condition_variable>
#include <iostream>
#include <mutex>
#include <queue>
#include <thread>

template< typename T >
class Buffer
{
public:

    Buffer( unsigned capacity = -1 )
        : m_capacity( capacity )
        , m_size( 0 )
    {
    }

    void push( T const & t )
    {
        std::unique_lock< std::mutex > lock( m_mutex );

        m_notFull.wait(
            lock,
            [ this ](){ return m_size + 1 < m_capacity; }
        );

        m_queue.push( t );
        m_size += 1;

        m_notEmpty.notify_one();
    }

    T get()
    {
        std::unique_lock< std::mutex > lock( m_mutex );

        m_notEmpty.wait(
            lock,
            [ this ](){ return m_size > 0; }
        );

        m_size -= 1;
        T t = m_queue.front();
        m_queue.pop();

        m_notFull.notify_one();

        return t;
    }

private:
    std::mutex m_mutex;

    std::condition_variable m_notFull;
    std::condition_variable m_notEmpty;

    unsigned m_size;
    unsigned m_capacity;
    std::queue< T > m_queue;
};

void producer( Buffer< int > & buffer )
{
    for( int i = 0 ; i < 1000 ; ++ i ){
        buffer.push( i );
    }
}

void consumer( Buffer< int > & buffer )
{
    int sum = 0;

    for( int i = 0 ; i < 1000 ; ++ i ){
        sum += buffer.get();
    }

    assert( sum == ( 0 + 999 ) * ( 1000 / 2 ) );

    std::cout << "OK" << std::endl;
}

int main()
{
    Buffer< int > buffer( 100 );

    std::thread p( & producer, std::ref( buffer ) );
    std::thread c( & consumer, std::ref( buffer ) );

    c.join();
    p.join();

    return 0;
}

