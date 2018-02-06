cmake_minimum_required(VERSION 3.9)
project(String)

set(CMAKE_CXX_STANDARD 11)
# set(CMAKE_CXX_FLAGS "-fsanitize=address")
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(run_string main.cpp)
