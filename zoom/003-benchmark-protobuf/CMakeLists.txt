project(003-benchmark-protobuf)

find_package(PkgConfig REQUIRED)
# Dep protobuf
pkg_search_module(PROTOBUF REQUIRED IMPORTED_TARGET GLOBAL protobuf>=3.6.1)
if(NOT PROTOBUF_FOUND)
    message(FATAL_ERROR "Please check libprotobuf-dev, Suggest to run `sudo apt install libprotobuf-dev`")
endif()

# 递归遍历ProtoBuf文件，进行编译生成*.pb.h和*.pb.cc
file(GLOB_RECURSE PROTO_DEF_FILES RELATIVE ${CMAKE_CURRENT_SOURCE_DIR}/proto-files *.proto)
foreach(PROTO_FILE ${PROTO_DEF_FILES})
    message(STATUS "generate proto file: ${PROTO_FILE}")
    execute_process(COMMAND bash -c "protoc -I=. --cpp_out=. ${PROTO_FILE}"
        WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR}/proto-files)
endforeach()

# 递归遍历所有源文件(包括刚才生成的*.pb.cc文件)
file(GLOB_RECURSE SRCS_LIST *.cc)
add_executable(${PROJECT_NAME} ${SRCS_LIST})
target_include_directories(${PROJECT_NAME} PRIVATE ${SPDLOG_INCLUDE_DIRS})
target_include_directories(${PROJECT_NAME} PRIVATE ${CMAKE_CURRENT_SOURCE_DIR}/proto-files)
target_link_libraries(${PROJECT_NAME}
    PkgConfig::BENCHMARK
    PkgConfig::PROTOBUF)

install(TARGETS ${PROJECT_NAME} LIBRARY DESTINATION install/zoom)
