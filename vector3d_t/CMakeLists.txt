cmake_minimum_required(VERSION 3.8)
project(vector3d_t)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES vector3d_t.h vector3d_t-test.cpp)
add_executable(vector3d_t ${SOURCE_FILES})