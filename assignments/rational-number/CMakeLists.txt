cmake_minimum_required(VERSION 3.9)
project(rational-number)

set(CMAKE_CXX_STANDARD 17)
set (INPUT_FILE input)

add_executable(rational-number main.cpp rational.cpp)

configure_file(${INPUT_FILE} ${CMAKE_BINARY_DIR}/${INPUT_FILE} COPYONLY)
