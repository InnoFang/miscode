cmake_minimum_required(VERSION 3.16)
project(kv_lite)

set(CMAKE_CXX_STANDARD 14)

include_directories(include)

add_executable(kv_lite main.cpp)