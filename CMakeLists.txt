cmake_minimum_required(VERSION 3.8)
project(week7)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES tests.cpp catch_main.cpp)
add_executable(run_tests ${SOURCE_FILES})