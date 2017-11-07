cmake_minimum_required(VERSION 3.8)
project(complex)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES complex_text.cpp complex.h complex.cpp)
add_executable(complex ${SOURCE_FILES})