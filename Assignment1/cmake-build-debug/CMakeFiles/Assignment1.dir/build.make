# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.15

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
CMAKE_COMMAND = /home/lior/Downloads/clion-2019.2.5/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/lior/Downloads/clion-2019.2.5/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/lior/CLionProjects/SPLFLIX/Assignment1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lior/CLionProjects/SPLFLIX/Assignment1/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/Assignment1.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Assignment1.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Assignment1.dir/flags.make

CMakeFiles/Assignment1.dir/src/Main.cpp.o: CMakeFiles/Assignment1.dir/flags.make
CMakeFiles/Assignment1.dir/src/Main.cpp.o: ../src/Main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lior/CLionProjects/SPLFLIX/Assignment1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Assignment1.dir/src/Main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Assignment1.dir/src/Main.cpp.o -c /home/lior/CLionProjects/SPLFLIX/Assignment1/src/Main.cpp

CMakeFiles/Assignment1.dir/src/Main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Assignment1.dir/src/Main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lior/CLionProjects/SPLFLIX/Assignment1/src/Main.cpp > CMakeFiles/Assignment1.dir/src/Main.cpp.i

CMakeFiles/Assignment1.dir/src/Main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Assignment1.dir/src/Main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lior/CLionProjects/SPLFLIX/Assignment1/src/Main.cpp -o CMakeFiles/Assignment1.dir/src/Main.cpp.s

CMakeFiles/Assignment1.dir/src/User.cpp.o: CMakeFiles/Assignment1.dir/flags.make
CMakeFiles/Assignment1.dir/src/User.cpp.o: ../src/User.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lior/CLionProjects/SPLFLIX/Assignment1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Assignment1.dir/src/User.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Assignment1.dir/src/User.cpp.o -c /home/lior/CLionProjects/SPLFLIX/Assignment1/src/User.cpp

CMakeFiles/Assignment1.dir/src/User.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Assignment1.dir/src/User.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lior/CLionProjects/SPLFLIX/Assignment1/src/User.cpp > CMakeFiles/Assignment1.dir/src/User.cpp.i

CMakeFiles/Assignment1.dir/src/User.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Assignment1.dir/src/User.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lior/CLionProjects/SPLFLIX/Assignment1/src/User.cpp -o CMakeFiles/Assignment1.dir/src/User.cpp.s

CMakeFiles/Assignment1.dir/src/Session.cpp.o: CMakeFiles/Assignment1.dir/flags.make
CMakeFiles/Assignment1.dir/src/Session.cpp.o: ../src/Session.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lior/CLionProjects/SPLFLIX/Assignment1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Assignment1.dir/src/Session.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Assignment1.dir/src/Session.cpp.o -c /home/lior/CLionProjects/SPLFLIX/Assignment1/src/Session.cpp

CMakeFiles/Assignment1.dir/src/Session.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Assignment1.dir/src/Session.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lior/CLionProjects/SPLFLIX/Assignment1/src/Session.cpp > CMakeFiles/Assignment1.dir/src/Session.cpp.i

CMakeFiles/Assignment1.dir/src/Session.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Assignment1.dir/src/Session.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lior/CLionProjects/SPLFLIX/Assignment1/src/Session.cpp -o CMakeFiles/Assignment1.dir/src/Session.cpp.s

CMakeFiles/Assignment1.dir/src/Watchable.cpp.o: CMakeFiles/Assignment1.dir/flags.make
CMakeFiles/Assignment1.dir/src/Watchable.cpp.o: ../src/Watchable.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lior/CLionProjects/SPLFLIX/Assignment1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Assignment1.dir/src/Watchable.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Assignment1.dir/src/Watchable.cpp.o -c /home/lior/CLionProjects/SPLFLIX/Assignment1/src/Watchable.cpp

CMakeFiles/Assignment1.dir/src/Watchable.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Assignment1.dir/src/Watchable.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lior/CLionProjects/SPLFLIX/Assignment1/src/Watchable.cpp > CMakeFiles/Assignment1.dir/src/Watchable.cpp.i

CMakeFiles/Assignment1.dir/src/Watchable.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Assignment1.dir/src/Watchable.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lior/CLionProjects/SPLFLIX/Assignment1/src/Watchable.cpp -o CMakeFiles/Assignment1.dir/src/Watchable.cpp.s

CMakeFiles/Assignment1.dir/src/Action.cpp.o: CMakeFiles/Assignment1.dir/flags.make
CMakeFiles/Assignment1.dir/src/Action.cpp.o: ../src/Action.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lior/CLionProjects/SPLFLIX/Assignment1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Assignment1.dir/src/Action.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Assignment1.dir/src/Action.cpp.o -c /home/lior/CLionProjects/SPLFLIX/Assignment1/src/Action.cpp

CMakeFiles/Assignment1.dir/src/Action.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Assignment1.dir/src/Action.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/lior/CLionProjects/SPLFLIX/Assignment1/src/Action.cpp > CMakeFiles/Assignment1.dir/src/Action.cpp.i

CMakeFiles/Assignment1.dir/src/Action.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Assignment1.dir/src/Action.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/lior/CLionProjects/SPLFLIX/Assignment1/src/Action.cpp -o CMakeFiles/Assignment1.dir/src/Action.cpp.s

# Object files for target Assignment1
Assignment1_OBJECTS = \
"CMakeFiles/Assignment1.dir/src/Main.cpp.o" \
"CMakeFiles/Assignment1.dir/src/User.cpp.o" \
"CMakeFiles/Assignment1.dir/src/Session.cpp.o" \
"CMakeFiles/Assignment1.dir/src/Watchable.cpp.o" \
"CMakeFiles/Assignment1.dir/src/Action.cpp.o"

# External object files for target Assignment1
Assignment1_EXTERNAL_OBJECTS =

Assignment1: CMakeFiles/Assignment1.dir/src/Main.cpp.o
Assignment1: CMakeFiles/Assignment1.dir/src/User.cpp.o
Assignment1: CMakeFiles/Assignment1.dir/src/Session.cpp.o
Assignment1: CMakeFiles/Assignment1.dir/src/Watchable.cpp.o
Assignment1: CMakeFiles/Assignment1.dir/src/Action.cpp.o
Assignment1: CMakeFiles/Assignment1.dir/build.make
Assignment1: CMakeFiles/Assignment1.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lior/CLionProjects/SPLFLIX/Assignment1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable Assignment1"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Assignment1.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Assignment1.dir/build: Assignment1

.PHONY : CMakeFiles/Assignment1.dir/build

CMakeFiles/Assignment1.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Assignment1.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Assignment1.dir/clean

CMakeFiles/Assignment1.dir/depend:
	cd /home/lior/CLionProjects/SPLFLIX/Assignment1/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lior/CLionProjects/SPLFLIX/Assignment1 /home/lior/CLionProjects/SPLFLIX/Assignment1 /home/lior/CLionProjects/SPLFLIX/Assignment1/cmake-build-debug /home/lior/CLionProjects/SPLFLIX/Assignment1/cmake-build-debug /home/lior/CLionProjects/SPLFLIX/Assignment1/cmake-build-debug/CMakeFiles/Assignment1.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Assignment1.dir/depend

