cmake_minimum_required(VERSION 3.8)
project(quaternion)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES quaternion.cpp quaternion.h quaternion-test.cpp)
add_executable(quaternion ${SOURCE_FILES})