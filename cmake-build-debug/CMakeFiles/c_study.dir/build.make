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
CMAKE_COMMAND = /home/chiangfire/idea/clion-2020.2.4/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/chiangfire/idea/clion-2020.2.4/bin/cmake/linux/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/chiangfire/idea/workspace-cpp/c-study

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/chiangfire/idea/workspace-cpp/c-study/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/c_study.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/c_study.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/c_study.dir/flags.make

CMakeFiles/c_study.dir/helloword/c-08-pointer.cpp.o: CMakeFiles/c_study.dir/flags.make
CMakeFiles/c_study.dir/helloword/c-08-pointer.cpp.o: ../helloword/c-08-pointer.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/chiangfire/idea/workspace-cpp/c-study/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/c_study.dir/helloword/c-08-pointer.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/c_study.dir/helloword/c-08-pointer.cpp.o -c /home/chiangfire/idea/workspace-cpp/c-study/helloword/c-08-pointer.cpp

CMakeFiles/c_study.dir/helloword/c-08-pointer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/c_study.dir/helloword/c-08-pointer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/chiangfire/idea/workspace-cpp/c-study/helloword/c-08-pointer.cpp > CMakeFiles/c_study.dir/helloword/c-08-pointer.cpp.i

CMakeFiles/c_study.dir/helloword/c-08-pointer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/c_study.dir/helloword/c-08-pointer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/chiangfire/idea/workspace-cpp/c-study/helloword/c-08-pointer.cpp -o CMakeFiles/c_study.dir/helloword/c-08-pointer.cpp.s

# Object files for target c_study
c_study_OBJECTS = \
"CMakeFiles/c_study.dir/helloword/c-08-pointer.cpp.o"

# External object files for target c_study
c_study_EXTERNAL_OBJECTS =

c_study: CMakeFiles/c_study.dir/helloword/c-08-pointer.cpp.o
c_study: CMakeFiles/c_study.dir/build.make
c_study: CMakeFiles/c_study.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/chiangfire/idea/workspace-cpp/c-study/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable c_study"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/c_study.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/c_study.dir/build: c_study

.PHONY : CMakeFiles/c_study.dir/build

CMakeFiles/c_study.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/c_study.dir/cmake_clean.cmake
.PHONY : CMakeFiles/c_study.dir/clean

CMakeFiles/c_study.dir/depend:
	cd /home/chiangfire/idea/workspace-cpp/c-study/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/chiangfire/idea/workspace-cpp/c-study /home/chiangfire/idea/workspace-cpp/c-study /home/chiangfire/idea/workspace-cpp/c-study/cmake-build-debug /home/chiangfire/idea/workspace-cpp/c-study/cmake-build-debug /home/chiangfire/idea/workspace-cpp/c-study/cmake-build-debug/CMakeFiles/c_study.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/c_study.dir/depend

