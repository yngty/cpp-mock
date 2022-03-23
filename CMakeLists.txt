cmake_minimum_required(VERSION 3.10)

project(cpp-mock)

set(CMAKE_CXX_STANDARD 17)

add_executable(test_function_linux test_function_linux.cpp mock.cpp)