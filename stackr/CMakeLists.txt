cmake_minimum_required(VERSION 3.8)
project(stackr)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES stackr.h stackr.cpp stackr-test.cpp)
add_executable(stackr ${SOURCE_FILES})