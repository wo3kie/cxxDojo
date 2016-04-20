include common.mk

all: $(APPS)
	$(MAKE) -C gsl
	$(MAKE) -C jni
	$(MAKE) -C lua
	$(MAKE) -C shared
	$(MAKE) -C ssl
	$(MAKE) -C xml

%: %.cpp
	$(CXX) $< -o $@ $(CXXFLAGS) $(LDLIBS)

clean:
	rm -rf $(APPS) *.gch
	$(MAKE) -C gsl clean
	$(MAKE) -C jni clean
	$(MAKE) -C lua clean
	$(MAKE) -C shared clean
	$(MAKE) -C ssl clean
	$(MAKE) -C xml clean
