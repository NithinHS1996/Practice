#to compile the library
add_library(
#to gernarate hello binary in a static way
	hello
	src/hello.hpp
	src/hello.cpp
)
#to include the hello directory as a public
target_include_directories(hello PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/src")

#to include the VERSION macro
#here PUBLIC - anyone can include
#PRIVATE - only hello binary can include
#INTERFACE - only other libraries can use
target_compile_definitions(hello PUBLIC VERSION=10)
