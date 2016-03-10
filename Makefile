CXX=g++

SRCS=$(shell ls *.cpp)
APPS=$(subst .cpp,,$(SRCS))

CXXFLAGS=--std=c++14 -O1 -g
INC=-I/usr/include/libxml2

LIB=-L/usr/lib/x86_64-linux-gnu/
LDLIBS=$(LIB) -lboost_system -lboost_date_time -lboost_filesystem -lboost_iostreams \
	-pthread -lxml2 -lssl -lcrypto

all: $(APPS)
	$(MAKE) -C shared
	$(MAKE) -C jni

%: %.cpp
	$(CXX) $< -o $@ $(CXXFLAGS) $(INC) $(LIBS) $(LDLIBS)

clean:
	rm -rf $(APPS)
	$(MAKE) -C shared clean
	$(MAKE) -C jni clean

