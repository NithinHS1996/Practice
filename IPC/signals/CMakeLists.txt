cmake_minimum_required(VERSION 3.10)

project(Signals VERSION 1.0)

set(SRC_FILES src/sigsent.cpp )

add_executable(sigsent ${SRC_FILES})

target_include_directories(sigsent PUBLIC ${CMAKE_SOURCE_DIR}/inc)

add_executable(sigreceive src/sigreceive.cpp)

add_executable(sigself src/sigself.cpp)

