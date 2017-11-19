cmake_minimum_required(VERSION 3.8)
project(matrix_u)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES matrix_u.h matrix_u.cpp matrix_u-test.cpp)
add_executable(matrix_u ${SOURCE_FILES})