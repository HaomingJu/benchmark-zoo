cmake_minimum_required(VERSION 3.20)
project(benchmark-zoo)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_POSITION_INDEPENDENT_CODE ON)
set(CMAKE_INSTALL_PREFIX ${CMAKE_SOURCE_DIR}/install)

if(NOT CMAKE_BUILD_TYPE)
    set(CMAKE_BUILD_TYPE Release)
endif()

if(${CMAKE_BUILD_TYPE} STREQUAL "Release")
    list(APPEND CMAKE_CXX_FLAGS -O3)
    message(STATUS "Release Mode: append CMAKE_CXX_FLAGS -O3")
else()
    list(APPEND CMAKE_CXX_FLAGS -O1)
    message(STATUS "Debug Mode: append CMAKE_CXX_FLAGS -O1")
endif()

find_package(PkgConfig REQUIRED)

# libs: benchmark
pkg_search_module(BENCHMARK REQUIRED IMPORTED_TARGET GLOBAL benchmark)
if(NOT BENCHMARK_FOUND)
    message(FATAL_ERROR "Please check benchmark, Suggest to run `sudo apt install libbenchmark-dev`")
endif()
include_directories(${BENCHMARK_INCLUDE_DIRS})


add_subdirectory(zoom/001-benchmark-normal-use)
add_subdirectory(zoom/002-benchmark-logs)
