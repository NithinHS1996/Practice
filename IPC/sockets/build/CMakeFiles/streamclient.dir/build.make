# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.24

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
CMAKE_COMMAND = /home/nithin/.local/lib/python3.10/site-packages/cmake/data/bin/cmake

# The command to remove a file.
RM = /home/nithin/.local/lib/python3.10/site-packages/cmake/data/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/nithin/Everything/Linux_with_c++/IPC/sockets

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/nithin/Everything/Linux_with_c++/IPC/sockets/build

# Include any dependencies generated for this target.
include CMakeFiles/streamclient.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/streamclient.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/streamclient.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/streamclient.dir/flags.make

CMakeFiles/streamclient.dir/src/streamclient.cpp.o: CMakeFiles/streamclient.dir/flags.make
CMakeFiles/streamclient.dir/src/streamclient.cpp.o: /home/nithin/Everything/Linux_with_c++/IPC/sockets/src/streamclient.cpp
CMakeFiles/streamclient.dir/src/streamclient.cpp.o: CMakeFiles/streamclient.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/nithin/Everything/Linux_with_c++/IPC/sockets/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/streamclient.dir/src/streamclient.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/streamclient.dir/src/streamclient.cpp.o -MF CMakeFiles/streamclient.dir/src/streamclient.cpp.o.d -o CMakeFiles/streamclient.dir/src/streamclient.cpp.o -c /home/nithin/Everything/Linux_with_c++/IPC/sockets/src/streamclient.cpp

CMakeFiles/streamclient.dir/src/streamclient.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/streamclient.dir/src/streamclient.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/nithin/Everything/Linux_with_c++/IPC/sockets/src/streamclient.cpp > CMakeFiles/streamclient.dir/src/streamclient.cpp.i

CMakeFiles/streamclient.dir/src/streamclient.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/streamclient.dir/src/streamclient.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/nithin/Everything/Linux_with_c++/IPC/sockets/src/streamclient.cpp -o CMakeFiles/streamclient.dir/src/streamclient.cpp.s

# Object files for target streamclient
streamclient_OBJECTS = \
"CMakeFiles/streamclient.dir/src/streamclient.cpp.o"

# External object files for target streamclient
streamclient_EXTERNAL_OBJECTS =

streamclient: CMakeFiles/streamclient.dir/src/streamclient.cpp.o
streamclient: CMakeFiles/streamclient.dir/build.make
streamclient: CMakeFiles/streamclient.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/nithin/Everything/Linux_with_c++/IPC/sockets/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable streamclient"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/streamclient.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/streamclient.dir/build: streamclient
.PHONY : CMakeFiles/streamclient.dir/build

CMakeFiles/streamclient.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/streamclient.dir/cmake_clean.cmake
.PHONY : CMakeFiles/streamclient.dir/clean

CMakeFiles/streamclient.dir/depend:
	cd /home/nithin/Everything/Linux_with_c++/IPC/sockets/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/nithin/Everything/Linux_with_c++/IPC/sockets /home/nithin/Everything/Linux_with_c++/IPC/sockets /home/nithin/Everything/Linux_with_c++/IPC/sockets/build /home/nithin/Everything/Linux_with_c++/IPC/sockets/build /home/nithin/Everything/Linux_with_c++/IPC/sockets/build/CMakeFiles/streamclient.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/streamclient.dir/depend

