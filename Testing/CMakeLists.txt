cmake_minimum_required(VERSION 3.20)
project(Testing)

set(CMAKE_CXX_STANDARD 17)
add_subdirectory(lib/googletest-main)

add_executable(Testing main.cpp Tests/brackets.h Tests/stack.h)
include_directories(lib/googletest-main/googletest/include)
target_link_libraries(Testing gtest gtest_main)