cmake_minimum_required(VERSION 3.8)
project(Array)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES array.h array.cpp array-test.cpp)
add_executable(Array ${SOURCE_FILES})