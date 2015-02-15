.PHONY: all

CXXFLAGS := -Wall -pedantic -std=c++11 -lbenchmark -lpthread

all: benchmark

benchmark: StockExchange.o Trade.o ListStockExchange.o ByteArrayTrade.o ByteArrayStockExchange.o main.o
	g++ $^ -O3 -flto -o benchmark.out $(CXXFLAGS)
	
%.o: src/%.cpp
	g++ -c -O3 -flto -o $@ $? $(CXXFLAGS)	

remake: clean all

clean:
	rm *.o *.out *.a

memory-leak-check:
	valgrind --leak-check=full ./benchmark.out > out.txt 2>&1
