# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.30

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "C:\Program Files\CMake\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\CMake\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\gkyen\OneDrive\Documents\ece0302\ECE-0302\Lec22_23

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\gkyen\OneDrive\Documents\ece0302\ECE-0302\Lec22_23\build

# Include any dependencies generated for this target.
include CMakeFiles/test_more_trees.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/test_more_trees.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/test_more_trees.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test_more_trees.dir/flags.make

CMakeFiles/test_more_trees.dir/test_more_trees.cpp.obj: CMakeFiles/test_more_trees.dir/flags.make
CMakeFiles/test_more_trees.dir/test_more_trees.cpp.obj: C:/Users/gkyen/OneDrive/Documents/ece0302/ECE-0302/Lec22_23/test_more_trees.cpp
CMakeFiles/test_more_trees.dir/test_more_trees.cpp.obj: CMakeFiles/test_more_trees.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\gkyen\OneDrive\Documents\ece0302\ECE-0302\Lec22_23\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test_more_trees.dir/test_more_trees.cpp.obj"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/test_more_trees.dir/test_more_trees.cpp.obj -MF CMakeFiles\test_more_trees.dir\test_more_trees.cpp.obj.d -o CMakeFiles\test_more_trees.dir\test_more_trees.cpp.obj -c C:\Users\gkyen\OneDrive\Documents\ece0302\ECE-0302\Lec22_23\test_more_trees.cpp

CMakeFiles/test_more_trees.dir/test_more_trees.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/test_more_trees.dir/test_more_trees.cpp.i"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\gkyen\OneDrive\Documents\ece0302\ECE-0302\Lec22_23\test_more_trees.cpp > CMakeFiles\test_more_trees.dir\test_more_trees.cpp.i

CMakeFiles/test_more_trees.dir/test_more_trees.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/test_more_trees.dir/test_more_trees.cpp.s"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\gkyen\OneDrive\Documents\ece0302\ECE-0302\Lec22_23\test_more_trees.cpp -o CMakeFiles\test_more_trees.dir\test_more_trees.cpp.s

# Object files for target test_more_trees
test_more_trees_OBJECTS = \
"CMakeFiles/test_more_trees.dir/test_more_trees.cpp.obj"

# External object files for target test_more_trees
test_more_trees_EXTERNAL_OBJECTS =

test_more_trees.exe: CMakeFiles/test_more_trees.dir/test_more_trees.cpp.obj
test_more_trees.exe: CMakeFiles/test_more_trees.dir/build.make
test_more_trees.exe: CMakeFiles/test_more_trees.dir/linkLibs.rsp
test_more_trees.exe: CMakeFiles/test_more_trees.dir/objects1.rsp
test_more_trees.exe: CMakeFiles/test_more_trees.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\gkyen\OneDrive\Documents\ece0302\ECE-0302\Lec22_23\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test_more_trees.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\test_more_trees.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test_more_trees.dir/build: test_more_trees.exe
.PHONY : CMakeFiles/test_more_trees.dir/build

CMakeFiles/test_more_trees.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\test_more_trees.dir\cmake_clean.cmake
.PHONY : CMakeFiles/test_more_trees.dir/clean

CMakeFiles/test_more_trees.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\gkyen\OneDrive\Documents\ece0302\ECE-0302\Lec22_23 C:\Users\gkyen\OneDrive\Documents\ece0302\ECE-0302\Lec22_23 C:\Users\gkyen\OneDrive\Documents\ece0302\ECE-0302\Lec22_23\build C:\Users\gkyen\OneDrive\Documents\ece0302\ECE-0302\Lec22_23\build C:\Users\gkyen\OneDrive\Documents\ece0302\ECE-0302\Lec22_23\build\CMakeFiles\test_more_trees.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/test_more_trees.dir/depend

