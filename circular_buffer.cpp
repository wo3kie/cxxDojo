/*
 * Website:
 *      https://github.com/wo3kie/dojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++11 circular_buffer.cpp -o circular_buffer
 *
 * Usage:
 *      $ ./circular_buffer
 */

#include <cassert>
#include <iostream>
#include <exception>
#include <tuple>

template<typename T, int Size>
struct CircularBuffer {
    static_assert(Size > 0, ":(");

    T data_[Size];
    int end_ = 0;
    int size_ = 0;

    void push(T const & t){
        data_[end_] = t;

        end_ = (end_ + 1) % Size;
        size_ = std::min(size_ + 1, Size);
    }

    T get(){
        if(size_ == 0){
            throw std::out_of_range(":(");
        }

        int head = end_ - size_;
        
        if(head < 0){
            head = Size + head;
        }

        T const result = data_[head];
        size_ -= 1;

        return result;
    }
};

template<typename T, int Size>
std::ostream & operator<<(std::ostream & out, CircularBuffer<T, Size> const & buffer){
    out << "{E: " << buffer.end_ << ", " << "S: " << buffer.size_ << " [";

    for(int i = 0; i < Size; ++i){
        out << " " << buffer.data_[i];
    }

    return out << "]}";
}

int main(){
    {
        CircularBuffer<int, 4> cb;
        cb.push(1);
        assert(cb.get() == 1);
    }
    {
        CircularBuffer<int, 4> cb;
        cb.push(1);
        cb.push(2);
        assert(cb.get() == 1);
        assert(cb.get() == 2);
    }
    {
        CircularBuffer<int, 4> cb;
        cb.push(1);
        cb.push(2);
        cb.push(3);
        assert(cb.get() == 1);
        assert(cb.get() == 2);
        assert(cb.get() == 3);
    }
    {
        CircularBuffer<int, 4> cb;
        cb.push(1);
        cb.push(2);
        cb.push(3);
        cb.push(4);
        assert(cb.get() == 1);
        assert(cb.get() == 2);
        assert(cb.get() == 3);
        assert(cb.get() == 4);
    }
    {
        CircularBuffer<int, 4> cb;
        cb.push(1);
        cb.push(2);
        cb.push(3);
        cb.push(4);
        cb.push(5);
        assert(cb.get() == 2);
        assert(cb.get() == 3);
        assert(cb.get() == 4);
        assert(cb.get() == 5);
    }
    {
        CircularBuffer<int, 4> cb;
        cb.push(1);
        cb.push(2);
        cb.push(3);
        cb.push(4);
        cb.push(5);
        cb.push(6);
        assert(cb.get() == 3);
        assert(cb.get() == 4);
        assert(cb.get() == 5);
        assert(cb.get() == 6);
    }
    {
        CircularBuffer<int, 4> cb;
        cb.push(1);
        cb.push(2);
        cb.push(3);
        cb.push(4);
        cb.push(5);
        cb.push(6);
        cb.push(7);
        assert(cb.get() == 4);
        assert(cb.get() == 5);
        assert(cb.get() == 6);
        assert(cb.get() == 7);
    }
    {
        CircularBuffer<int, 4> cb;
        cb.push(1);
        cb.push(2);
        cb.push(3);
        cb.push(4);
        cb.push(5);
        cb.push(6);
        cb.push(7);
        cb.push(8);
        assert(cb.get() == 5);
        assert(cb.get() == 6);
        assert(cb.get() == 7);
        assert(cb.get() == 8);
    }
    {
        CircularBuffer<int, 4> cb;
        cb.push(1);               // [1, , , ]
        cb.push(2);               // [1,2, , ]
        assert(cb.get() == 1);    // [ ,2, , ]
        cb.push(3);               // [ ,2,3, ]
        cb.push(4);               // [ ,2,3,4]
        assert(cb.get() == 2);    // [ , ,3,4]
        cb.push(5);               // [5, ,3,4]
        cb.push(6);               // [5,6,3,4]
        assert(cb.get() == 3);    // [5,6, ,4]
        cb.push(7);               // [5,6,7,4]
        cb.push(8);               // [5,6,7,8]
        assert(cb.get() == 5);    // [ ,6,7,8]
    }
}

