cmake_minimum_required(VERSION 3.10)
project(dailies)

enable_testing()

set(CMAKE_CXX_FLAGS "-std=c++17 -msse4.2 -Wall -Wextra -O3 -g")

add_subdirectory(1)
add_subdirectory(2)

add_subdirectory(test)