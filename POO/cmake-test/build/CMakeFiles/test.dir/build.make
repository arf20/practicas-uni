# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.25

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/arf20/practicas-uni/POO/cmake-test

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/arf20/practicas-uni/POO/cmake-test/build

# Utility rule file for test.

# Include any custom commands dependencies for this target.
include CMakeFiles/test.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/test.dir/progress.make

CMakeFiles/test: test.jar

test.jar: CMakeFiles/test.dir/java_class_filelist
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/arf20/practicas-uni/POO/cmake-test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Creating Java archive test.jar"
	cd /home/arf20/practicas-uni/POO/cmake-test/build/CMakeFiles/test.dir && /usr/bin/jar -cfe /home/arf20/practicas-uni/POO/cmake-test/build/test.jar testpackage.test @java_class_filelist
	cd /home/arf20/practicas-uni/POO/cmake-test/build/CMakeFiles/test.dir && /usr/bin/cmake -D_JAVA_TARGET_DIR=/home/arf20/practicas-uni/POO/cmake-test/build -D_JAVA_TARGET_OUTPUT_NAME=test.jar -D_JAVA_TARGET_OUTPUT_LINK= -P /usr/share/cmake-3.25/Modules/UseJava/Symlinks.cmake

CMakeFiles/test.dir/java_class_filelist: CMakeFiles/test.dir/java_compiled_test
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/arf20/practicas-uni/POO/cmake-test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Generating CMakeFiles/test.dir/java_class_filelist"
	cd /home/arf20/practicas-uni/POO/cmake-test && /usr/bin/cmake -DCMAKE_JAVA_CLASS_OUTPUT_PATH=/home/arf20/practicas-uni/POO/cmake-test/build/CMakeFiles/test.dir -DCMAKE_JAR_CLASSES_PREFIX= -P /usr/share/cmake-3.25/Modules/UseJava/ClassFilelist.cmake

CMakeFiles/test.dir/java_compiled_test: /home/arf20/practicas-uni/POO/cmake-test/src/testpackage/test.java
CMakeFiles/test.dir/java_compiled_test: CMakeFiles/test.dir/java_sources
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --blue --bold --progress-dir=/home/arf20/practicas-uni/POO/cmake-test/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building Java objects for test.jar"
	cd /home/arf20/practicas-uni/POO/cmake-test && /usr/bin/cmake -DCMAKE_JAVA_CLASS_OUTPUT_PATH=/home/arf20/practicas-uni/POO/cmake-test/build/CMakeFiles/test.dir -DCMAKE_JAR_CLASSES_PREFIX= -P /usr/share/cmake-3.25/Modules/UseJava/ClearClassFiles.cmake
	cd /home/arf20/practicas-uni/POO/cmake-test && /usr/bin/javac -classpath :/home/arf20/practicas-uni/POO/cmake-test:/home/arf20/practicas-uni/POO/cmake-test/build -d /home/arf20/practicas-uni/POO/cmake-test/build/CMakeFiles/test.dir @/home/arf20/practicas-uni/POO/cmake-test/build/CMakeFiles/test.dir/java_sources
	cd /home/arf20/practicas-uni/POO/cmake-test && /usr/bin/cmake -E touch /home/arf20/practicas-uni/POO/cmake-test/build/CMakeFiles/test.dir/java_compiled_test

test: CMakeFiles/test
test: CMakeFiles/test.dir/java_class_filelist
test: CMakeFiles/test.dir/java_compiled_test
test: test.jar
test: CMakeFiles/test.dir/build.make
.PHONY : test

# Rule to build all files generated by this target.
CMakeFiles/test.dir/build: test
.PHONY : CMakeFiles/test.dir/build

CMakeFiles/test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/test.dir/clean

CMakeFiles/test.dir/depend:
	cd /home/arf20/practicas-uni/POO/cmake-test/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/arf20/practicas-uni/POO/cmake-test /home/arf20/practicas-uni/POO/cmake-test /home/arf20/practicas-uni/POO/cmake-test/build /home/arf20/practicas-uni/POO/cmake-test/build /home/arf20/practicas-uni/POO/cmake-test/build/CMakeFiles/test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/test.dir/depend

