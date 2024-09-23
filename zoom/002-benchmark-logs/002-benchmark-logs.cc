#include <benchmark/benchmark.h>

#include <cstdio>          // for printf
#include <glog/logging.h>  // for glog
#include <iostream>        // for std::cout
#include <spdlog/spdlog.h> // for spdlog

static void BM_printf(benchmark::State &state) {
  char ch = 'A';
  int i = 1977;
  for (auto _ : state) {
    printf("test printf %c, %d\n", ch, i);
    //printf("This is test @ jian\n");
  }
}

static void BM_cout(benchmark::State &state) {
  char ch = 'A';
  int i = 1977;
  for (auto _ : state) {
    std::cout << "test cout " << ch << i << std::endl;
    //std::cout << "This is test @ jian" << std::endl;
  }
}

static void BM_spdlog(benchmark::State &state) {
  char ch = 'A';
  int i = 1977;
  for (auto _ : state) {
    spdlog::info("test spdlog %c, %d\n", ch, i);
    //spdlog::info("This is test @ jian");
  }
}

static void BM_glog(benchmark::State &state) {
  char ch = 'A';
  int i = 1977;
  for (auto _ : state) {
    LOG(INFO) << "test glog " << ch << i;
    //LOG(INFO) << "This is test @ jian";
  }
}

BENCHMARK(BM_printf);
BENCHMARK(BM_cout);
BENCHMARK(BM_spdlog);
BENCHMARK(BM_glog);

BENCHMARK_MAIN();
