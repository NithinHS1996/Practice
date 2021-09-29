cmake_minimum_required(VERSION 3.10)
project(ptr_container)

message("Started compilation")
add_executable(testing ptr_container.cpp)
target_link_libraries(testing LINK_PUBLIC ${Boost_LIBRARIES})
