# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/nithin/.local/lib/python3.6/site-packages/cmake/data/bin/cmake

# The command to remove a file.
RM = /home/nithin/.local/lib/python3.6/site-packages/cmake/data/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/nithin/Everything/Linux_with_c++/concurrency

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nithin/Everything/Linux_with_c++/concurrency/build

# Include any dependencies generated for this target.
include CMakeFiles/thread_stack.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/thread_stack.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/thread_stack.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/thread_stack.dir/flags.make

CMakeFiles/thread_stack.dir/src/thread_stack.cpp.o: CMakeFiles/thread_stack.dir/flags.make
CMakeFiles/thread_stack.dir/src/thread_stack.cpp.o: ../src/thread_stack.cpp
CMakeFiles/thread_stack.dir/src/thread_stack.cpp.o: CMakeFiles/thread_stack.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nithin/Everything/Linux_with_c++/concurrency/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/thread_stack.dir/src/thread_stack.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/thread_stack.dir/src/thread_stack.cpp.o -MF CMakeFiles/thread_stack.dir/src/thread_stack.cpp.o.d -o CMakeFiles/thread_stack.dir/src/thread_stack.cpp.o -c /home/nithin/Everything/Linux_with_c++/concurrency/src/thread_stack.cpp

CMakeFiles/thread_stack.dir/src/thread_stack.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/thread_stack.dir/src/thread_stack.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nithin/Everything/Linux_with_c++/concurrency/src/thread_stack.cpp > CMakeFiles/thread_stack.dir/src/thread_stack.cpp.i

CMakeFiles/thread_stack.dir/src/thread_stack.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/thread_stack.dir/src/thread_stack.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nithin/Everything/Linux_with_c++/concurrency/src/thread_stack.cpp -o CMakeFiles/thread_stack.dir/src/thread_stack.cpp.s

# Object files for target thread_stack
thread_stack_OBJECTS = \
"CMakeFiles/thread_stack.dir/src/thread_stack.cpp.o"

# External object files for target thread_stack
thread_stack_EXTERNAL_OBJECTS =

thread_stack: CMakeFiles/thread_stack.dir/src/thread_stack.cpp.o
thread_stack: CMakeFiles/thread_stack.dir/build.make
thread_stack: CMakeFiles/thread_stack.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/nithin/Everything/Linux_with_c++/concurrency/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable thread_stack"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/thread_stack.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/thread_stack.dir/build: thread_stack
.PHONY : CMakeFiles/thread_stack.dir/build

CMakeFiles/thread_stack.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/thread_stack.dir/cmake_clean.cmake
.PHONY : CMakeFiles/thread_stack.dir/clean

CMakeFiles/thread_stack.dir/depend:
	cd /home/nithin/Everything/Linux_with_c++/concurrency/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nithin/Everything/Linux_with_c++/concurrency /home/nithin/Everything/Linux_with_c++/concurrency /home/nithin/Everything/Linux_with_c++/concurrency/build /home/nithin/Everything/Linux_with_c++/concurrency/build /home/nithin/Everything/Linux_with_c++/concurrency/build/CMakeFiles/thread_stack.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/thread_stack.dir/depend

