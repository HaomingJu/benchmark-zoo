#include <benchmark/benchmark.h>

#include <Person.pb.h>
#include <SearchRequest.pb.h>

#include <memory> // for std::make_shared

static void BM_protobuf_obj(benchmark::State &state) {
  for (auto _ : state) {
    Person p;
    p.set_name("ZhangSan");
    p.set_age(8);
  }
}

static void BM_protobuf_smart_ptr(benchmark::State &state) {
  for (auto _ : state) {
    auto p = std::make_shared<Person>();
    p->set_name("ZhangSan");
    p->set_age(8);
  }
}

static void BM_protobuf_obj_repeated(benchmark::State &state) {
  SearchRequest sr;
  for (auto _ : state) {
    sr.add_page_number(32);
    sr.add_query("GOD IS LOVE");
  }
}

static void BM_protobuf_smart_ptr_repeated(benchmark::State &state) {
  auto srPtr = std::make_shared<SearchRequest>();
  for (auto _ : state) {
    srPtr->add_page_number(32);
    srPtr->add_query("GOD IS LOVE");
  }
}

#include <google/protobuf/arena.h>
static void BM_protobuf_smart_ptr_repeated_arena(benchmark::State &state) {
  google::protobuf::Arena arena;
  auto srPtr = google::protobuf::Arena::CreateMessage<SearchRequest>(&arena);
  for (auto _ : state) {
    srPtr->add_page_number(32);
    srPtr->add_query("GOD IS LOVE");
  }
}

BENCHMARK(BM_protobuf_obj);
BENCHMARK(BM_protobuf_smart_ptr);
BENCHMARK(BM_protobuf_obj_repeated);
BENCHMARK(BM_protobuf_smart_ptr_repeated);
BENCHMARK(BM_protobuf_smart_ptr_repeated_arena);

BENCHMARK_MAIN();

/*
 * 参考BM_protobuf_obj_repeated和BM_protobuf_smart_ptr_repeated可知如下结论
 * protobuf性能瓶颈在于repeated类型的字段的多次调用add_*函数导致小内存不断创建,移动,销毁
 * 在使用arena接管Protobuf对象的内存管理后，由arena统一管理内存可提高add_*函数的速度
 */
