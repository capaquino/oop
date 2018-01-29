cmake_minimum_required(VERSION 3.9)
project(cardgame)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin)

add_executable(cardgame main.cpp Card.hpp Card.cpp)
