cmake_minimum_required(VERSION 3.8)
project(vector3d)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES vector3d.h vector3d.cpp vector3d-test.cpp)
add_executable(vector3d ${SOURCE_FILES})