cmake_minimum_required(VERSION 3.10)
project(demo)

message("started compilation")
FIND_PACKAGE( Boost 1.65.1 COMPONENTS program_options REQUIRED )
INCLUDE_DIRECTORIES( ${Boost_INCLUDE_DIR} )
add_executable(testing shared_ptr.cpp)
TARGET_LINK_LIBRARIES( testing LINK_PUBLIC ${Boost_LIBRARIES} )
