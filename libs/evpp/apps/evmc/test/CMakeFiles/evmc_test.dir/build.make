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
include libs/evpp/apps/evmc/test/CMakeFiles/evmc_test.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include libs/evpp/apps/evmc/test/CMakeFiles/evmc_test.dir/compiler_depend.make

# Include the progress variables for this target.
include libs/evpp/apps/evmc/test/CMakeFiles/evmc_test.dir/progress.make

# Include the compile flags for this target's objects.
include libs/evpp/apps/evmc/test/CMakeFiles/evmc_test.dir/flags.make

libs/evpp/apps/evmc/test/CMakeFiles/evmc_test.dir/mcpool_test.cc.o: libs/evpp/apps/evmc/test/CMakeFiles/evmc_test.dir/flags.make
libs/evpp/apps/evmc/test/CMakeFiles/evmc_test.dir/mcpool_test.cc.o: libs/evpp/apps/evmc/test/mcpool_test.cc
libs/evpp/apps/evmc/test/CMakeFiles/evmc_test.dir/mcpool_test.cc.o: libs/evpp/apps/evmc/test/CMakeFiles/evmc_test.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fhayha/Documentos/ByteRunnerDB/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object libs/evpp/apps/evmc/test/CMakeFiles/evmc_test.dir/mcpool_test.cc.o"
	cd /home/fhayha/Documentos/ByteRunnerDB/libs/evpp/apps/evmc/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT libs/evpp/apps/evmc/test/CMakeFiles/evmc_test.dir/mcpool_test.cc.o -MF CMakeFiles/evmc_test.dir/mcpool_test.cc.o.d -o CMakeFiles/evmc_test.dir/mcpool_test.cc.o -c /home/fhayha/Documentos/ByteRunnerDB/libs/evpp/apps/evmc/test/mcpool_test.cc

libs/evpp/apps/evmc/test/CMakeFiles/evmc_test.dir/mcpool_test.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/evmc_test.dir/mcpool_test.cc.i"
	cd /home/fhayha/Documentos/ByteRunnerDB/libs/evpp/apps/evmc/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fhayha/Documentos/ByteRunnerDB/libs/evpp/apps/evmc/test/mcpool_test.cc > CMakeFiles/evmc_test.dir/mcpool_test.cc.i

libs/evpp/apps/evmc/test/CMakeFiles/evmc_test.dir/mcpool_test.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/evmc_test.dir/mcpool_test.cc.s"
	cd /home/fhayha/Documentos/ByteRunnerDB/libs/evpp/apps/evmc/test && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fhayha/Documentos/ByteRunnerDB/libs/evpp/apps/evmc/test/mcpool_test.cc -o CMakeFiles/evmc_test.dir/mcpool_test.cc.s

# Object files for target evmc_test
evmc_test_OBJECTS = \
"CMakeFiles/evmc_test.dir/mcpool_test.cc.o"

# External object files for target evmc_test
evmc_test_EXTERNAL_OBJECTS =

libs/evpp/bin/evmc_test: libs/evpp/apps/evmc/test/CMakeFiles/evmc_test.dir/mcpool_test.cc.o
libs/evpp/bin/evmc_test: libs/evpp/apps/evmc/test/CMakeFiles/evmc_test.dir/build.make
libs/evpp/bin/evmc_test: libs/evpp/lib/libevmc_static.a
libs/evpp/bin/evmc_test: libs/evpp/lib/libevpp_concurrentqueue.so.0.7.0.0
libs/evpp/bin/evmc_test: libs/evpp/apps/evmc/test/CMakeFiles/evmc_test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/fhayha/Documentos/ByteRunnerDB/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable ../../../bin/evmc_test"
	cd /home/fhayha/Documentos/ByteRunnerDB/libs/evpp/apps/evmc/test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/evmc_test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
libs/evpp/apps/evmc/test/CMakeFiles/evmc_test.dir/build: libs/evpp/bin/evmc_test
.PHONY : libs/evpp/apps/evmc/test/CMakeFiles/evmc_test.dir/build

libs/evpp/apps/evmc/test/CMakeFiles/evmc_test.dir/clean:
	cd /home/fhayha/Documentos/ByteRunnerDB/libs/evpp/apps/evmc/test && $(CMAKE_COMMAND) -P CMakeFiles/evmc_test.dir/cmake_clean.cmake
.PHONY : libs/evpp/apps/evmc/test/CMakeFiles/evmc_test.dir/clean

libs/evpp/apps/evmc/test/CMakeFiles/evmc_test.dir/depend:
	cd /home/fhayha/Documentos/ByteRunnerDB && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/fhayha/Documentos/ByteRunnerDB /home/fhayha/Documentos/ByteRunnerDB/libs/evpp/apps/evmc/test /home/fhayha/Documentos/ByteRunnerDB /home/fhayha/Documentos/ByteRunnerDB/libs/evpp/apps/evmc/test /home/fhayha/Documentos/ByteRunnerDB/libs/evpp/apps/evmc/test/CMakeFiles/evmc_test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : libs/evpp/apps/evmc/test/CMakeFiles/evmc_test.dir/depend

