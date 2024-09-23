#include <benchmark/benchmark.h>

#include <cstdio>          // for printf
#include <glog/logging.h>  // for glog
#include <iostream>        // for std::cout
#include <spdlog/spdlog.h> // for spdlog

static void BM_todo(benchmark::State &state) {
  for (auto _ : state) {
      // TODO
  }
}


BENCHMARK(BM_todo);

BENCHMARK_MAIN();
