.PHONY: all

CXXFLAGS := -Wall -pedantic -std=c++11 -lbenchmark -lpthread

all: lib

lib: main.o $^
	
%.o: src/%.cpp
	g++ -o $@ $? $(CXXFLAGS)	

remake: clean all

clean:
	rm *.o *.out *.a
