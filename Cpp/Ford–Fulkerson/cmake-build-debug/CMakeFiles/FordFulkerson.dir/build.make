# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /home/denis/clion-2018.2.5/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/denis/clion-2018.2.5/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/denis/CLionProjects/Ford–Fulkerson

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/denis/CLionProjects/Ford–Fulkerson/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/FordFulkerson.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/FordFulkerson.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/FordFulkerson.dir/flags.make

CMakeFiles/FordFulkerson.dir/main.cpp.o: CMakeFiles/FordFulkerson.dir/flags.make
CMakeFiles/FordFulkerson.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/denis/CLionProjects/Ford–Fulkerson/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/FordFulkerson.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/FordFulkerson.dir/main.cpp.o -c /home/denis/CLionProjects/Ford–Fulkerson/main.cpp

CMakeFiles/FordFulkerson.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/FordFulkerson.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/denis/CLionProjects/Ford–Fulkerson/main.cpp > CMakeFiles/FordFulkerson.dir/main.cpp.i

CMakeFiles/FordFulkerson.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/FordFulkerson.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/denis/CLionProjects/Ford–Fulkerson/main.cpp -o CMakeFiles/FordFulkerson.dir/main.cpp.s

# Object files for target FordFulkerson
FordFulkerson_OBJECTS = \
"CMakeFiles/FordFulkerson.dir/main.cpp.o"

# External object files for target FordFulkerson
FordFulkerson_EXTERNAL_OBJECTS =

FordFulkerson: CMakeFiles/FordFulkerson.dir/main.cpp.o
FordFulkerson: CMakeFiles/FordFulkerson.dir/build.make
FordFulkerson: CMakeFiles/FordFulkerson.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/denis/CLionProjects/Ford–Fulkerson/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable FordFulkerson"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/FordFulkerson.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/FordFulkerson.dir/build: FordFulkerson

.PHONY : CMakeFiles/FordFulkerson.dir/build

CMakeFiles/FordFulkerson.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/FordFulkerson.dir/cmake_clean.cmake
.PHONY : CMakeFiles/FordFulkerson.dir/clean

CMakeFiles/FordFulkerson.dir/depend:
	cd /home/denis/CLionProjects/Ford–Fulkerson/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/denis/CLionProjects/Ford–Fulkerson /home/denis/CLionProjects/Ford–Fulkerson /home/denis/CLionProjects/Ford–Fulkerson/cmake-build-debug /home/denis/CLionProjects/Ford–Fulkerson/cmake-build-debug /home/denis/CLionProjects/Ford–Fulkerson/cmake-build-debug/CMakeFiles/FordFulkerson.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/FordFulkerson.dir/depend

