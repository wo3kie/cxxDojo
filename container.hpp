/*
 * Website:
 *      https://github.com/wo3kie/dojo
 *
 * Author:
 *      Lukasz Czerwinski
 */

#ifndef CXX_DOJO_CONTAINER_HPP
#define CXX_DOJO_CONTAINER_HPP

#include <vector>
#include <list>

template<typename Iterator>
struct Container{
    Container(Iterator begin, Iterator end)
        : begin_(begin)
        , end_(end)
    {
    }

    Iterator begin() { return begin_; }
    Iterator begin() const { return begin_; }

    Iterator end() { return end_; }
    Iterator end() const { return end_; }

    Iterator cbegin() { return begin_; }
    Iterator cbegin() const { return begin_; }

    Iterator cend() { return end_; }
    Iterator cend() const { return end_; }
    
    Iterator begin_;
    Iterator end_;
};

template<typename Container>
struct ContainerTraits {

};

template<typename T>
struct ContainerTraits<std::vector<T>> {
    typedef T value_type;

    template<typename U>
    struct rebind {
        typedef std::vector<U> type;
    };
};

template<typename T>
struct ContainerTraits<std::list<T>> {
    typedef T value_type;

    template<typename U>
    struct rebind {
        typedef std::list<U> type;
    };
};

// TODO...

template<typename T>
std::vector<T> & insert(std::vector<T> & container, T const & item){
    container.push_back(item);
    return container;
}

template<typename T>
std::list<T> & insert(std::list<T> & container, T const & item){
    container.push_back(item);
    return container;
}

// TODO...

#endif
