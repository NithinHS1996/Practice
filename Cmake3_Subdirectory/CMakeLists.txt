#this is required to mention the minimum required cmake version
cmake_minimum_required(VERSION 3.10)
#this is required for defining the name for project
project(MyProject VERSION 1.0.0)

#used to set the variables
set(VARIABLE 4000)
set(VAR "HELLO")

#used to print the terminal message
message( "hey cmake here ${VARIABLE} ${VAR} ${PROJECT_VERSION}")

#to add the subdirectory
add_subdirectory(hello)

#to compile the main with maain.cpp
add_executable(main main.cpp)

#to link the library with main code
target_link_libraries(main PRIVATE hello)
