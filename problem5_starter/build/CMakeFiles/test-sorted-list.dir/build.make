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
CMAKE_SOURCE_DIR = C:\Users\gkyen\OneDrive\Documents\ece0302\ECE-0302\problem5_starter

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\gkyen\OneDrive\Documents\ece0302\ECE-0302\problem5_starter\build

# Include any dependencies generated for this target.
include CMakeFiles/test-sorted-list.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/test-sorted-list.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/test-sorted-list.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test-sorted-list.dir/flags.make

CMakeFiles/test-sorted-list.dir/test_sorted_list.cpp.obj: CMakeFiles/test-sorted-list.dir/flags.make
CMakeFiles/test-sorted-list.dir/test_sorted_list.cpp.obj: C:/Users/gkyen/OneDrive/Documents/ece0302/ECE-0302/problem5_starter/test_sorted_list.cpp
CMakeFiles/test-sorted-list.dir/test_sorted_list.cpp.obj: CMakeFiles/test-sorted-list.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\gkyen\OneDrive\Documents\ece0302\ECE-0302\problem5_starter\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test-sorted-list.dir/test_sorted_list.cpp.obj"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/test-sorted-list.dir/test_sorted_list.cpp.obj -MF CMakeFiles\test-sorted-list.dir\test_sorted_list.cpp.obj.d -o CMakeFiles\test-sorted-list.dir\test_sorted_list.cpp.obj -c C:\Users\gkyen\OneDrive\Documents\ece0302\ECE-0302\problem5_starter\test_sorted_list.cpp

CMakeFiles/test-sorted-list.dir/test_sorted_list.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/test-sorted-list.dir/test_sorted_list.cpp.i"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\gkyen\OneDrive\Documents\ece0302\ECE-0302\problem5_starter\test_sorted_list.cpp > CMakeFiles\test-sorted-list.dir\test_sorted_list.cpp.i

CMakeFiles/test-sorted-list.dir/test_sorted_list.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/test-sorted-list.dir/test_sorted_list.cpp.s"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\gkyen\OneDrive\Documents\ece0302\ECE-0302\problem5_starter\test_sorted_list.cpp -o CMakeFiles\test-sorted-list.dir\test_sorted_list.cpp.s

# Object files for target test-sorted-list
test__sorted__list_OBJECTS = \
"CMakeFiles/test-sorted-list.dir/test_sorted_list.cpp.obj"

# External object files for target test-sorted-list
test__sorted__list_EXTERNAL_OBJECTS =

test-sorted-list.exe: CMakeFiles/test-sorted-list.dir/test_sorted_list.cpp.obj
test-sorted-list.exe: CMakeFiles/test-sorted-list.dir/build.make
test-sorted-list.exe: CMakeFiles/test-sorted-list.dir/linkLibs.rsp
test-sorted-list.exe: CMakeFiles/test-sorted-list.dir/objects1.rsp
test-sorted-list.exe: CMakeFiles/test-sorted-list.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\gkyen\OneDrive\Documents\ece0302\ECE-0302\problem5_starter\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test-sorted-list.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\test-sorted-list.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test-sorted-list.dir/build: test-sorted-list.exe
.PHONY : CMakeFiles/test-sorted-list.dir/build

CMakeFiles/test-sorted-list.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\test-sorted-list.dir\cmake_clean.cmake
.PHONY : CMakeFiles/test-sorted-list.dir/clean

CMakeFiles/test-sorted-list.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\gkyen\OneDrive\Documents\ece0302\ECE-0302\problem5_starter C:\Users\gkyen\OneDrive\Documents\ece0302\ECE-0302\problem5_starter C:\Users\gkyen\OneDrive\Documents\ece0302\ECE-0302\problem5_starter\build C:\Users\gkyen\OneDrive\Documents\ece0302\ECE-0302\problem5_starter\build C:\Users\gkyen\OneDrive\Documents\ece0302\ECE-0302\problem5_starter\build\CMakeFiles\test-sorted-list.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/test-sorted-list.dir/depend

