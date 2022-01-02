cmake_minimum_required(VERSION 3.17)
project(c_study)

set(CMAKE_CXX_STANDARD 14)

INCLUDE_DIRECTORIES(./helloword)

add_executable(c_study design-mode/c-13-thread.cpp)

# 关于多线程的配置，否则使用多线程会报 undefined reference to `pthread_create' 错误
find_package(Threads REQUIRED)
# 注意：c_study是入口的名称
target_link_libraries(c_study Threads::Threads)

