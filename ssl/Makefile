include ../common.mk

SRCS=$(shell ls *.cpp)
APPS=$(subst .cpp,,$(SRCS))
CXXFLAGS += -I..
LDLIBS += -lssl -lcrypto

all: $(APPS)

%: %.cpp
	$(CXX) $< -o $@ $(CXXFLAGS) $(LDLIBS)

clean:
	rm -rf $(APPS) *.gch
