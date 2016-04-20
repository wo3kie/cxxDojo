include ../common.mk

LDLIBS += /usr/local/lib/liblua.a -ldl

all: main

main: main.cpp
	$(CXX) $< -o $@ $(CXXFLAGS) $(LDLIBS)

clean:
	rm -rf main *.gch
