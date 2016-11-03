include ../common.mk

SRCS=$(shell ls *.cpp)
APPS=$(subst .cpp,,$(SRCS))
CXXFLAGS += -I..
LDLIBS +=

all: $(APPS)

%: %.cpp
	$(CXX) $< -o $@ $(CXXFLAGS) $(LDLIBS)
	objdump -d -D -C -S -M intel ./$@ > $@.s

clean:
	rm -rf $(APPS) *.gch

