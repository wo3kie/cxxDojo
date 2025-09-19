include common.mk

all: $(APPS)
	#$(MAKE) -C gsl

%: %.cpp
	$(CXX) $< -o $@ $(CXXFLAGS) $(LDLIBS)

clean:
	rm -rf $(APPS) *.gch
	#$(MAKE) -C gsl clean

