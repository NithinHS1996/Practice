cmake_minimum_required(VERSION 3.10)

#set the project name and version
project(webmonitoring VERSION 1.0)

# specify the C++ standard
set(CMAKE_C_STANDARD 11)
set(CMAKE_C_STANDARD_REQUIRED True)

#debug print
message("started compilation")

# this one is important
SET(CMAKE_SYSTEM_NAME Linux)
#this one not so much
SET(CMAKE_SYSTEM_VERSION 1)

#comment below two lines to run in linux environment
# specify the cross compiler
#SET(CMAKE_CXX_COMPILER arm-linux-gnueabihf-g++)

# where is the target environment 
#SET(CMAKE_FIND_ROOT_PATH /home/nithin/gcc-linaro-7.5.0-2019.12-x86_64_armeb-linux-gnueabihf/bin/armeb-linux-gnueabihf-g++)

# search for programs in the build host directories
#SET(CMAKE_FIND_ROOT_PATH_MODE_PROGRAM NEVER)
# for libraries and headers in the target directories
#SET(CMAKE_FIND_ROOT_PATH_MODE_LIBRARY ONLY)
#SET(CMAKE_FIND_ROOT_PATH_MODE_INCLUDE ONLY)

#thread creation binary
#macro to name source files
set(SRC_FILES src/linked_list.c)

#build the executables
add_executable(linked_list ${SRC_FILES})

#link the libraries
#target_link_libraries(linked_list pthread)

#include the header files
target_include_directories(linked_list PUBLIC ${CMAKE_SOURCE_DIR}/inc)

