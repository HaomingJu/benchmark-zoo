project(001-benchmark-normal-use)

file(GLOB_RECURSE SRCS_LIST *.cc)

add_executable(${PROJECT_NAME} ${SRCS_LIST})

target_link_libraries(${PROJECT_NAME} PkgConfig::BENCHMARK)

install(TARGETS ${PROJECT_NAME} LIBRARY DESTINATION install/zoom)
