cmake_minimum_required(VERSION 3.8)
project(week7)

set(CMAKE_CXX_STANDARD 14)

add_executable(exercise1_tests tests.cpp catch_main.cpp)

add_executable(exercise2_tests tests2.cpp catch_main.cpp)