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
include libs/evpp/benchmark/throughput/evpp/CMakeFiles/benchmark_pingpong_client_fixed_size.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include libs/evpp/benchmark/throughput/evpp/CMakeFiles/benchmark_pingpong_client_fixed_size.dir/compiler_depend.make

# Include the progress variables for this target.
include libs/evpp/benchmark/throughput/evpp/CMakeFiles/benchmark_pingpong_client_fixed_size.dir/progress.make

# Include the compile flags for this target's objects.
include libs/evpp/benchmark/throughput/evpp/CMakeFiles/benchmark_pingpong_client_fixed_size.dir/flags.make

libs/evpp/benchmark/throughput/evpp/CMakeFiles/benchmark_pingpong_client_fixed_size.dir/client_fixed_size.cc.o: libs/evpp/benchmark/throughput/evpp/CMakeFiles/benchmark_pingpong_client_fixed_size.dir/flags.make
libs/evpp/benchmark/throughput/evpp/CMakeFiles/benchmark_pingpong_client_fixed_size.dir/client_fixed_size.cc.o: libs/evpp/benchmark/throughput/evpp/client_fixed_size.cc
libs/evpp/benchmark/throughput/evpp/CMakeFiles/benchmark_pingpong_client_fixed_size.dir/client_fixed_size.cc.o: libs/evpp/benchmark/throughput/evpp/CMakeFiles/benchmark_pingpong_client_fixed_size.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fhayha/Documentos/ByteRunnerDB/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object libs/evpp/benchmark/throughput/evpp/CMakeFiles/benchmark_pingpong_client_fixed_size.dir/client_fixed_size.cc.o"
	cd /home/fhayha/Documentos/ByteRunnerDB/libs/evpp/benchmark/throughput/evpp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT libs/evpp/benchmark/throughput/evpp/CMakeFiles/benchmark_pingpong_client_fixed_size.dir/client_fixed_size.cc.o -MF CMakeFiles/benchmark_pingpong_client_fixed_size.dir/client_fixed_size.cc.o.d -o CMakeFiles/benchmark_pingpong_client_fixed_size.dir/client_fixed_size.cc.o -c /home/fhayha/Documentos/ByteRunnerDB/libs/evpp/benchmark/throughput/evpp/client_fixed_size.cc

libs/evpp/benchmark/throughput/evpp/CMakeFiles/benchmark_pingpong_client_fixed_size.dir/client_fixed_size.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/benchmark_pingpong_client_fixed_size.dir/client_fixed_size.cc.i"
	cd /home/fhayha/Documentos/ByteRunnerDB/libs/evpp/benchmark/throughput/evpp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fhayha/Documentos/ByteRunnerDB/libs/evpp/benchmark/throughput/evpp/client_fixed_size.cc > CMakeFiles/benchmark_pingpong_client_fixed_size.dir/client_fixed_size.cc.i

libs/evpp/benchmark/throughput/evpp/CMakeFiles/benchmark_pingpong_client_fixed_size.dir/client_fixed_size.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/benchmark_pingpong_client_fixed_size.dir/client_fixed_size.cc.s"
	cd /home/fhayha/Documentos/ByteRunnerDB/libs/evpp/benchmark/throughput/evpp && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fhayha/Documentos/ByteRunnerDB/libs/evpp/benchmark/throughput/evpp/client_fixed_size.cc -o CMakeFiles/benchmark_pingpong_client_fixed_size.dir/client_fixed_size.cc.s

# Object files for target benchmark_pingpong_client_fixed_size
benchmark_pingpong_client_fixed_size_OBJECTS = \
"CMakeFiles/benchmark_pingpong_client_fixed_size.dir/client_fixed_size.cc.o"

# External object files for target benchmark_pingpong_client_fixed_size
benchmark_pingpong_client_fixed_size_EXTERNAL_OBJECTS =

libs/evpp/bin/benchmark_pingpong_client_fixed_size: libs/evpp/benchmark/throughput/evpp/CMakeFiles/benchmark_pingpong_client_fixed_size.dir/client_fixed_size.cc.o
libs/evpp/bin/benchmark_pingpong_client_fixed_size: libs/evpp/benchmark/throughput/evpp/CMakeFiles/benchmark_pingpong_client_fixed_size.dir/build.make
libs/evpp/bin/benchmark_pingpong_client_fixed_size: libs/evpp/lib/libevpp_static.a
libs/evpp/bin/benchmark_pingpong_client_fixed_size: libs/evpp/benchmark/throughput/evpp/CMakeFiles/benchmark_pingpong_client_fixed_size.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/fhayha/Documentos/ByteRunnerDB/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../../bin/benchmark_pingpong_client_fixed_size"
	cd /home/fhayha/Documentos/ByteRunnerDB/libs/evpp/benchmark/throughput/evpp && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/benchmark_pingpong_client_fixed_size.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
libs/evpp/benchmark/throughput/evpp/CMakeFiles/benchmark_pingpong_client_fixed_size.dir/build: libs/evpp/bin/benchmark_pingpong_client_fixed_size
.PHONY : libs/evpp/benchmark/throughput/evpp/CMakeFiles/benchmark_pingpong_client_fixed_size.dir/build

libs/evpp/benchmark/throughput/evpp/CMakeFiles/benchmark_pingpong_client_fixed_size.dir/clean:
	cd /home/fhayha/Documentos/ByteRunnerDB/libs/evpp/benchmark/throughput/evpp && $(CMAKE_COMMAND) -P CMakeFiles/benchmark_pingpong_client_fixed_size.dir/cmake_clean.cmake
.PHONY : libs/evpp/benchmark/throughput/evpp/CMakeFiles/benchmark_pingpong_client_fixed_size.dir/clean

libs/evpp/benchmark/throughput/evpp/CMakeFiles/benchmark_pingpong_client_fixed_size.dir/depend:
	cd /home/fhayha/Documentos/ByteRunnerDB && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/fhayha/Documentos/ByteRunnerDB /home/fhayha/Documentos/ByteRunnerDB/libs/evpp/benchmark/throughput/evpp /home/fhayha/Documentos/ByteRunnerDB /home/fhayha/Documentos/ByteRunnerDB/libs/evpp/benchmark/throughput/evpp /home/fhayha/Documentos/ByteRunnerDB/libs/evpp/benchmark/throughput/evpp/CMakeFiles/benchmark_pingpong_client_fixed_size.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : libs/evpp/benchmark/throughput/evpp/CMakeFiles/benchmark_pingpong_client_fixed_size.dir/depend

