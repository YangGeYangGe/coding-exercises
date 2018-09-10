cmake_minimum_required(VERSION 3.8)
project(ass5)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp BucketSort.h.h "BucketSort.cpp")
add_executable(ass5 ${SOURCE_FILES})