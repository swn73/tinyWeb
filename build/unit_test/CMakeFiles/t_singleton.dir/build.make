# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.4

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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.4.3/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.4.3/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/hualin/github/tinyWeb/src

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/hualin/github/tinyWeb/build

# Include any dependencies generated for this target.
include unit_test/CMakeFiles/t_singleton.dir/depend.make

# Include the progress variables for this target.
include unit_test/CMakeFiles/t_singleton.dir/progress.make

# Include the compile flags for this target's objects.
include unit_test/CMakeFiles/t_singleton.dir/flags.make

unit_test/CMakeFiles/t_singleton.dir/t_singleton.cpp.o: unit_test/CMakeFiles/t_singleton.dir/flags.make
unit_test/CMakeFiles/t_singleton.dir/t_singleton.cpp.o: /Users/hualin/github/tinyWeb/src/unit_test/t_singleton.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/hualin/github/tinyWeb/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object unit_test/CMakeFiles/t_singleton.dir/t_singleton.cpp.o"
	cd /Users/hualin/github/tinyWeb/build/unit_test && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++   $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/t_singleton.dir/t_singleton.cpp.o -c /Users/hualin/github/tinyWeb/src/unit_test/t_singleton.cpp

unit_test/CMakeFiles/t_singleton.dir/t_singleton.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/t_singleton.dir/t_singleton.cpp.i"
	cd /Users/hualin/github/tinyWeb/build/unit_test && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/hualin/github/tinyWeb/src/unit_test/t_singleton.cpp > CMakeFiles/t_singleton.dir/t_singleton.cpp.i

unit_test/CMakeFiles/t_singleton.dir/t_singleton.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/t_singleton.dir/t_singleton.cpp.s"
	cd /Users/hualin/github/tinyWeb/build/unit_test && /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/hualin/github/tinyWeb/src/unit_test/t_singleton.cpp -o CMakeFiles/t_singleton.dir/t_singleton.cpp.s

unit_test/CMakeFiles/t_singleton.dir/t_singleton.cpp.o.requires:

.PHONY : unit_test/CMakeFiles/t_singleton.dir/t_singleton.cpp.o.requires

unit_test/CMakeFiles/t_singleton.dir/t_singleton.cpp.o.provides: unit_test/CMakeFiles/t_singleton.dir/t_singleton.cpp.o.requires
	$(MAKE) -f unit_test/CMakeFiles/t_singleton.dir/build.make unit_test/CMakeFiles/t_singleton.dir/t_singleton.cpp.o.provides.build
.PHONY : unit_test/CMakeFiles/t_singleton.dir/t_singleton.cpp.o.provides

unit_test/CMakeFiles/t_singleton.dir/t_singleton.cpp.o.provides.build: unit_test/CMakeFiles/t_singleton.dir/t_singleton.cpp.o


# Object files for target t_singleton
t_singleton_OBJECTS = \
"CMakeFiles/t_singleton.dir/t_singleton.cpp.o"

# External object files for target t_singleton
t_singleton_EXTERNAL_OBJECTS =

unit_test/t_singleton: unit_test/CMakeFiles/t_singleton.dir/t_singleton.cpp.o
unit_test/t_singleton: unit_test/CMakeFiles/t_singleton.dir/build.make
unit_test/t_singleton: unit_test/CMakeFiles/t_singleton.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/hualin/github/tinyWeb/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable t_singleton"
	cd /Users/hualin/github/tinyWeb/build/unit_test && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/t_singleton.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
unit_test/CMakeFiles/t_singleton.dir/build: unit_test/t_singleton

.PHONY : unit_test/CMakeFiles/t_singleton.dir/build

unit_test/CMakeFiles/t_singleton.dir/requires: unit_test/CMakeFiles/t_singleton.dir/t_singleton.cpp.o.requires

.PHONY : unit_test/CMakeFiles/t_singleton.dir/requires

unit_test/CMakeFiles/t_singleton.dir/clean:
	cd /Users/hualin/github/tinyWeb/build/unit_test && $(CMAKE_COMMAND) -P CMakeFiles/t_singleton.dir/cmake_clean.cmake
.PHONY : unit_test/CMakeFiles/t_singleton.dir/clean

unit_test/CMakeFiles/t_singleton.dir/depend:
	cd /Users/hualin/github/tinyWeb/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/hualin/github/tinyWeb/src /Users/hualin/github/tinyWeb/src/unit_test /Users/hualin/github/tinyWeb/build /Users/hualin/github/tinyWeb/build/unit_test /Users/hualin/github/tinyWeb/build/unit_test/CMakeFiles/t_singleton.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : unit_test/CMakeFiles/t_singleton.dir/depend
