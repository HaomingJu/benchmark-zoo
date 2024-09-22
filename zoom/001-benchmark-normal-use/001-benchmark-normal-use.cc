/*
 * 测试vector的push_back和emplace_back的耗时差异
 */

#include <benchmark/benchmark.h>
#include <vector>

struct ELE_TYPE {
  int i = 0;
  double j = 0.0;
  ELE_TYPE(int i_, double j_) : i(i_), j(j_) {}
};

static void BM_vector_push_back(benchmark::State &state) {
  std::vector<ELE_TYPE> vec_;
  for (auto _ : state) {
    vec_.push_back({1, 2.2});
  }
}

static void BM_vector_emplace_back(benchmark::State &state) {
  std::vector<ELE_TYPE> vec_;
  for (auto _ : state) {
    vec_.emplace_back(1, 2.2);
  }
}

// Register the function as a benchmark
BENCHMARK(BM_vector_push_back);
BENCHMARK(BM_vector_emplace_back);

// Run the benchmark
BENCHMARK_MAIN();
