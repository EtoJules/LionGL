# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.17

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
CMAKE_COMMAND = /var/lib/snapd/snap/clion/139/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /var/lib/snapd/snap/clion/139/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/andrew/MY/Projects/LionGL

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/andrew/MY/Projects/LionGL/cmake-build-default

# Include any dependencies generated for this target.
include src/CMakeFiles/Sources.dir/depend.make

# Include the progress variables for this target.
include src/CMakeFiles/Sources.dir/progress.make

# Include the compile flags for this target's objects.
include src/CMakeFiles/Sources.dir/flags.make

src/CMakeFiles/Sources.dir/Helper/parser.cpp.o: src/CMakeFiles/Sources.dir/flags.make
src/CMakeFiles/Sources.dir/Helper/parser.cpp.o: ../src/Helper/parser.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andrew/MY/Projects/LionGL/cmake-build-default/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/CMakeFiles/Sources.dir/Helper/parser.cpp.o"
	cd /home/andrew/MY/Projects/LionGL/cmake-build-default/src && /usr/lib64/ccache/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Sources.dir/Helper/parser.cpp.o -c /home/andrew/MY/Projects/LionGL/src/Helper/parser.cpp

src/CMakeFiles/Sources.dir/Helper/parser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Sources.dir/Helper/parser.cpp.i"
	cd /home/andrew/MY/Projects/LionGL/cmake-build-default/src && /usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/andrew/MY/Projects/LionGL/src/Helper/parser.cpp > CMakeFiles/Sources.dir/Helper/parser.cpp.i

src/CMakeFiles/Sources.dir/Helper/parser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Sources.dir/Helper/parser.cpp.s"
	cd /home/andrew/MY/Projects/LionGL/cmake-build-default/src && /usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/andrew/MY/Projects/LionGL/src/Helper/parser.cpp -o CMakeFiles/Sources.dir/Helper/parser.cpp.s

# Object files for target Sources
Sources_OBJECTS = \
"CMakeFiles/Sources.dir/Helper/parser.cpp.o"

# External object files for target Sources
Sources_EXTERNAL_OBJECTS =

src/libSources.a: src/CMakeFiles/Sources.dir/Helper/parser.cpp.o
src/libSources.a: src/CMakeFiles/Sources.dir/build.make
src/libSources.a: src/CMakeFiles/Sources.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/andrew/MY/Projects/LionGL/cmake-build-default/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX static library libSources.a"
	cd /home/andrew/MY/Projects/LionGL/cmake-build-default/src && $(CMAKE_COMMAND) -P CMakeFiles/Sources.dir/cmake_clean_target.cmake
	cd /home/andrew/MY/Projects/LionGL/cmake-build-default/src && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Sources.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/CMakeFiles/Sources.dir/build: src/libSources.a

.PHONY : src/CMakeFiles/Sources.dir/build

src/CMakeFiles/Sources.dir/clean:
	cd /home/andrew/MY/Projects/LionGL/cmake-build-default/src && $(CMAKE_COMMAND) -P CMakeFiles/Sources.dir/cmake_clean.cmake
.PHONY : src/CMakeFiles/Sources.dir/clean

src/CMakeFiles/Sources.dir/depend:
	cd /home/andrew/MY/Projects/LionGL/cmake-build-default && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/andrew/MY/Projects/LionGL /home/andrew/MY/Projects/LionGL/src /home/andrew/MY/Projects/LionGL/cmake-build-default /home/andrew/MY/Projects/LionGL/cmake-build-default/src /home/andrew/MY/Projects/LionGL/cmake-build-default/src/CMakeFiles/Sources.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/CMakeFiles/Sources.dir/depend

