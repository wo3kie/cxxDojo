ERR=$(shell which clang++ >/dev/null; echo $$?) 
ifeq "$(ERR)" "0" 
	CXX=clang++ 
else 
	CXX=g++ 
endif 

CPP_FILES=$(shell ls *.cpp)
APPS=$(subst .cpp,,$(CPP_FILES))

CC=$(CXX)
CXXFLAGS=--std=c++11 -g
LDLIBS=-lboost_system -lboost_thread -pthread

all: $(APPS)

%: %.cpp
	$(CXX) $(CXXFLAGS) $< -o $@ $(LDLIBS)

clean:
	rm -rf $(APPS)

