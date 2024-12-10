cmake_minimum_required(VERSION 3.29)
project(dynamic_array C)

set(CMAKE_C_STANDARD 17)
add_subdirectory("extern/Unity")

add_library(dynamic_array STATIC library.c)

add_executable(test test.c)
target_link_libraries(test PRIVATE unity)
