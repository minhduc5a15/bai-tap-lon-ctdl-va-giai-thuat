cmake_minimum_required(VERSION 3.28)
project(BTL)

set(CMAKE_CXX_STANDARD 20)
file(GLOB SRC "src/**/*.hpp")
add_executable(BTL main.cpp ${SRC})