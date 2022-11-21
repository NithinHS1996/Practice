cmake_minimum_required(VERSION 3.10)

project(Signals VERSION 1.0)

set(SRC_FILES src/streamserver.cpp )

add_executable(streamserver ${SRC_FILES})

target_include_directories(streamserver PUBLIC ${CMAKE_SOURCE_DIR}/inc)

add_executable(streamclient src/streamclient.cpp)
