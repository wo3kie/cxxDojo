CXX=g++ 

SRCS=$(shell ls *.cpp)
APPS=$(subst .cpp,,$(SRCS))

CXXFLAGS=--std=c++11 -g
INC=-I/usr/include/libxml2

LIB=-L/usr/lib/x86_64-linux-gnu/
LDLIBS=$(LIB) -lboost_system -lboost_date_time -lboost_filesystem -lboost_iostreams \
	-pthread -lxml2 -lssl -lcrypto

all: $(APPS)
	$(MAKE) -C shared

%: %.cpp
	$(CXX) $< -o $@ $(CXXFLAGS) $(INC) $(LIBS) $(LDLIBS)

clean:
	rm -rf $(APPS)
	$(MAKE) -C shared

