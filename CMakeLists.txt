cmake_minimum_required(VERSION 3.6)
project(cDemo)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp main2.cpp pointers_on_c_demo/basic_type.cpp pointers_on_c_demo/eight_queen.cpp pointers_on_c_demo/eight_queen_recursion.cpp)
add_executable(cDemo ${SOURCE_FILES})