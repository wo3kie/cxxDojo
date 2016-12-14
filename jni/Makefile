include ../common.mk

JAVAC=javac
CXXFLAGS += -I/usr/lib/jvm/java-8-openjdk-amd64/include
LDLIBS += -L/usr/lib/jvm/java-8-openjdk-amd64/jre/lib/amd64/server -ljvm

all: Main.class main

Main.class: Main.java
	$(JAVAC) Main.java

main: main.cpp
	$(CXX) $< -o $@ $(CXXFLAGS) $(LDLIBS)

clean:
	rm -rf main Main.class *.gch
