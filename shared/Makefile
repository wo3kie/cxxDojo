include ../common.mk

all: libshared.so main

main.o: main.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGS)

main: main.o
	$(CXX) $(CXXFLAGS) $< -o $@ -L. -ldl -lshared

shared.o: shared.cpp
	$(CXX) -c $< -o $@ $(CXXFLAGS) -fpic

libshared.so: shared.o
	$(CXX) $< -o $@ $(CXXFLAGS) -shared

clean:
	rm -rf main libshared.so *.o *.gch
