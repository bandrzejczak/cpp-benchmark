.PHONY: all

CXXFLAGS := -Wall -pedantic -std=c++11 -lbenchmark -lpthread

all: benchmark

benchmark: Trade.o ListStockExchange.o MallocTrade.o  MallocStockExchange.o main.o
	g++ $^ -o benchmark.out $(CXXFLAGS)
	
%.o: src/%.cpp
	g++ -c -o $@ $? $(CXXFLAGS)	

remake: clean all

clean:
	rm *.o *.out *.a

memory-leak-check:
	valgrind --leak-check=full ./benchmark.out > out.txt 2>&1