cmake_minimum_required (VERSION 2.6)
# project (Tutorial)
add_definitions(-g -Wall)
add_executable(chain_of_resp.out chain_of_resp.cpp)

set_property (TARGET chain_of_resp.out PROPERTY CXX_STANDARD 11)
