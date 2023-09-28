cmake_minimum_required(VERSION 3.25)
project(logger)

set(CMAKE_CXX_STANDARD 20)

add_executable(logger main.cpp logger.cpp logger.h timer.cpp timer.h)
