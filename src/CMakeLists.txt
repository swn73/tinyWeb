cmake_minimum_required(VERSION 2.8)

project(tinyWeb)

add_definitions(-Wall -std=c++11)

add_subdirectory(unit_test)

add_executable(tinyWeb main.cpp)
