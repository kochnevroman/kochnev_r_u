cmake_minimum_required(VERSION 3.8)
project(matrix_r)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES matrix_r.h matrix_r.cpp matrix_r-test.cpp)
add_executable(matrix_r ${SOURCE_FILES})