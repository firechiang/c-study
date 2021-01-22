cmake_minimum_required(VERSION 3.17)
project(c_study)

set(CMAKE_CXX_STANDARD 14)

INCLUDE_DIRECTORIES(./helloword)

add_executable(c_study design-mode/c-06-map.cpp)