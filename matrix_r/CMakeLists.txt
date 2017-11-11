cmake_minimum_required(VERSION 3.8)
project(Matrix)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES matrix_r.h matrix_r.cpp matrix_r-test.cpp)
add_executable(Matrix ${SOURCE_FILES})