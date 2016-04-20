include ../common.mk

SRCS=$(shell ls *.cpp)
APPS=$(subst .cpp,,$(SRCS))
CXXFLAGS += -I.. -I/usr/include/libxml2
LDLIBS += -lxml2

all: $(APPS)

%: %.cpp
	$(CXX) $< -o $@ $(CXXFLAGS) $(LDLIBS)

clean:
	rm -rf $(APPS) *.gch
