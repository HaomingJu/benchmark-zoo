project(003-benchmark-protobuf)

find_package(PkgConfig REQUIRED)

# Dep protobuf
pkg_search_module(PROTOBUF REQUIRED IMPORTED_TARGET GLOBAL protobuf>=3.6.1)
if(NOT PROTOBUF_FOUND)
    message(FATAL_ERROR "Please check libprotobuf-dev, Suggest to run `sudo apt install libprotobuf-dev`")
endif()

file(GLOB_RECURSE SRCS_LIST *.cc)

add_executable(${PROJECT_NAME} ${SRCS_LIST})
target_include_directories(${PROJECT_NAME} PRIVATE ${SPDLOG_INCLUDE_DIRS})

target_link_libraries(${PROJECT_NAME}
    PkgConfig::BENCHMARK
    PkgConfig::PROTOBUF)

install(TARGETS ${PROJECT_NAME} LIBRARY DESTINATION install/zoom)
