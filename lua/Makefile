include ../common.mk

CXXFLAGS += -I /usr/include/lua5.2

LDLIBS += /usr/local/lib/liblua.so -ldl

all: main

main: main.cpp
	$(CXX) $< -o $@ $(CXXFLAGS) $(LDLIBS)

clean:
	rm -rf main *.gch
