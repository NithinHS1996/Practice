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

#thread creation binary
#macro to name source files
set(SRC_FILES src/thread_creation.cpp)

#build the executables
add_executable(thread_creation ${SRC_FILES})

#link the libraries
target_link_libraries(thread_creation pthread)

#include the header files
target_include_directories(thread_creation PUBLIC ${CMAKE_SOURCE_DIR}/inc)

#thread joinable binary
#macro to name source files
set(SRC_FILES src/thread_joinable.cpp)

#build the executables
add_executable(thread_joinable ${SRC_FILES})

#link the libraries
target_link_libraries(thread_joinable pthread)

#thread guard binary
#macro to name source files
set(SRC_FILES src/thread_guard.cpp)

#build the executables
add_executable(thread_guard ${SRC_FILES})

#link the libraries
target_link_libraries(thread_guard pthread)

#thread args binary
#macro to name source files
set(SRC_FILES src/thread_args.cpp)

#build the executables
add_executable(thread_args ${SRC_FILES})

#link the libraries
target_link_libraries(thread_args pthread)

#include the header files
target_include_directories(thread_args PUBLIC ${CMAKE_SOURCE_DIR}/inc)

#thread move binary
#macro to name source files
set(SRC_FILES src/thread_move.cpp)

#build the executables
add_executable(thread_move ${SRC_FILES})

#link the libraries
target_link_libraries(thread_move pthread)

#include the header files
target_include_directories(thread_move PUBLIC ${CMAKE_SOURCE_DIR}/inc)

#thread yield binary
#macro to name source files
set(SRC_FILES src/thread_yield.cpp)

#build the executables
add_executable(thread_yield ${SRC_FILES})

#link the libraries
target_link_libraries(thread_yield pthread)

#include the header files
target_include_directories(thread_yield PUBLIC ${CMAKE_SOURCE_DIR}/inc)

#thread accumulate binary
#macro to name source files
set(SRC_FILES src/thread_accumulate.cpp)

#build the executables
add_executable(thread_accumulate ${SRC_FILES})

#link the libraries
target_link_libraries(thread_accumulate pthread)

#include the header files
target_include_directories(thread_accumulate PUBLIC ${CMAKE_SOURCE_DIR}/inc)

#thread mutex binary
#macro to name source files
set(SRC_FILES src/thread_mutex.cpp)

#build the executables
add_executable(thread_mutex ${SRC_FILES})

#link the libraries
target_link_libraries(thread_mutex pthread)

#include the header files
target_include_directories(thread_mutex PUBLIC ${CMAKE_SOURCE_DIR}/inc)

#thread safe stack binary
#macro to name source files
set(SRC_FILES src/thread_stack.cpp)

#build the executables
add_executable(thread_stack ${SRC_FILES})

#link the libraries
target_link_libraries(thread_stack pthread)

#include the header files
target_include_directories(thread_stack PUBLIC ${CMAKE_SOURCE_DIR}/inc)

#thread condition variable binary
#macro to name source files
set(SRC_FILES src/thread_cond_var.cpp)

#build the executables
add_executable(thread_cond_var ${SRC_FILES})

#link the libraries
target_link_libraries(thread_cond_var pthread)

#include the header files
target_include_directories(thread_cond_var PUBLIC ${CMAKE_SOURCE_DIR}/inc)

#thread future binary
#macro to name source files
set(SRC_FILES src/thread_future.cpp)

#build the executables
add_executable(thread_future ${SRC_FILES})

#link the libraries
target_link_libraries(thread_future pthread)

#include the header files
target_include_directories(thread_future PUBLIC ${CMAKE_SOURCE_DIR}/inc)

#thread package_task binary
#macro to name source files
set(SRC_FILES src/thread_package_task.cpp)

#build the executables
add_executable(thread_package_task ${SRC_FILES})

#link the libraries
target_link_libraries(thread_package_task pthread)

#include the header files
target_include_directories(thread_package_task PUBLIC ${CMAKE_SOURCE_DIR}/inc)

#thread promise binary
#macro to name source files
set(SRC_FILES src/thread_promise.cpp)

#build the executables
add_executable(thread_promise ${SRC_FILES})

#link the libraries
target_link_libraries(thread_promise pthread)

#include the header files
target_include_directories(thread_promise PUBLIC ${CMAKE_SOURCE_DIR}/inc)

#thread promise_exp binary
#macro to name source files
set(SRC_FILES src/thread_promise_exp.cpp)

#build the executables
add_executable(thread_promise_exp ${SRC_FILES})

#link the libraries
target_link_libraries(thread_promise_exp pthread)

#include the header files
target_include_directories(thread_promise_exp PUBLIC ${CMAKE_SOURCE_DIR}/inc)

#thread jthreads binary
#macro to name source files
#set(SRC_FILES src/thread_jthreads.cpp)

#build the executables
#add_executable(thread_jthreads ${SRC_FILES})

#link the libraries
#target_link_libraries(thread_jthreads pthread)

#include the header files
#target_include_directories(thread_jthreads PUBLIC ${CMAKE_SOURCE_DIR}/inc)

#thread atomic binary
#macro to name source files
set(SRC_FILES src/thread_atomic.cpp)

#build the executables
add_executable(thread_atomic ${SRC_FILES})

#link the libraries
target_link_libraries(thread_atomic pthread)

#include the header files
target_include_directories(thread_atomic PUBLIC ${CMAKE_SOURCE_DIR}/inc)
