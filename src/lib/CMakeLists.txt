cmake_minimum_required(VERSION 2.6)
# project name
project(MyLib)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++1y -Wall")

set(SOURCE_LIB
    lib.cpp
  )

add_library(lib STATIC ${SOURCE_LIB})
