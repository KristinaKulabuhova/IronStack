cmake_minimum_required(VERSION 3.17)
project(iron_stack)

set(CMAKE_CXX_STANDARD 14)
add_definitions(-DTEST_BUILD)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11 -Wall")
include_directories(.)

add_executable(iron_stack
        main.cpp
        stack.cpp
        stack.h
        hash.cpp
        hash.h
        test.cpp
        test.h hash.h)
