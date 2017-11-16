cmake_minimum_required(VERSION 3.8)
project(stackl)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES stack.h stack.cpp stack-test.cpp)
add_executable(stackl ${SOURCE_FILES})