# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.16

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/andrew/MY/Projects/Graphic/LionGL/libs/SDL2-2.0.12

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/andrew/MY/Projects/Graphic/LionGL/libs/SDL2-2.0.12/build

# Include any dependencies generated for this target.
include CMakeFiles/SDL2main.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/SDL2main.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/SDL2main.dir/flags.make

CMakeFiles/SDL2main.dir/src/main/dummy/SDL_dummy_main.c.o: CMakeFiles/SDL2main.dir/flags.make
CMakeFiles/SDL2main.dir/src/main/dummy/SDL_dummy_main.c.o: ../src/main/dummy/SDL_dummy_main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/andrew/MY/Projects/Graphic/LionGL/libs/SDL2-2.0.12/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/SDL2main.dir/src/main/dummy/SDL_dummy_main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/SDL2main.dir/src/main/dummy/SDL_dummy_main.c.o   -c /home/andrew/MY/Projects/Graphic/LionGL/libs/SDL2-2.0.12/src/main/dummy/SDL_dummy_main.c

CMakeFiles/SDL2main.dir/src/main/dummy/SDL_dummy_main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/SDL2main.dir/src/main/dummy/SDL_dummy_main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/andrew/MY/Projects/Graphic/LionGL/libs/SDL2-2.0.12/src/main/dummy/SDL_dummy_main.c > CMakeFiles/SDL2main.dir/src/main/dummy/SDL_dummy_main.c.i

CMakeFiles/SDL2main.dir/src/main/dummy/SDL_dummy_main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/SDL2main.dir/src/main/dummy/SDL_dummy_main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/andrew/MY/Projects/Graphic/LionGL/libs/SDL2-2.0.12/src/main/dummy/SDL_dummy_main.c -o CMakeFiles/SDL2main.dir/src/main/dummy/SDL_dummy_main.c.s

# Object files for target SDL2main
SDL2main_OBJECTS = \
"CMakeFiles/SDL2main.dir/src/main/dummy/SDL_dummy_main.c.o"

# External object files for target SDL2main
SDL2main_EXTERNAL_OBJECTS =

libSDL2main.a: CMakeFiles/SDL2main.dir/src/main/dummy/SDL_dummy_main.c.o
libSDL2main.a: CMakeFiles/SDL2main.dir/build.make
libSDL2main.a: CMakeFiles/SDL2main.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/andrew/MY/Projects/Graphic/LionGL/libs/SDL2-2.0.12/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libSDL2main.a"
	$(CMAKE_COMMAND) -P CMakeFiles/SDL2main.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/SDL2main.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/SDL2main.dir/build: libSDL2main.a

.PHONY : CMakeFiles/SDL2main.dir/build

CMakeFiles/SDL2main.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/SDL2main.dir/cmake_clean.cmake
.PHONY : CMakeFiles/SDL2main.dir/clean

CMakeFiles/SDL2main.dir/depend:
	cd /home/andrew/MY/Projects/Graphic/LionGL/libs/SDL2-2.0.12/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/andrew/MY/Projects/Graphic/LionGL/libs/SDL2-2.0.12 /home/andrew/MY/Projects/Graphic/LionGL/libs/SDL2-2.0.12 /home/andrew/MY/Projects/Graphic/LionGL/libs/SDL2-2.0.12/build /home/andrew/MY/Projects/Graphic/LionGL/libs/SDL2-2.0.12/build /home/andrew/MY/Projects/Graphic/LionGL/libs/SDL2-2.0.12/build/CMakeFiles/SDL2main.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/SDL2main.dir/depend

