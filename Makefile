include common.mk

all: $(APPS)
	#$(MAKE) -C gsl
	#$(MAKE) -C ssl
	#$(MAKE) -C xml

%: %.cpp
	$(CXX) $< -o $@ $(CXXFLAGS) $(LDLIBS)

co_await: co_await.cpp
co_yield: co_yield.cpp
co_transform: co_transform.cpp
co_iter: co_iter.cpp
	$(CXX) $< -o $@ -fcoroutines $(CXXFLAGS) $(LDLIBS)

clean:
	rm -rf $(APPS) *.gch
	#$(MAKE) -C gsl clean
	#$(MAKE) -C ssl clean
	#$(MAKE) -C xml clean

