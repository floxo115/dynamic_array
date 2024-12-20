cmake_minimum_required(VERSION 3.25)
project(dynamic_array C)

set(CMAKE_C_STANDARD 17)
add_subdirectory("extern/Unity")
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -Wextra -Werror -pedantic -pedantic-errors -Wshadow -Wcast-align -Wcast-qual -Wconversion -Wsign-conversion -Wformat=2 -Wundef -Wimplicit-fallthrough -Wlogical-op -Wnull-dereference -Wredundant-decls -fstack-protector-strong -D_FORTIFY_SOURCE=2")


add_library(dynamic_array STATIC library.c)

add_executable(test test.c library.c)
target_link_libraries(test PRIVATE unity m)
