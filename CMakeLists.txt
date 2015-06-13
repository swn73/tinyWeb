cmake_minimum_required(VERSION 3.2)
project(tinyWeb)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp)
add_executable(tinyWeb ${SOURCE_FILES} comm_head.h error_handling.h rio.h core.h sig_handler.h)