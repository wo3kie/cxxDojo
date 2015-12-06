SRCS=$(shell ls *.cpp)
APPS=$(subst .cpp,,$(SRCS))

CXX=g++ 
INC=-I/usr/include/libxml2
LIB=-L/usr/lib/x86_64-linux-gnu/
CXXFLAGS=--std=c++11 -g $(INC)
LDLIBS=$(LIB) -lboost_system -lboost_date_time -lboost_filesystem -lboost_iostreams -pthread -lxml2 -lssl -lcrypto

all: $(APPS)

%: %.cpp
	$(CXX) $< -o $@ $(CXXFLAGS) $(LDLIBS)

clean:
	rm -rf $(APPS)

