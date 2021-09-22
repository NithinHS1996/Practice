cmake_minimum_required(VERSION 3.10)
project(MyProject VERSION 1.0.0)
add_library(
	say-hello
	hello.hpp
	hello.cpp
)
add_executable(main main.cpp)

target_link_libraries(main PRIVATE say-hello)
