# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.26

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/fhayha/Documentos/ByteRunnerDB

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/fhayha/Documentos/ByteRunnerDB

# Include any dependencies generated for this target.
include libs/evpp/examples/CMakeFiles/example_tcpecho.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include libs/evpp/examples/CMakeFiles/example_tcpecho.dir/compiler_depend.make

# Include the progress variables for this target.
include libs/evpp/examples/CMakeFiles/example_tcpecho.dir/progress.make

# Include the compile flags for this target's objects.
include libs/evpp/examples/CMakeFiles/example_tcpecho.dir/flags.make

libs/evpp/examples/CMakeFiles/example_tcpecho.dir/echo/tcpecho/main.cc.o: libs/evpp/examples/CMakeFiles/example_tcpecho.dir/flags.make
libs/evpp/examples/CMakeFiles/example_tcpecho.dir/echo/tcpecho/main.cc.o: libs/evpp/examples/echo/tcpecho/main.cc
libs/evpp/examples/CMakeFiles/example_tcpecho.dir/echo/tcpecho/main.cc.o: libs/evpp/examples/CMakeFiles/example_tcpecho.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fhayha/Documentos/ByteRunnerDB/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object libs/evpp/examples/CMakeFiles/example_tcpecho.dir/echo/tcpecho/main.cc.o"
	cd /home/fhayha/Documentos/ByteRunnerDB/libs/evpp/examples && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT libs/evpp/examples/CMakeFiles/example_tcpecho.dir/echo/tcpecho/main.cc.o -MF CMakeFiles/example_tcpecho.dir/echo/tcpecho/main.cc.o.d -o CMakeFiles/example_tcpecho.dir/echo/tcpecho/main.cc.o -c /home/fhayha/Documentos/ByteRunnerDB/libs/evpp/examples/echo/tcpecho/main.cc

libs/evpp/examples/CMakeFiles/example_tcpecho.dir/echo/tcpecho/main.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/example_tcpecho.dir/echo/tcpecho/main.cc.i"
	cd /home/fhayha/Documentos/ByteRunnerDB/libs/evpp/examples && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fhayha/Documentos/ByteRunnerDB/libs/evpp/examples/echo/tcpecho/main.cc > CMakeFiles/example_tcpecho.dir/echo/tcpecho/main.cc.i

libs/evpp/examples/CMakeFiles/example_tcpecho.dir/echo/tcpecho/main.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/example_tcpecho.dir/echo/tcpecho/main.cc.s"
	cd /home/fhayha/Documentos/ByteRunnerDB/libs/evpp/examples && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fhayha/Documentos/ByteRunnerDB/libs/evpp/examples/echo/tcpecho/main.cc -o CMakeFiles/example_tcpecho.dir/echo/tcpecho/main.cc.s

# Object files for target example_tcpecho
example_tcpecho_OBJECTS = \
"CMakeFiles/example_tcpecho.dir/echo/tcpecho/main.cc.o"

# External object files for target example_tcpecho
example_tcpecho_EXTERNAL_OBJECTS =

libs/evpp/bin/example_tcpecho: libs/evpp/examples/CMakeFiles/example_tcpecho.dir/echo/tcpecho/main.cc.o
libs/evpp/bin/example_tcpecho: libs/evpp/examples/CMakeFiles/example_tcpecho.dir/build.make
libs/evpp/bin/example_tcpecho: libs/evpp/lib/libevpp_static.a
libs/evpp/bin/example_tcpecho: libs/evpp/examples/CMakeFiles/example_tcpecho.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/fhayha/Documentos/ByteRunnerDB/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../bin/example_tcpecho"
	cd /home/fhayha/Documentos/ByteRunnerDB/libs/evpp/examples && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/example_tcpecho.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
libs/evpp/examples/CMakeFiles/example_tcpecho.dir/build: libs/evpp/bin/example_tcpecho
.PHONY : libs/evpp/examples/CMakeFiles/example_tcpecho.dir/build

libs/evpp/examples/CMakeFiles/example_tcpecho.dir/clean:
	cd /home/fhayha/Documentos/ByteRunnerDB/libs/evpp/examples && $(CMAKE_COMMAND) -P CMakeFiles/example_tcpecho.dir/cmake_clean.cmake
.PHONY : libs/evpp/examples/CMakeFiles/example_tcpecho.dir/clean

libs/evpp/examples/CMakeFiles/example_tcpecho.dir/depend:
	cd /home/fhayha/Documentos/ByteRunnerDB && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/fhayha/Documentos/ByteRunnerDB /home/fhayha/Documentos/ByteRunnerDB/libs/evpp/examples /home/fhayha/Documentos/ByteRunnerDB /home/fhayha/Documentos/ByteRunnerDB/libs/evpp/examples /home/fhayha/Documentos/ByteRunnerDB/libs/evpp/examples/CMakeFiles/example_tcpecho.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : libs/evpp/examples/CMakeFiles/example_tcpecho.dir/depend

