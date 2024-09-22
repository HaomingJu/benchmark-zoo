cmake_minimum_required(VERSION 3.20)
project(benchmark-zoo)
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_INSTALL_PREFIX ${CMAKE_SOURCE_DIR}/install)

find_package(PkgConfig REQUIRED)

# libs: benchmark
pkg_search_module(BENCHMARK REQUIRED IMPORTED_TARGET GLOBAL benchmark)
if(NOT BENCHMARK_FOUND)
    message(FATAL_ERROR "Please check benchmark, Suggest to run `sudo apt install libbenchmark-dev`")
endif()
include_directories(${BENCHMARK_INCLUDE_DIRS})


#pkg_search_module(PROTOBUF REQUIRED IMPORTED_TARGET GLOBAL protobuf>=3.6)
#message(STATUS "PROTOBUF_INCLUDE_DIRS: ${PROTOBUF_INCLUDE_DIRS}")

add_subdirectory(zoom/001-benchmark-normal-use)
