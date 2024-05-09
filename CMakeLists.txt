cmake_minimum_required(VERSION 3.14)
project(Interpretator)

set(CMAKE_CXX_STANDARD 14)

include_directories(include gtest)

add_subdirectory(samples)
add_subdirectory(test)
add_subdirectory(gtest)
