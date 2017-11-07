cmake_minimum_required(VERSION 3.8)
project(vector3d_T)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES vector3d_T.h vector3d_T.cpp vector3d_t-test.cpp)
add_executable(vector3d_T ${SOURCE_FILES})