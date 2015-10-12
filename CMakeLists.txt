cmake_minimum_required(VERSION 3.3)
project(HW3_2)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES hw311_main.cpp)
add_executable(HW3_2 ${SOURCE_FILES})