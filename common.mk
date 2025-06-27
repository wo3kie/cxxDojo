CXX=g++

SRCS=$(shell ls *.cpp)
APPS=$(subst .cpp,,$(SRCS))

CXXFLAGS=--std=c++20 -O0 -g

LDLIBS=-L/usr/lib/x86_64-linux-gnu/ \
	-lboost_system -lboost_date_time -lboost_filesystem -lboost_iostreams \
	-pthread 
