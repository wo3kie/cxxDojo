ERR=$(shell which clang++ >/dev/null; echo $$?) 
ifeq "$(ERR)" "0" 
	CXX=clang++
else 
	CXX=g++ 
endif 


CPP_FILES=$(shell ls *.cpp)
APPS=$(subst .cpp,,$(CPP_FILES))

CC=$(CXX)
INC=-I/usr/include/libxml2
LIB=-Lusr/lib/x86_64-linux-gnu/
CXXFLAGS=$(INC) --std=c++11 -g
LDLIBS=$(LIB) -lboost_system -lboost_thread -pthread -lxml2

all: $(APPS)

%: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@ $(LDLIBS)

clean:
	rm -rf $(APPS)

