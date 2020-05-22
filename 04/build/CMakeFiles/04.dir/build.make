# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/lalo/Dropbox/escom/Compiladores/practicas/04

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/lalo/Dropbox/escom/Compiladores/practicas/04/build

# Include any dependencies generated for this target.
include CMakeFiles/04.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/04.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/04.dir/flags.make

parser.c: ../ejemplo2.y
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/lalo/Dropbox/escom/Compiladores/practicas/04/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "[BISON][MyParser] Building parser with bison 3.0.4"
	cd /home/lalo/Dropbox/escom/Compiladores/practicas/04 && /usr/bin/bison -d -o /home/lalo/Dropbox/escom/Compiladores/practicas/04/build/parser.c /home/lalo/Dropbox/escom/Compiladores/practicas/04/ejemplo2.y

parser.h: parser.c
	@$(CMAKE_COMMAND) -E touch_nocreate parser.h

scanner.c: ../ejemplo2.l
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/lalo/Dropbox/escom/Compiladores/practicas/04/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "[FLEX][MyScanner] Building scanner with flex 2.6.4"
	cd /home/lalo/Dropbox/escom/Compiladores/practicas/04 && /usr/bin/flex -o/home/lalo/Dropbox/escom/Compiladores/practicas/04/build/scanner.c /home/lalo/Dropbox/escom/Compiladores/practicas/04/ejemplo2.l

CMakeFiles/04.dir/parser.c.o: CMakeFiles/04.dir/flags.make
CMakeFiles/04.dir/parser.c.o: parser.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lalo/Dropbox/escom/Compiladores/practicas/04/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building C object CMakeFiles/04.dir/parser.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/04.dir/parser.c.o   -c /home/lalo/Dropbox/escom/Compiladores/practicas/04/build/parser.c

CMakeFiles/04.dir/parser.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/04.dir/parser.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/lalo/Dropbox/escom/Compiladores/practicas/04/build/parser.c > CMakeFiles/04.dir/parser.c.i

CMakeFiles/04.dir/parser.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/04.dir/parser.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/lalo/Dropbox/escom/Compiladores/practicas/04/build/parser.c -o CMakeFiles/04.dir/parser.c.s

CMakeFiles/04.dir/parser.c.o.requires:

.PHONY : CMakeFiles/04.dir/parser.c.o.requires

CMakeFiles/04.dir/parser.c.o.provides: CMakeFiles/04.dir/parser.c.o.requires
	$(MAKE) -f CMakeFiles/04.dir/build.make CMakeFiles/04.dir/parser.c.o.provides.build
.PHONY : CMakeFiles/04.dir/parser.c.o.provides

CMakeFiles/04.dir/parser.c.o.provides.build: CMakeFiles/04.dir/parser.c.o


CMakeFiles/04.dir/scanner.c.o: CMakeFiles/04.dir/flags.make
CMakeFiles/04.dir/scanner.c.o: scanner.c
CMakeFiles/04.dir/scanner.c.o: parser.h
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/lalo/Dropbox/escom/Compiladores/practicas/04/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building C object CMakeFiles/04.dir/scanner.c.o"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles/04.dir/scanner.c.o   -c /home/lalo/Dropbox/escom/Compiladores/practicas/04/build/scanner.c

CMakeFiles/04.dir/scanner.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/04.dir/scanner.c.i"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E /home/lalo/Dropbox/escom/Compiladores/practicas/04/build/scanner.c > CMakeFiles/04.dir/scanner.c.i

CMakeFiles/04.dir/scanner.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/04.dir/scanner.c.s"
	/usr/bin/cc $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S /home/lalo/Dropbox/escom/Compiladores/practicas/04/build/scanner.c -o CMakeFiles/04.dir/scanner.c.s

CMakeFiles/04.dir/scanner.c.o.requires:

.PHONY : CMakeFiles/04.dir/scanner.c.o.requires

CMakeFiles/04.dir/scanner.c.o.provides: CMakeFiles/04.dir/scanner.c.o.requires
	$(MAKE) -f CMakeFiles/04.dir/build.make CMakeFiles/04.dir/scanner.c.o.provides.build
.PHONY : CMakeFiles/04.dir/scanner.c.o.provides

CMakeFiles/04.dir/scanner.c.o.provides.build: CMakeFiles/04.dir/scanner.c.o


# Object files for target 04
04_OBJECTS = \
"CMakeFiles/04.dir/parser.c.o" \
"CMakeFiles/04.dir/scanner.c.o"

# External object files for target 04
04_EXTERNAL_OBJECTS =

04: CMakeFiles/04.dir/parser.c.o
04: CMakeFiles/04.dir/scanner.c.o
04: CMakeFiles/04.dir/build.make
04: /usr/lib/libfl.so
04: CMakeFiles/04.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/lalo/Dropbox/escom/Compiladores/practicas/04/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Linking C executable 04"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/04.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/04.dir/build: 04

.PHONY : CMakeFiles/04.dir/build

CMakeFiles/04.dir/requires: CMakeFiles/04.dir/parser.c.o.requires
CMakeFiles/04.dir/requires: CMakeFiles/04.dir/scanner.c.o.requires

.PHONY : CMakeFiles/04.dir/requires

CMakeFiles/04.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/04.dir/cmake_clean.cmake
.PHONY : CMakeFiles/04.dir/clean

CMakeFiles/04.dir/depend: parser.c
CMakeFiles/04.dir/depend: parser.h
CMakeFiles/04.dir/depend: scanner.c
	cd /home/lalo/Dropbox/escom/Compiladores/practicas/04/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/lalo/Dropbox/escom/Compiladores/practicas/04 /home/lalo/Dropbox/escom/Compiladores/practicas/04 /home/lalo/Dropbox/escom/Compiladores/practicas/04/build /home/lalo/Dropbox/escom/Compiladores/practicas/04/build /home/lalo/Dropbox/escom/Compiladores/practicas/04/build/CMakeFiles/04.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/04.dir/depend

