include common.mk

all: $(APPS)
	$(MAKE) -C shared
	$(MAKE) -C jni
	$(MAKE) -C lua

%: %.cpp
	$(CXX) $< -o $@ $(CXXFLAGS) $(INC) $(LIBS) $(LDLIBS)

clean:
	rm -rf $(APPS) *.gch
	$(MAKE) -C shared clean
	$(MAKE) -C jni clean
	$(MAKE) -C lua clean
