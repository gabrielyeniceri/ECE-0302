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
CMAKE_SOURCE_DIR = C:\Users\gkyen\OneDrive\Documents\ece0302\ECE-0302\problem8_starter

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\gkyen\OneDrive\Documents\ece0302\ECE-0302\problem8_starter\build

# Include any dependencies generated for this target.
include CMakeFiles/test-heap.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/test-heap.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/test-heap.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/test-heap.dir/flags.make

CMakeFiles/test-heap.dir/test_heap.cpp.obj: CMakeFiles/test-heap.dir/flags.make
CMakeFiles/test-heap.dir/test_heap.cpp.obj: C:/Users/gkyen/OneDrive/Documents/ece0302/ECE-0302/problem8_starter/test_heap.cpp
CMakeFiles/test-heap.dir/test_heap.cpp.obj: CMakeFiles/test-heap.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=C:\Users\gkyen\OneDrive\Documents\ece0302\ECE-0302\problem8_starter\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/test-heap.dir/test_heap.cpp.obj"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/test-heap.dir/test_heap.cpp.obj -MF CMakeFiles\test-heap.dir\test_heap.cpp.obj.d -o CMakeFiles\test-heap.dir\test_heap.cpp.obj -c C:\Users\gkyen\OneDrive\Documents\ece0302\ECE-0302\problem8_starter\test_heap.cpp

CMakeFiles/test-heap.dir/test_heap.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/test-heap.dir/test_heap.cpp.i"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E C:\Users\gkyen\OneDrive\Documents\ece0302\ECE-0302\problem8_starter\test_heap.cpp > CMakeFiles\test-heap.dir\test_heap.cpp.i

CMakeFiles/test-heap.dir/test_heap.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/test-heap.dir/test_heap.cpp.s"
	C:\msys64\ucrt64\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S C:\Users\gkyen\OneDrive\Documents\ece0302\ECE-0302\problem8_starter\test_heap.cpp -o CMakeFiles\test-heap.dir\test_heap.cpp.s

# Object files for target test-heap
test__heap_OBJECTS = \
"CMakeFiles/test-heap.dir/test_heap.cpp.obj"

# External object files for target test-heap
test__heap_EXTERNAL_OBJECTS =

test-heap.exe: CMakeFiles/test-heap.dir/test_heap.cpp.obj
test-heap.exe: CMakeFiles/test-heap.dir/build.make
test-heap.exe: CMakeFiles/test-heap.dir/linkLibs.rsp
test-heap.exe: CMakeFiles/test-heap.dir/objects1.rsp
test-heap.exe: CMakeFiles/test-heap.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=C:\Users\gkyen\OneDrive\Documents\ece0302\ECE-0302\problem8_starter\build\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable test-heap.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\test-heap.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/test-heap.dir/build: test-heap.exe
.PHONY : CMakeFiles/test-heap.dir/build

CMakeFiles/test-heap.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\test-heap.dir\cmake_clean.cmake
.PHONY : CMakeFiles/test-heap.dir/clean

CMakeFiles/test-heap.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\gkyen\OneDrive\Documents\ece0302\ECE-0302\problem8_starter C:\Users\gkyen\OneDrive\Documents\ece0302\ECE-0302\problem8_starter C:\Users\gkyen\OneDrive\Documents\ece0302\ECE-0302\problem8_starter\build C:\Users\gkyen\OneDrive\Documents\ece0302\ECE-0302\problem8_starter\build C:\Users\gkyen\OneDrive\Documents\ece0302\ECE-0302\problem8_starter\build\CMakeFiles\test-heap.dir\DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/test-heap.dir/depend

