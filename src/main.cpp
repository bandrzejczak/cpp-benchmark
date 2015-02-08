#include <iostream>
#include <benchmark/benchmark.h>
#include "ListStockExchange.cpp"
#include "MallocStockExchange.cpp"

#define TRADES_PER_DAY 50000000

static void BM_List(benchmark::State& state) {
	ListStockExchange * exchange;
	while (state.KeepRunning()){    
		exchange = new ListStockExchange();
	    for (int i = 0; i < TRADES_PER_DAY; i++) {
	      exchange->order(i, i, i, (i & 1) == 0);
	    }
	    exchange->dayBalance();
	    delete exchange;
	}
}
BENCHMARK(BM_List);

static void BM_Malloc(benchmark::State& state) {
	while (state.KeepRunning()){    
		MallocStockExchange exchange;
	    for (int i = 0; i < TRADES_PER_DAY; i++) {
	      exchange.order(i, i, i, (i & 1) == 0);
	    }
	    exchange.dayBalance();
	}
}
BENCHMARK(BM_Malloc);


int main(int argc, const char* argv[]) {
  benchmark::Initialize(&argc, argv);
  benchmark::RunSpecifiedBenchmarks();
  return 0;
}