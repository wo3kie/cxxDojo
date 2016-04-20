include ../common.mk

SRCS=$(shell ls *.cpp)
APPS=$(subst .cpp,,$(SRCS))
CXXFLAGS += -I..
LDLIBS += -lgsl -lgslcblas -lm

all: $(APPS)

%: %.cpp
	$(CXX) $< -o $@ $(CXXFLAGS) $(LDLIBS)

clean:
	rm -rf $(APPS) *.gch
