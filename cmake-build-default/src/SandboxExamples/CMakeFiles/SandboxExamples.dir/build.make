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
include src/SandboxExamples/CMakeFiles/SandboxExamples.dir/depend.make

# Include the progress variables for this target.
include src/SandboxExamples/CMakeFiles/SandboxExamples.dir/progress.make

# Include the compile flags for this target's objects.
include src/SandboxExamples/CMakeFiles/SandboxExamples.dir/flags.make

src/SandboxExamples/CMakeFiles/SandboxExamples.dir/TriangleSandbox/TriangleSandbox.cpp.o: src/SandboxExamples/CMakeFiles/SandboxExamples.dir/flags.make
src/SandboxExamples/CMakeFiles/SandboxExamples.dir/TriangleSandbox/TriangleSandbox.cpp.o: ../src/SandboxExamples/TriangleSandbox/TriangleSandbox.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andrew/MY/Projects/LionGL/cmake-build-default/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object src/SandboxExamples/CMakeFiles/SandboxExamples.dir/TriangleSandbox/TriangleSandbox.cpp.o"
	cd /home/andrew/MY/Projects/LionGL/cmake-build-default/src/SandboxExamples && /usr/lib64/ccache/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SandboxExamples.dir/TriangleSandbox/TriangleSandbox.cpp.o -c /home/andrew/MY/Projects/LionGL/src/SandboxExamples/TriangleSandbox/TriangleSandbox.cpp

src/SandboxExamples/CMakeFiles/SandboxExamples.dir/TriangleSandbox/TriangleSandbox.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SandboxExamples.dir/TriangleSandbox/TriangleSandbox.cpp.i"
	cd /home/andrew/MY/Projects/LionGL/cmake-build-default/src/SandboxExamples && /usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/andrew/MY/Projects/LionGL/src/SandboxExamples/TriangleSandbox/TriangleSandbox.cpp > CMakeFiles/SandboxExamples.dir/TriangleSandbox/TriangleSandbox.cpp.i

src/SandboxExamples/CMakeFiles/SandboxExamples.dir/TriangleSandbox/TriangleSandbox.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SandboxExamples.dir/TriangleSandbox/TriangleSandbox.cpp.s"
	cd /home/andrew/MY/Projects/LionGL/cmake-build-default/src/SandboxExamples && /usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/andrew/MY/Projects/LionGL/src/SandboxExamples/TriangleSandbox/TriangleSandbox.cpp -o CMakeFiles/SandboxExamples.dir/TriangleSandbox/TriangleSandbox.cpp.s

src/SandboxExamples/CMakeFiles/SandboxExamples.dir/CameraSandbox/CameraSandbox.cpp.o: src/SandboxExamples/CMakeFiles/SandboxExamples.dir/flags.make
src/SandboxExamples/CMakeFiles/SandboxExamples.dir/CameraSandbox/CameraSandbox.cpp.o: ../src/SandboxExamples/CameraSandbox/CameraSandbox.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andrew/MY/Projects/LionGL/cmake-build-default/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object src/SandboxExamples/CMakeFiles/SandboxExamples.dir/CameraSandbox/CameraSandbox.cpp.o"
	cd /home/andrew/MY/Projects/LionGL/cmake-build-default/src/SandboxExamples && /usr/lib64/ccache/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SandboxExamples.dir/CameraSandbox/CameraSandbox.cpp.o -c /home/andrew/MY/Projects/LionGL/src/SandboxExamples/CameraSandbox/CameraSandbox.cpp

src/SandboxExamples/CMakeFiles/SandboxExamples.dir/CameraSandbox/CameraSandbox.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SandboxExamples.dir/CameraSandbox/CameraSandbox.cpp.i"
	cd /home/andrew/MY/Projects/LionGL/cmake-build-default/src/SandboxExamples && /usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/andrew/MY/Projects/LionGL/src/SandboxExamples/CameraSandbox/CameraSandbox.cpp > CMakeFiles/SandboxExamples.dir/CameraSandbox/CameraSandbox.cpp.i

src/SandboxExamples/CMakeFiles/SandboxExamples.dir/CameraSandbox/CameraSandbox.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SandboxExamples.dir/CameraSandbox/CameraSandbox.cpp.s"
	cd /home/andrew/MY/Projects/LionGL/cmake-build-default/src/SandboxExamples && /usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/andrew/MY/Projects/LionGL/src/SandboxExamples/CameraSandbox/CameraSandbox.cpp -o CMakeFiles/SandboxExamples.dir/CameraSandbox/CameraSandbox.cpp.s

src/SandboxExamples/CMakeFiles/SandboxExamples.dir/LightningSandbox/LightningSandbox.cpp.o: src/SandboxExamples/CMakeFiles/SandboxExamples.dir/flags.make
src/SandboxExamples/CMakeFiles/SandboxExamples.dir/LightningSandbox/LightningSandbox.cpp.o: ../src/SandboxExamples/LightningSandbox/LightningSandbox.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andrew/MY/Projects/LionGL/cmake-build-default/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object src/SandboxExamples/CMakeFiles/SandboxExamples.dir/LightningSandbox/LightningSandbox.cpp.o"
	cd /home/andrew/MY/Projects/LionGL/cmake-build-default/src/SandboxExamples && /usr/lib64/ccache/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SandboxExamples.dir/LightningSandbox/LightningSandbox.cpp.o -c /home/andrew/MY/Projects/LionGL/src/SandboxExamples/LightningSandbox/LightningSandbox.cpp

src/SandboxExamples/CMakeFiles/SandboxExamples.dir/LightningSandbox/LightningSandbox.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SandboxExamples.dir/LightningSandbox/LightningSandbox.cpp.i"
	cd /home/andrew/MY/Projects/LionGL/cmake-build-default/src/SandboxExamples && /usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/andrew/MY/Projects/LionGL/src/SandboxExamples/LightningSandbox/LightningSandbox.cpp > CMakeFiles/SandboxExamples.dir/LightningSandbox/LightningSandbox.cpp.i

src/SandboxExamples/CMakeFiles/SandboxExamples.dir/LightningSandbox/LightningSandbox.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SandboxExamples.dir/LightningSandbox/LightningSandbox.cpp.s"
	cd /home/andrew/MY/Projects/LionGL/cmake-build-default/src/SandboxExamples && /usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/andrew/MY/Projects/LionGL/src/SandboxExamples/LightningSandbox/LightningSandbox.cpp -o CMakeFiles/SandboxExamples.dir/LightningSandbox/LightningSandbox.cpp.s

src/SandboxExamples/CMakeFiles/SandboxExamples.dir/MeshSandbox/MeshSandbox.cpp.o: src/SandboxExamples/CMakeFiles/SandboxExamples.dir/flags.make
src/SandboxExamples/CMakeFiles/SandboxExamples.dir/MeshSandbox/MeshSandbox.cpp.o: ../src/SandboxExamples/MeshSandbox/MeshSandbox.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andrew/MY/Projects/LionGL/cmake-build-default/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object src/SandboxExamples/CMakeFiles/SandboxExamples.dir/MeshSandbox/MeshSandbox.cpp.o"
	cd /home/andrew/MY/Projects/LionGL/cmake-build-default/src/SandboxExamples && /usr/lib64/ccache/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/SandboxExamples.dir/MeshSandbox/MeshSandbox.cpp.o -c /home/andrew/MY/Projects/LionGL/src/SandboxExamples/MeshSandbox/MeshSandbox.cpp

src/SandboxExamples/CMakeFiles/SandboxExamples.dir/MeshSandbox/MeshSandbox.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/SandboxExamples.dir/MeshSandbox/MeshSandbox.cpp.i"
	cd /home/andrew/MY/Projects/LionGL/cmake-build-default/src/SandboxExamples && /usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/andrew/MY/Projects/LionGL/src/SandboxExamples/MeshSandbox/MeshSandbox.cpp > CMakeFiles/SandboxExamples.dir/MeshSandbox/MeshSandbox.cpp.i

src/SandboxExamples/CMakeFiles/SandboxExamples.dir/MeshSandbox/MeshSandbox.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/SandboxExamples.dir/MeshSandbox/MeshSandbox.cpp.s"
	cd /home/andrew/MY/Projects/LionGL/cmake-build-default/src/SandboxExamples && /usr/lib64/ccache/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/andrew/MY/Projects/LionGL/src/SandboxExamples/MeshSandbox/MeshSandbox.cpp -o CMakeFiles/SandboxExamples.dir/MeshSandbox/MeshSandbox.cpp.s

# Object files for target SandboxExamples
SandboxExamples_OBJECTS = \
"CMakeFiles/SandboxExamples.dir/TriangleSandbox/TriangleSandbox.cpp.o" \
"CMakeFiles/SandboxExamples.dir/CameraSandbox/CameraSandbox.cpp.o" \
"CMakeFiles/SandboxExamples.dir/LightningSandbox/LightningSandbox.cpp.o" \
"CMakeFiles/SandboxExamples.dir/MeshSandbox/MeshSandbox.cpp.o"

# External object files for target SandboxExamples
SandboxExamples_EXTERNAL_OBJECTS =

src/SandboxExamples/libSandboxExamples.a: src/SandboxExamples/CMakeFiles/SandboxExamples.dir/TriangleSandbox/TriangleSandbox.cpp.o
src/SandboxExamples/libSandboxExamples.a: src/SandboxExamples/CMakeFiles/SandboxExamples.dir/CameraSandbox/CameraSandbox.cpp.o
src/SandboxExamples/libSandboxExamples.a: src/SandboxExamples/CMakeFiles/SandboxExamples.dir/LightningSandbox/LightningSandbox.cpp.o
src/SandboxExamples/libSandboxExamples.a: src/SandboxExamples/CMakeFiles/SandboxExamples.dir/MeshSandbox/MeshSandbox.cpp.o
src/SandboxExamples/libSandboxExamples.a: src/SandboxExamples/CMakeFiles/SandboxExamples.dir/build.make
src/SandboxExamples/libSandboxExamples.a: src/SandboxExamples/CMakeFiles/SandboxExamples.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/andrew/MY/Projects/LionGL/cmake-build-default/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking CXX static library libSandboxExamples.a"
	cd /home/andrew/MY/Projects/LionGL/cmake-build-default/src/SandboxExamples && $(CMAKE_COMMAND) -P CMakeFiles/SandboxExamples.dir/cmake_clean_target.cmake
	cd /home/andrew/MY/Projects/LionGL/cmake-build-default/src/SandboxExamples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SandboxExamples.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
src/SandboxExamples/CMakeFiles/SandboxExamples.dir/build: src/SandboxExamples/libSandboxExamples.a

.PHONY : src/SandboxExamples/CMakeFiles/SandboxExamples.dir/build

src/SandboxExamples/CMakeFiles/SandboxExamples.dir/clean:
	cd /home/andrew/MY/Projects/LionGL/cmake-build-default/src/SandboxExamples && $(CMAKE_COMMAND) -P CMakeFiles/SandboxExamples.dir/cmake_clean.cmake
.PHONY : src/SandboxExamples/CMakeFiles/SandboxExamples.dir/clean

src/SandboxExamples/CMakeFiles/SandboxExamples.dir/depend:
	cd /home/andrew/MY/Projects/LionGL/cmake-build-default && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/andrew/MY/Projects/LionGL /home/andrew/MY/Projects/LionGL/src/SandboxExamples /home/andrew/MY/Projects/LionGL/cmake-build-default /home/andrew/MY/Projects/LionGL/cmake-build-default/src/SandboxExamples /home/andrew/MY/Projects/LionGL/cmake-build-default/src/SandboxExamples/CMakeFiles/SandboxExamples.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : src/SandboxExamples/CMakeFiles/SandboxExamples.dir/depend

