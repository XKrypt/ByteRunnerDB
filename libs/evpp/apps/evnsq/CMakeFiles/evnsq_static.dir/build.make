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
include libs/evpp/apps/evnsq/CMakeFiles/evnsq_static.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include libs/evpp/apps/evnsq/CMakeFiles/evnsq_static.dir/compiler_depend.make

# Include the progress variables for this target.
include libs/evpp/apps/evnsq/CMakeFiles/evnsq_static.dir/progress.make

# Include the compile flags for this target's objects.
include libs/evpp/apps/evnsq/CMakeFiles/evnsq_static.dir/flags.make

libs/evpp/apps/evnsq/CMakeFiles/evnsq_static.dir/client.cc.o: libs/evpp/apps/evnsq/CMakeFiles/evnsq_static.dir/flags.make
libs/evpp/apps/evnsq/CMakeFiles/evnsq_static.dir/client.cc.o: libs/evpp/apps/evnsq/client.cc
libs/evpp/apps/evnsq/CMakeFiles/evnsq_static.dir/client.cc.o: libs/evpp/apps/evnsq/CMakeFiles/evnsq_static.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fhayha/Documentos/ByteRunnerDB/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object libs/evpp/apps/evnsq/CMakeFiles/evnsq_static.dir/client.cc.o"
	cd /home/fhayha/Documentos/ByteRunnerDB/libs/evpp/apps/evnsq && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT libs/evpp/apps/evnsq/CMakeFiles/evnsq_static.dir/client.cc.o -MF CMakeFiles/evnsq_static.dir/client.cc.o.d -o CMakeFiles/evnsq_static.dir/client.cc.o -c /home/fhayha/Documentos/ByteRunnerDB/libs/evpp/apps/evnsq/client.cc

libs/evpp/apps/evnsq/CMakeFiles/evnsq_static.dir/client.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/evnsq_static.dir/client.cc.i"
	cd /home/fhayha/Documentos/ByteRunnerDB/libs/evpp/apps/evnsq && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fhayha/Documentos/ByteRunnerDB/libs/evpp/apps/evnsq/client.cc > CMakeFiles/evnsq_static.dir/client.cc.i

libs/evpp/apps/evnsq/CMakeFiles/evnsq_static.dir/client.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/evnsq_static.dir/client.cc.s"
	cd /home/fhayha/Documentos/ByteRunnerDB/libs/evpp/apps/evnsq && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fhayha/Documentos/ByteRunnerDB/libs/evpp/apps/evnsq/client.cc -o CMakeFiles/evnsq_static.dir/client.cc.s

libs/evpp/apps/evnsq/CMakeFiles/evnsq_static.dir/command.cc.o: libs/evpp/apps/evnsq/CMakeFiles/evnsq_static.dir/flags.make
libs/evpp/apps/evnsq/CMakeFiles/evnsq_static.dir/command.cc.o: libs/evpp/apps/evnsq/command.cc
libs/evpp/apps/evnsq/CMakeFiles/evnsq_static.dir/command.cc.o: libs/evpp/apps/evnsq/CMakeFiles/evnsq_static.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fhayha/Documentos/ByteRunnerDB/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object libs/evpp/apps/evnsq/CMakeFiles/evnsq_static.dir/command.cc.o"
	cd /home/fhayha/Documentos/ByteRunnerDB/libs/evpp/apps/evnsq && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT libs/evpp/apps/evnsq/CMakeFiles/evnsq_static.dir/command.cc.o -MF CMakeFiles/evnsq_static.dir/command.cc.o.d -o CMakeFiles/evnsq_static.dir/command.cc.o -c /home/fhayha/Documentos/ByteRunnerDB/libs/evpp/apps/evnsq/command.cc

libs/evpp/apps/evnsq/CMakeFiles/evnsq_static.dir/command.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/evnsq_static.dir/command.cc.i"
	cd /home/fhayha/Documentos/ByteRunnerDB/libs/evpp/apps/evnsq && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fhayha/Documentos/ByteRunnerDB/libs/evpp/apps/evnsq/command.cc > CMakeFiles/evnsq_static.dir/command.cc.i

libs/evpp/apps/evnsq/CMakeFiles/evnsq_static.dir/command.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/evnsq_static.dir/command.cc.s"
	cd /home/fhayha/Documentos/ByteRunnerDB/libs/evpp/apps/evnsq && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fhayha/Documentos/ByteRunnerDB/libs/evpp/apps/evnsq/command.cc -o CMakeFiles/evnsq_static.dir/command.cc.s

libs/evpp/apps/evnsq/CMakeFiles/evnsq_static.dir/consumer.cc.o: libs/evpp/apps/evnsq/CMakeFiles/evnsq_static.dir/flags.make
libs/evpp/apps/evnsq/CMakeFiles/evnsq_static.dir/consumer.cc.o: libs/evpp/apps/evnsq/consumer.cc
libs/evpp/apps/evnsq/CMakeFiles/evnsq_static.dir/consumer.cc.o: libs/evpp/apps/evnsq/CMakeFiles/evnsq_static.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fhayha/Documentos/ByteRunnerDB/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object libs/evpp/apps/evnsq/CMakeFiles/evnsq_static.dir/consumer.cc.o"
	cd /home/fhayha/Documentos/ByteRunnerDB/libs/evpp/apps/evnsq && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT libs/evpp/apps/evnsq/CMakeFiles/evnsq_static.dir/consumer.cc.o -MF CMakeFiles/evnsq_static.dir/consumer.cc.o.d -o CMakeFiles/evnsq_static.dir/consumer.cc.o -c /home/fhayha/Documentos/ByteRunnerDB/libs/evpp/apps/evnsq/consumer.cc

libs/evpp/apps/evnsq/CMakeFiles/evnsq_static.dir/consumer.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/evnsq_static.dir/consumer.cc.i"
	cd /home/fhayha/Documentos/ByteRunnerDB/libs/evpp/apps/evnsq && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fhayha/Documentos/ByteRunnerDB/libs/evpp/apps/evnsq/consumer.cc > CMakeFiles/evnsq_static.dir/consumer.cc.i

libs/evpp/apps/evnsq/CMakeFiles/evnsq_static.dir/consumer.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/evnsq_static.dir/consumer.cc.s"
	cd /home/fhayha/Documentos/ByteRunnerDB/libs/evpp/apps/evnsq && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fhayha/Documentos/ByteRunnerDB/libs/evpp/apps/evnsq/consumer.cc -o CMakeFiles/evnsq_static.dir/consumer.cc.s

libs/evpp/apps/evnsq/CMakeFiles/evnsq_static.dir/nsq_conn.cc.o: libs/evpp/apps/evnsq/CMakeFiles/evnsq_static.dir/flags.make
libs/evpp/apps/evnsq/CMakeFiles/evnsq_static.dir/nsq_conn.cc.o: libs/evpp/apps/evnsq/nsq_conn.cc
libs/evpp/apps/evnsq/CMakeFiles/evnsq_static.dir/nsq_conn.cc.o: libs/evpp/apps/evnsq/CMakeFiles/evnsq_static.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fhayha/Documentos/ByteRunnerDB/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object libs/evpp/apps/evnsq/CMakeFiles/evnsq_static.dir/nsq_conn.cc.o"
	cd /home/fhayha/Documentos/ByteRunnerDB/libs/evpp/apps/evnsq && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT libs/evpp/apps/evnsq/CMakeFiles/evnsq_static.dir/nsq_conn.cc.o -MF CMakeFiles/evnsq_static.dir/nsq_conn.cc.o.d -o CMakeFiles/evnsq_static.dir/nsq_conn.cc.o -c /home/fhayha/Documentos/ByteRunnerDB/libs/evpp/apps/evnsq/nsq_conn.cc

libs/evpp/apps/evnsq/CMakeFiles/evnsq_static.dir/nsq_conn.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/evnsq_static.dir/nsq_conn.cc.i"
	cd /home/fhayha/Documentos/ByteRunnerDB/libs/evpp/apps/evnsq && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fhayha/Documentos/ByteRunnerDB/libs/evpp/apps/evnsq/nsq_conn.cc > CMakeFiles/evnsq_static.dir/nsq_conn.cc.i

libs/evpp/apps/evnsq/CMakeFiles/evnsq_static.dir/nsq_conn.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/evnsq_static.dir/nsq_conn.cc.s"
	cd /home/fhayha/Documentos/ByteRunnerDB/libs/evpp/apps/evnsq && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fhayha/Documentos/ByteRunnerDB/libs/evpp/apps/evnsq/nsq_conn.cc -o CMakeFiles/evnsq_static.dir/nsq_conn.cc.s

libs/evpp/apps/evnsq/CMakeFiles/evnsq_static.dir/option.cc.o: libs/evpp/apps/evnsq/CMakeFiles/evnsq_static.dir/flags.make
libs/evpp/apps/evnsq/CMakeFiles/evnsq_static.dir/option.cc.o: libs/evpp/apps/evnsq/option.cc
libs/evpp/apps/evnsq/CMakeFiles/evnsq_static.dir/option.cc.o: libs/evpp/apps/evnsq/CMakeFiles/evnsq_static.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fhayha/Documentos/ByteRunnerDB/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object libs/evpp/apps/evnsq/CMakeFiles/evnsq_static.dir/option.cc.o"
	cd /home/fhayha/Documentos/ByteRunnerDB/libs/evpp/apps/evnsq && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT libs/evpp/apps/evnsq/CMakeFiles/evnsq_static.dir/option.cc.o -MF CMakeFiles/evnsq_static.dir/option.cc.o.d -o CMakeFiles/evnsq_static.dir/option.cc.o -c /home/fhayha/Documentos/ByteRunnerDB/libs/evpp/apps/evnsq/option.cc

libs/evpp/apps/evnsq/CMakeFiles/evnsq_static.dir/option.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/evnsq_static.dir/option.cc.i"
	cd /home/fhayha/Documentos/ByteRunnerDB/libs/evpp/apps/evnsq && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fhayha/Documentos/ByteRunnerDB/libs/evpp/apps/evnsq/option.cc > CMakeFiles/evnsq_static.dir/option.cc.i

libs/evpp/apps/evnsq/CMakeFiles/evnsq_static.dir/option.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/evnsq_static.dir/option.cc.s"
	cd /home/fhayha/Documentos/ByteRunnerDB/libs/evpp/apps/evnsq && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fhayha/Documentos/ByteRunnerDB/libs/evpp/apps/evnsq/option.cc -o CMakeFiles/evnsq_static.dir/option.cc.s

libs/evpp/apps/evnsq/CMakeFiles/evnsq_static.dir/producer.cc.o: libs/evpp/apps/evnsq/CMakeFiles/evnsq_static.dir/flags.make
libs/evpp/apps/evnsq/CMakeFiles/evnsq_static.dir/producer.cc.o: libs/evpp/apps/evnsq/producer.cc
libs/evpp/apps/evnsq/CMakeFiles/evnsq_static.dir/producer.cc.o: libs/evpp/apps/evnsq/CMakeFiles/evnsq_static.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fhayha/Documentos/ByteRunnerDB/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object libs/evpp/apps/evnsq/CMakeFiles/evnsq_static.dir/producer.cc.o"
	cd /home/fhayha/Documentos/ByteRunnerDB/libs/evpp/apps/evnsq && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT libs/evpp/apps/evnsq/CMakeFiles/evnsq_static.dir/producer.cc.o -MF CMakeFiles/evnsq_static.dir/producer.cc.o.d -o CMakeFiles/evnsq_static.dir/producer.cc.o -c /home/fhayha/Documentos/ByteRunnerDB/libs/evpp/apps/evnsq/producer.cc

libs/evpp/apps/evnsq/CMakeFiles/evnsq_static.dir/producer.cc.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/evnsq_static.dir/producer.cc.i"
	cd /home/fhayha/Documentos/ByteRunnerDB/libs/evpp/apps/evnsq && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fhayha/Documentos/ByteRunnerDB/libs/evpp/apps/evnsq/producer.cc > CMakeFiles/evnsq_static.dir/producer.cc.i

libs/evpp/apps/evnsq/CMakeFiles/evnsq_static.dir/producer.cc.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/evnsq_static.dir/producer.cc.s"
	cd /home/fhayha/Documentos/ByteRunnerDB/libs/evpp/apps/evnsq && /usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fhayha/Documentos/ByteRunnerDB/libs/evpp/apps/evnsq/producer.cc -o CMakeFiles/evnsq_static.dir/producer.cc.s

# Object files for target evnsq_static
evnsq_static_OBJECTS = \
"CMakeFiles/evnsq_static.dir/client.cc.o" \
"CMakeFiles/evnsq_static.dir/command.cc.o" \
"CMakeFiles/evnsq_static.dir/consumer.cc.o" \
"CMakeFiles/evnsq_static.dir/nsq_conn.cc.o" \
"CMakeFiles/evnsq_static.dir/option.cc.o" \
"CMakeFiles/evnsq_static.dir/producer.cc.o"

# External object files for target evnsq_static
evnsq_static_EXTERNAL_OBJECTS =

libs/evpp/lib/libevnsq_static.a: libs/evpp/apps/evnsq/CMakeFiles/evnsq_static.dir/client.cc.o
libs/evpp/lib/libevnsq_static.a: libs/evpp/apps/evnsq/CMakeFiles/evnsq_static.dir/command.cc.o
libs/evpp/lib/libevnsq_static.a: libs/evpp/apps/evnsq/CMakeFiles/evnsq_static.dir/consumer.cc.o
libs/evpp/lib/libevnsq_static.a: libs/evpp/apps/evnsq/CMakeFiles/evnsq_static.dir/nsq_conn.cc.o
libs/evpp/lib/libevnsq_static.a: libs/evpp/apps/evnsq/CMakeFiles/evnsq_static.dir/option.cc.o
libs/evpp/lib/libevnsq_static.a: libs/evpp/apps/evnsq/CMakeFiles/evnsq_static.dir/producer.cc.o
libs/evpp/lib/libevnsq_static.a: libs/evpp/apps/evnsq/CMakeFiles/evnsq_static.dir/build.make
libs/evpp/lib/libevnsq_static.a: libs/evpp/apps/evnsq/CMakeFiles/evnsq_static.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/fhayha/Documentos/ByteRunnerDB/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Linking CXX static library ../../lib/libevnsq_static.a"
	cd /home/fhayha/Documentos/ByteRunnerDB/libs/evpp/apps/evnsq && $(CMAKE_COMMAND) -P CMakeFiles/evnsq_static.dir/cmake_clean_target.cmake
	cd /home/fhayha/Documentos/ByteRunnerDB/libs/evpp/apps/evnsq && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/evnsq_static.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
libs/evpp/apps/evnsq/CMakeFiles/evnsq_static.dir/build: libs/evpp/lib/libevnsq_static.a
.PHONY : libs/evpp/apps/evnsq/CMakeFiles/evnsq_static.dir/build

libs/evpp/apps/evnsq/CMakeFiles/evnsq_static.dir/clean:
	cd /home/fhayha/Documentos/ByteRunnerDB/libs/evpp/apps/evnsq && $(CMAKE_COMMAND) -P CMakeFiles/evnsq_static.dir/cmake_clean.cmake
.PHONY : libs/evpp/apps/evnsq/CMakeFiles/evnsq_static.dir/clean

libs/evpp/apps/evnsq/CMakeFiles/evnsq_static.dir/depend:
	cd /home/fhayha/Documentos/ByteRunnerDB && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/fhayha/Documentos/ByteRunnerDB /home/fhayha/Documentos/ByteRunnerDB/libs/evpp/apps/evnsq /home/fhayha/Documentos/ByteRunnerDB /home/fhayha/Documentos/ByteRunnerDB/libs/evpp/apps/evnsq /home/fhayha/Documentos/ByteRunnerDB/libs/evpp/apps/evnsq/CMakeFiles/evnsq_static.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : libs/evpp/apps/evnsq/CMakeFiles/evnsq_static.dir/depend
