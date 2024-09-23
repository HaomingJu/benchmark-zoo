project(002-benchmark-logs)

find_package(PkgConfig REQUIRED)

# Dep spdlog
pkg_search_module(SPDLOG REQUIRED IMPORTED_TARGET GLOBAL spdlog>=1.5.0)
if(NOT SPDLOG_FOUND)
    message(FATAL_ERROR "Please check libspdlog-dev, Suggest to run `sudo apt install libspdlog-dev`")
endif()
include_directories(${SPDLOG_INCLUDE_DIRS})

# Dep glog
pkg_search_module(GLOG REQUIRED IMPORTED_TARGET GLOBAL libglog>=0.4.0)
if(NOT GLOG_FOUND)
    message(FATAL_ERROR "Please check libgoogle-glog-dev, Suggest to run `sudo apt install libgoogle-glog-dev`")
endif()
include_directories(${GLOG_INCLUDE_DIRS})

file(GLOB_RECURSE SRCS_LIST *.cc)

add_executable(${PROJECT_NAME} ${SRCS_LIST})

target_link_libraries(${PROJECT_NAME} 
    PkgConfig::BENCHMARK
    PkgConfig::SPDLOG
    PkgConfig::GLOG)

install(TARGETS ${PROJECT_NAME} LIBRARY DESTINATION install/zoom)
