ERR=$(shell which clang++ >/dev/null; echo $$?) 
ifeq "$(ERR)" "0" 
	CXX=clang++
else 
	CXX=g++ 
endif 


SRCS=$(shell ls *.cpp)
APPS=$(subst .cpp,,$(SRCS))

CC=$(CXX)
INC=-I/usr/include/libxml2
LIB=-Lusr/lib/x86_64-linux-gnu/
CXXFLAGS=$(INC) --std=c++11 -g
LDLIBS=$(LIB) -lboost_system -lboost_date_time -pthread -lxml2 -lssl -lcrypto

all: $(APPS)

%: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@ $(LDLIBS)

clean:
	rm -rf $(APPS)

