# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 2.8

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/jbr134/Documents/Development/aschWirzard/aschWizrd

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/jbr134/Documents/Development/aschWirzard/aschWizrd/build-sys-linux-x86_64

# Include any dependencies generated for this target.
include CMakeFiles/aschWizrd.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/aschWizrd.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/aschWizrd.dir/flags.make

CMakeFiles/aschWizrd.dir/main.cpp.o: CMakeFiles/aschWizrd.dir/flags.make
CMakeFiles/aschWizrd.dir/main.cpp.o: ../main.cpp
	$(CMAKE_COMMAND) -E cmake_progress_report /home/jbr134/Documents/Development/aschWirzard/aschWizrd/build-sys-linux-x86_64/CMakeFiles $(CMAKE_PROGRESS_1)
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Building CXX object CMakeFiles/aschWizrd.dir/main.cpp.o"
	/usr/bin/c++   $(CXX_DEFINES) $(CXX_FLAGS) -o CMakeFiles/aschWizrd.dir/main.cpp.o -c /home/jbr134/Documents/Development/aschWirzard/aschWizrd/main.cpp

CMakeFiles/aschWizrd.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/aschWizrd.dir/main.cpp.i"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -E /home/jbr134/Documents/Development/aschWirzard/aschWizrd/main.cpp > CMakeFiles/aschWizrd.dir/main.cpp.i

CMakeFiles/aschWizrd.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/aschWizrd.dir/main.cpp.s"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_FLAGS) -S /home/jbr134/Documents/Development/aschWirzard/aschWizrd/main.cpp -o CMakeFiles/aschWizrd.dir/main.cpp.s

CMakeFiles/aschWizrd.dir/main.cpp.o.requires:
.PHONY : CMakeFiles/aschWizrd.dir/main.cpp.o.requires

CMakeFiles/aschWizrd.dir/main.cpp.o.provides: CMakeFiles/aschWizrd.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/aschWizrd.dir/build.make CMakeFiles/aschWizrd.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/aschWizrd.dir/main.cpp.o.provides

CMakeFiles/aschWizrd.dir/main.cpp.o.provides.build: CMakeFiles/aschWizrd.dir/main.cpp.o

# Object files for target aschWizrd
aschWizrd_OBJECTS = \
"CMakeFiles/aschWizrd.dir/main.cpp.o"

# External object files for target aschWizrd
aschWizrd_EXTERNAL_OBJECTS =

sdk/bin/aschWizrd: CMakeFiles/aschWizrd.dir/main.cpp.o
sdk/bin/aschWizrd: CMakeFiles/aschWizrd.dir/build.make
sdk/bin/aschWizrd: CMakeFiles/aschWizrd.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --red --bold "Linking CXX executable sdk/bin/aschWizrd"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/aschWizrd.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/aschWizrd.dir/build: sdk/bin/aschWizrd
.PHONY : CMakeFiles/aschWizrd.dir/build

CMakeFiles/aschWizrd.dir/requires: CMakeFiles/aschWizrd.dir/main.cpp.o.requires
.PHONY : CMakeFiles/aschWizrd.dir/requires

CMakeFiles/aschWizrd.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/aschWizrd.dir/cmake_clean.cmake
.PHONY : CMakeFiles/aschWizrd.dir/clean

CMakeFiles/aschWizrd.dir/depend:
	cd /home/jbr134/Documents/Development/aschWirzard/aschWizrd/build-sys-linux-x86_64 && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/jbr134/Documents/Development/aschWirzard/aschWizrd /home/jbr134/Documents/Development/aschWirzard/aschWizrd /home/jbr134/Documents/Development/aschWirzard/aschWizrd/build-sys-linux-x86_64 /home/jbr134/Documents/Development/aschWirzard/aschWizrd/build-sys-linux-x86_64 /home/jbr134/Documents/Development/aschWirzard/aschWizrd/build-sys-linux-x86_64/CMakeFiles/aschWizrd.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/aschWizrd.dir/depend

