cmake_minimum_required(VERSION 3.10)

project(Signals VERSION 1.0)

set(SRC_FILES src/msgsender.cpp )

add_executable(msgsender ${SRC_FILES})

target_include_directories(msgsender PUBLIC ${CMAKE_SOURCE_DIR}/inc)

add_executable(msgreceiver src/msgreceiver.cpp)
