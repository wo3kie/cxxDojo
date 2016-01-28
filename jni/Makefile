CXX=g++
JAVAC=javac

CXXFLAGS=--std=c++11 -g
INC=-I/usr/lib/jvm/java-7-openjdk-amd64/include
LIB=-L/usr/lib/jvm/java-7-openjdk-amd64/jre/lib/amd64/server
LDLIBS=$(LIB) -ljvm

all: Main.class main

Main.class: Main.java
	$(JAVAC) Main.java

main: main.cpp
	$(CXX) $< -o main $(CXXFLAGS) $(INC) $(LIBS) $(LDLIBS)

clean:
	rm -rf main Main.class

