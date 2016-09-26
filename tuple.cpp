/*
 * Website:
 *      https://github.com/wo3kie/dojo
 *
 * Author:
 *      Lukasz Czerwinski
 *
 * Compilation:
 *      g++ --std=c++11 tuple.cpp -o tuple
 *
 * Usage:
 *      $ ./tuple
 */

#include <iostream>

template<typename Arg, typename ... Args>
struct Tuple
{
	Tuple(){
	}

	Tuple(Arg arg, Args... args)
		: head_(arg)
		, tail_(args...)
	{
	}

	Arg head_;
	Tuple<Args...> tail_;
};

template<typename Arg>
struct Tuple<Arg> 
{
	Tuple(){
	}

	Tuple(Arg arg)
		: head_(arg)
	{
	}

	Arg head_;
};

template<typename ... Args>
Tuple<Args...> makeTuple(Args ... args){
	return Tuple<Args...>(args...);
}

template<int I, typename Arg, typename ... Args>
struct Get
{
	auto operator()(Tuple<Arg, Args...> tuple)
	{
		return Get<I - 1, Args...>()(tuple.tail_);
	}
};

template<typename Arg, typename ... Args>
struct Get<0, Arg, Args...>
{
	Arg operator()(Tuple<Arg, Args...> tuple){
		return tuple.head_;
	}
};

template<int I, typename Arg, typename ... Args>
auto get(Tuple<Arg, Args...> tuple){
	return Get<I, Arg, Args...>()(tuple);
}

template<typename Arg, typename ... Args>
int size(Tuple<Arg, Args...> tuple){
	return 1 + sizeof...(Args);
}

#include <cassert>
#include <string>

int main(){
	auto tuple = makeTuple(0, 1.0, '2', "3");    

	assert(get<0>(tuple) == 0);
	assert(get<1>(tuple) == 1.0);
	assert(get<2>(tuple) == '2');

	using namespace std::string_literals;
	assert(get<3>(tuple) == "3"s);

	assert(size(tuple) == 4);
}

