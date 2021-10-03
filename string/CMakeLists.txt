cmake_minimum_required(VERSION 3.10)
project(String)

message("Compilation start")
add_executable(string string.cpp)
TARGET_LINK_LIBRARIES( string LINK_PUBLIC ${Boost_LIBRARIES} )
