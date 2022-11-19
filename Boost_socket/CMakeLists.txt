cmake_minimum_required(VERSION 3.10)

#set the project name and version
project(webmonitoring VERSION 1.0)

# specify the C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

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

#files for library
#-------------------------------------------------------------------------------
#macro to name source files
find_package(Boost 1.78.0 COMPONENTS program_options  REQUIRED)

#boost socket server
#-------------------------------------------------------------------------------
set(TIMERLIB_FILES src/server.cpp)
add_executable(server ${TIMERLIB_FILES})
target_link_libraries(server ${Boost_LIBRARIES} )
target_link_libraries(server boost_filesystem boost_system )
target_include_directories(server PUBLIC ${CMAKE_SOURCE_DIR}/inc )

#boost socket client
#-------------------------------------------------------------------------------
set(TIMERLIB_FILES src/client.cpp)
add_executable(client ${TIMERLIB_FILES})
target_link_libraries(client ${Boost_LIBRARIES} )
target_link_libraries(client boost_filesystem boost_system )
target_include_directories(client PUBLIC ${CMAKE_SOURCE_DIR}/inc )
