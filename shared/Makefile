CXX=g++ 

all: libshared.so main

main: main.cpp
	g++ --std=c++11 -g3 -c main.cpp -o main.o
	g++ --std=c++11 -g3 main.o -o main -L. -lshared -ldl

libshared.so: shared.cpp shared.h
	g++ -g3 -fpic -c shared.cpp -o shared.o
	g++ -g3 -shared shared.o -o libshared.so

clean:
	rm -rf main libshared.so *.o

