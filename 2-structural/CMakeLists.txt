cmake_minimum_required (VERSION 2.6)
# project (Tutorial)
add_definitions(-g -Wall)
add_executable(adapter.out adapter.cpp)

set_property (TARGET adapter.out PROPERTY CXX_STANDARD 11)
