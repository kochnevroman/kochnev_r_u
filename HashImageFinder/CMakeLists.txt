cmake_minimum_required(VERSION 3.8)
project(HashImageFinder)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES hashImageFinder.h xxHash32.h hashImageFinder.cpp sqlite3.h ImagesHashDB.db shell.c sqlite3.c sqlite3ext.h)
add_executable(HashImageFinder ${SOURCE_FILES})