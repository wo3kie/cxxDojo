CXX=g++

CXXFLAGS=--std=c++11 -g
INC=-I/usr/local/include
LIBS=/usr/local/lib/liblua.a
LDLIBS=$(LIB) -ldl

all: main

main: main.cpp
	$(CXX) $< -o main $(CXXFLAGS) $(INC) $(LIBS) $(LDLIBS)

clean:
	rm -rf main

