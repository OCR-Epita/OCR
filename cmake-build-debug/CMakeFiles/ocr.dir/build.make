# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.12

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
CMAKE_COMMAND = /home/tsaison/clion-2018.2.4/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /home/tsaison/clion-2018.2.4/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /root/ocr

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /root/ocr/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ocr.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ocr.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ocr.dir/flags.make

CMakeFiles/ocr.dir/Files/Binary.c.o: CMakeFiles/ocr.dir/flags.make
CMakeFiles/ocr.dir/Files/Binary.c.o: ../Files/Binary.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/ocr/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/ocr.dir/Files/Binary.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ocr.dir/Files/Binary.c.o   -c /root/ocr/Files/Binary.c

CMakeFiles/ocr.dir/Files/Binary.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ocr.dir/Files/Binary.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /root/ocr/Files/Binary.c > CMakeFiles/ocr.dir/Files/Binary.c.i

CMakeFiles/ocr.dir/Files/Binary.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ocr.dir/Files/Binary.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /root/ocr/Files/Binary.c -o CMakeFiles/ocr.dir/Files/Binary.c.s

CMakeFiles/ocr.dir/Files/Segmentation.c.o: CMakeFiles/ocr.dir/flags.make
CMakeFiles/ocr.dir/Files/Segmentation.c.o: ../Files/Segmentation.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/ocr/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building C object CMakeFiles/ocr.dir/Files/Segmentation.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ocr.dir/Files/Segmentation.c.o   -c /root/ocr/Files/Segmentation.c

CMakeFiles/ocr.dir/Files/Segmentation.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ocr.dir/Files/Segmentation.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /root/ocr/Files/Segmentation.c > CMakeFiles/ocr.dir/Files/Segmentation.c.i

CMakeFiles/ocr.dir/Files/Segmentation.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ocr.dir/Files/Segmentation.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /root/ocr/Files/Segmentation.c -o CMakeFiles/ocr.dir/Files/Segmentation.c.s

CMakeFiles/ocr.dir/Files/Traitement.c.o: CMakeFiles/ocr.dir/flags.make
CMakeFiles/ocr.dir/Files/Traitement.c.o: ../Files/Traitement.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/ocr/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/ocr.dir/Files/Traitement.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ocr.dir/Files/Traitement.c.o   -c /root/ocr/Files/Traitement.c

CMakeFiles/ocr.dir/Files/Traitement.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ocr.dir/Files/Traitement.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /root/ocr/Files/Traitement.c > CMakeFiles/ocr.dir/Files/Traitement.c.i

CMakeFiles/ocr.dir/Files/Traitement.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ocr.dir/Files/Traitement.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /root/ocr/Files/Traitement.c -o CMakeFiles/ocr.dir/Files/Traitement.c.s

CMakeFiles/ocr.dir/Files/Utility.c.o: CMakeFiles/ocr.dir/flags.make
CMakeFiles/ocr.dir/Files/Utility.c.o: ../Files/Utility.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/ocr/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/ocr.dir/Files/Utility.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ocr.dir/Files/Utility.c.o   -c /root/ocr/Files/Utility.c

CMakeFiles/ocr.dir/Files/Utility.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ocr.dir/Files/Utility.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /root/ocr/Files/Utility.c > CMakeFiles/ocr.dir/Files/Utility.c.i

CMakeFiles/ocr.dir/Files/Utility.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ocr.dir/Files/Utility.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /root/ocr/Files/Utility.c -o CMakeFiles/ocr.dir/Files/Utility.c.s

CMakeFiles/ocr.dir/main.c.o: CMakeFiles/ocr.dir/flags.make
CMakeFiles/ocr.dir/main.c.o: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/root/ocr/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building C object CMakeFiles/ocr.dir/main.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/ocr.dir/main.c.o   -c /root/ocr/main.c

CMakeFiles/ocr.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ocr.dir/main.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /root/ocr/main.c > CMakeFiles/ocr.dir/main.c.i

CMakeFiles/ocr.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ocr.dir/main.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /root/ocr/main.c -o CMakeFiles/ocr.dir/main.c.s

# Object files for target ocr
ocr_OBJECTS = \
"CMakeFiles/ocr.dir/Files/Binary.c.o" \
"CMakeFiles/ocr.dir/Files/Segmentation.c.o" \
"CMakeFiles/ocr.dir/Files/Traitement.c.o" \
"CMakeFiles/ocr.dir/Files/Utility.c.o" \
"CMakeFiles/ocr.dir/main.c.o"

# External object files for target ocr
ocr_EXTERNAL_OBJECTS =

ocr: CMakeFiles/ocr.dir/Files/Binary.c.o
ocr: CMakeFiles/ocr.dir/Files/Segmentation.c.o
ocr: CMakeFiles/ocr.dir/Files/Traitement.c.o
ocr: CMakeFiles/ocr.dir/Files/Utility.c.o
ocr: CMakeFiles/ocr.dir/main.c.o
ocr: CMakeFiles/ocr.dir/build.make
ocr: CMakeFiles/ocr.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/root/ocr/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking C executable ocr"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ocr.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ocr.dir/build: ocr

.PHONY : CMakeFiles/ocr.dir/build

CMakeFiles/ocr.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ocr.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ocr.dir/clean

CMakeFiles/ocr.dir/depend:
	cd /root/ocr/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /root/ocr /root/ocr /root/ocr/cmake-build-debug /root/ocr/cmake-build-debug /root/ocr/cmake-build-debug/CMakeFiles/ocr.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ocr.dir/depend
