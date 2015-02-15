#include <iostream>
#include <benchmark/benchmark.h>
#include "StockExchange.cpp"
#include "ListStockExchange.cpp"
#include "ByteArrayStockExchange.cpp"

#define TRADES_PER_DAY 50000000

static void perform_operations(StockExchange& exchange){
	for (int i = 0; i < TRADES_PER_DAY; i++) {
      exchange.order(i, i, i, (i & 1) == 0);
    }
    exchange.dayBalance();
}

static void BM_List(benchmark::State& state) {
	while (state.KeepRunning()){
		ListStockExchange exchange;
	    perform_operations(exchange);
	}
}
BENCHMARK(BM_List);

static void BM_ByteBuffer(benchmark::State& state) {
	while (state.KeepRunning()){
		ByteArrayStockExchange exchange;
	    perform_operations(exchange);
	}
}
BENCHMARK(BM_ByteBuffer);


int main(int argc, const char* argv[]) {
  benchmark::Initialize(&argc, argv);
  benchmark::RunSpecifiedBenchmarks();
  return 0;
}
