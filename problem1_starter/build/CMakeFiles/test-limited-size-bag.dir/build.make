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
CMAKE_SOURCE_DIR = C:\Users\gkyen\OneDrive\Documents\ece0302\ECE-0302\problem1_starter

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\gkyen\OneDrive\Documents\ece0302\ECE-0302\problem1_starter\build

# Include any dependencies generated for this target.
include CMakeFiles/test-limited-size-bag.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/test-limited-size-bag.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/test-limited-size-bag.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test-limited-size-bag.dir/flags.make

CMakeFiles/test-limited-size-bag.dir/test_limited_size_bag.cpp.obj: CMakeFiles/test-limited-size-bag.dir/flags.make
CMakeFiles/test-limited-size-bag.dir/test_limited_size_bag.cpp.obj: C:/Users/gkyen/OneDrive/Documents/ece0302/ECE-0302/problem1_starter/test_limited_size_bag.cpp
CMakeFiles/test-limited-size-bag.dir/test_limited_size_bag.cpp.obj: CMakeFiles/test-limited-size-bag.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\gkyen\OneDrive\Documents\ece0302\ECE-0302\problem1_starter\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test-limited-size-bag.dir/test_limited_size_bag.cpp.obj"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/test-limited-size-bag.dir/test_limited_size_bag.cpp.obj -MF CMakeFiles\test-limited-size-bag.dir\test_limited_size_bag.cpp.obj.d -o CMakeFiles\test-limited-size-bag.dir\test_limited_size_bag.cpp.obj -c C:\Users\gkyen\OneDrive\Documents\ece0302\ECE-0302\problem1_starter\test_limited_size_bag.cpp

CMakeFiles/test-limited-size-bag.dir/test_limited_size_bag.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/test-limited-size-bag.dir/test_limited_size_bag.cpp.i"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\gkyen\OneDrive\Documents\ece0302\ECE-0302\problem1_starter\test_limited_size_bag.cpp > CMakeFiles\test-limited-size-bag.dir\test_limited_size_bag.cpp.i

CMakeFiles/test-limited-size-bag.dir/test_limited_size_bag.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/test-limited-size-bag.dir/test_limited_size_bag.cpp.s"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\gkyen\OneDrive\Documents\ece0302\ECE-0302\problem1_starter\test_limited_size_bag.cpp -o CMakeFiles\test-limited-size-bag.dir\test_limited_size_bag.cpp.s

# Object files for target test-limited-size-bag
test__limited__size__bag_OBJECTS = \
"CMakeFiles/test-limited-size-bag.dir/test_limited_size_bag.cpp.obj"

# External object files for target test-limited-size-bag
test__limited__size__bag_EXTERNAL_OBJECTS =

test-limited-size-bag.exe: CMakeFiles/test-limited-size-bag.dir/test_limited_size_bag.cpp.obj
test-limited-size-bag.exe: CMakeFiles/test-limited-size-bag.dir/build.make
test-limited-size-bag.exe: CMakeFiles/test-limited-size-bag.dir/linkLibs.rsp
test-limited-size-bag.exe: CMakeFiles/test-limited-size-bag.dir/objects1.rsp
test-limited-size-bag.exe: CMakeFiles/test-limited-size-bag.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\gkyen\OneDrive\Documents\ece0302\ECE-0302\problem1_starter\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test-limited-size-bag.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\test-limited-size-bag.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test-limited-size-bag.dir/build: test-limited-size-bag.exe
.PHONY : CMakeFiles/test-limited-size-bag.dir/build

CMakeFiles/test-limited-size-bag.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\test-limited-size-bag.dir\cmake_clean.cmake
.PHONY : CMakeFiles/test-limited-size-bag.dir/clean

CMakeFiles/test-limited-size-bag.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\gkyen\OneDrive\Documents\ece0302\ECE-0302\problem1_starter C:\Users\gkyen\OneDrive\Documents\ece0302\ECE-0302\problem1_starter C:\Users\gkyen\OneDrive\Documents\ece0302\ECE-0302\problem1_starter\build C:\Users\gkyen\OneDrive\Documents\ece0302\ECE-0302\problem1_starter\build C:\Users\gkyen\OneDrive\Documents\ece0302\ECE-0302\problem1_starter\build\CMakeFiles\test-limited-size-bag.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/test-limited-size-bag.dir/depend

