# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.5

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


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
CMAKE_SOURCE_DIR = /mnt/c/Users/giova/Desktop/ProgettoCppBertoncelliGiovanniVR399929/TuringMachineSimulatorCpp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/c/Users/giova/Desktop/ProgettoCppBertoncelliGiovanniVR399929/TuringMachineSimulatorCpp

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target test
test:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running tests..."
	/usr/bin/ctest --force-new-ctest-process $(ARGS)
.PHONY : test

# Special rule for the target test
test/fast: test

.PHONY : test/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /mnt/c/Users/giova/Desktop/ProgettoCppBertoncelliGiovanniVR399929/TuringMachineSimulatorCpp/CMakeFiles /mnt/c/Users/giova/Desktop/ProgettoCppBertoncelliGiovanniVR399929/TuringMachineSimulatorCpp/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /mnt/c/Users/giova/Desktop/ProgettoCppBertoncelliGiovanniVR399929/TuringMachineSimulatorCpp/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named doc

# Build rule for target.
doc: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 doc
.PHONY : doc

# fast build rule for target.
doc/fast:
	$(MAKE) -f CMakeFiles/doc.dir/build.make CMakeFiles/doc.dir/build
.PHONY : doc/fast

#=============================================================================
# Target rules for targets named TuringSimulatorOut.x

# Build rule for target.
TuringSimulatorOut.x: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 TuringSimulatorOut.x
.PHONY : TuringSimulatorOut.x

# fast build rule for target.
TuringSimulatorOut.x/fast:
	$(MAKE) -f CMakeFiles/TuringSimulatorOut.x.dir/build.make CMakeFiles/TuringSimulatorOut.x.dir/build
.PHONY : TuringSimulatorOut.x/fast

#=============================================================================
# Target rules for targets named rm

# Build rule for target.
rm: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 rm
.PHONY : rm

# fast build rule for target.
rm/fast:
	$(MAKE) -f CMakeFiles/rm.dir/build.make CMakeFiles/rm.dir/build
.PHONY : rm/fast

#=============================================================================
# Target rules for targets named scan-build

# Build rule for target.
scan-build: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 scan-build
.PHONY : scan-build

# fast build rule for target.
scan-build/fast:
	$(MAKE) -f CMakeFiles/scan-build.dir/build.make CMakeFiles/scan-build.dir/build
.PHONY : scan-build/fast

#=============================================================================
# Target rules for targets named stats

# Build rule for target.
stats: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 stats
.PHONY : stats

# fast build rule for target.
stats/fast:
	$(MAKE) -f CMakeFiles/stats.dir/build.make CMakeFiles/stats.dir/build
.PHONY : stats/fast

#=============================================================================
# Target rules for targets named valgrind

# Build rule for target.
valgrind: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 valgrind
.PHONY : valgrind

# fast build rule for target.
valgrind/fast:
	$(MAKE) -f CMakeFiles/valgrind.dir/build.make CMakeFiles/valgrind.dir/build
.PHONY : valgrind/fast

#=============================================================================
# Target rules for targets named Testing.x

# Build rule for target.
Testing.x: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 Testing.x
.PHONY : Testing.x

# fast build rule for target.
Testing.x/fast:
	$(MAKE) -f CMakeFiles/Testing.x.dir/build.make CMakeFiles/Testing.x.dir/build
.PHONY : Testing.x/fast

#=============================================================================
# Target rules for targets named format

# Build rule for target.
format: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 format
.PHONY : format

# fast build rule for target.
format/fast:
	$(MAKE) -f CMakeFiles/format.dir/build.make CMakeFiles/format.dir/build
.PHONY : format/fast

src/GpUtils.o: src/GpUtils.cpp.o

.PHONY : src/GpUtils.o

# target to build an object file
src/GpUtils.cpp.o:
	$(MAKE) -f CMakeFiles/TuringSimulatorOut.x.dir/build.make CMakeFiles/TuringSimulatorOut.x.dir/src/GpUtils.cpp.o
.PHONY : src/GpUtils.cpp.o

src/GpUtils.i: src/GpUtils.cpp.i

.PHONY : src/GpUtils.i

# target to preprocess a source file
src/GpUtils.cpp.i:
	$(MAKE) -f CMakeFiles/TuringSimulatorOut.x.dir/build.make CMakeFiles/TuringSimulatorOut.x.dir/src/GpUtils.cpp.i
.PHONY : src/GpUtils.cpp.i

src/GpUtils.s: src/GpUtils.cpp.s

.PHONY : src/GpUtils.s

# target to generate assembly for a file
src/GpUtils.cpp.s:
	$(MAKE) -f CMakeFiles/TuringSimulatorOut.x.dir/build.make CMakeFiles/TuringSimulatorOut.x.dir/src/GpUtils.cpp.s
.PHONY : src/GpUtils.cpp.s

src/State.o: src/State.cpp.o

.PHONY : src/State.o

# target to build an object file
src/State.cpp.o:
	$(MAKE) -f CMakeFiles/TuringSimulatorOut.x.dir/build.make CMakeFiles/TuringSimulatorOut.x.dir/src/State.cpp.o
.PHONY : src/State.cpp.o

src/State.i: src/State.cpp.i

.PHONY : src/State.i

# target to preprocess a source file
src/State.cpp.i:
	$(MAKE) -f CMakeFiles/TuringSimulatorOut.x.dir/build.make CMakeFiles/TuringSimulatorOut.x.dir/src/State.cpp.i
.PHONY : src/State.cpp.i

src/State.s: src/State.cpp.s

.PHONY : src/State.s

# target to generate assembly for a file
src/State.cpp.s:
	$(MAKE) -f CMakeFiles/TuringSimulatorOut.x.dir/build.make CMakeFiles/TuringSimulatorOut.x.dir/src/State.cpp.s
.PHONY : src/State.cpp.s

src/TransitionBase.o: src/TransitionBase.cpp.o

.PHONY : src/TransitionBase.o

# target to build an object file
src/TransitionBase.cpp.o:
	$(MAKE) -f CMakeFiles/TuringSimulatorOut.x.dir/build.make CMakeFiles/TuringSimulatorOut.x.dir/src/TransitionBase.cpp.o
.PHONY : src/TransitionBase.cpp.o

src/TransitionBase.i: src/TransitionBase.cpp.i

.PHONY : src/TransitionBase.i

# target to preprocess a source file
src/TransitionBase.cpp.i:
	$(MAKE) -f CMakeFiles/TuringSimulatorOut.x.dir/build.make CMakeFiles/TuringSimulatorOut.x.dir/src/TransitionBase.cpp.i
.PHONY : src/TransitionBase.cpp.i

src/TransitionBase.s: src/TransitionBase.cpp.s

.PHONY : src/TransitionBase.s

# target to generate assembly for a file
src/TransitionBase.cpp.s:
	$(MAKE) -f CMakeFiles/TuringSimulatorOut.x.dir/build.make CMakeFiles/TuringSimulatorOut.x.dir/src/TransitionBase.cpp.s
.PHONY : src/TransitionBase.cpp.s

src/TransitionValue.o: src/TransitionValue.cpp.o

.PHONY : src/TransitionValue.o

# target to build an object file
src/TransitionValue.cpp.o:
	$(MAKE) -f CMakeFiles/TuringSimulatorOut.x.dir/build.make CMakeFiles/TuringSimulatorOut.x.dir/src/TransitionValue.cpp.o
.PHONY : src/TransitionValue.cpp.o

src/TransitionValue.i: src/TransitionValue.cpp.i

.PHONY : src/TransitionValue.i

# target to preprocess a source file
src/TransitionValue.cpp.i:
	$(MAKE) -f CMakeFiles/TuringSimulatorOut.x.dir/build.make CMakeFiles/TuringSimulatorOut.x.dir/src/TransitionValue.cpp.i
.PHONY : src/TransitionValue.cpp.i

src/TransitionValue.s: src/TransitionValue.cpp.s

.PHONY : src/TransitionValue.s

# target to generate assembly for a file
src/TransitionValue.cpp.s:
	$(MAKE) -f CMakeFiles/TuringSimulatorOut.x.dir/build.make CMakeFiles/TuringSimulatorOut.x.dir/src/TransitionValue.cpp.s
.PHONY : src/TransitionValue.cpp.s

src/TuringMachine.o: src/TuringMachine.cpp.o

.PHONY : src/TuringMachine.o

# target to build an object file
src/TuringMachine.cpp.o:
	$(MAKE) -f CMakeFiles/TuringSimulatorOut.x.dir/build.make CMakeFiles/TuringSimulatorOut.x.dir/src/TuringMachine.cpp.o
.PHONY : src/TuringMachine.cpp.o

src/TuringMachine.i: src/TuringMachine.cpp.i

.PHONY : src/TuringMachine.i

# target to preprocess a source file
src/TuringMachine.cpp.i:
	$(MAKE) -f CMakeFiles/TuringSimulatorOut.x.dir/build.make CMakeFiles/TuringSimulatorOut.x.dir/src/TuringMachine.cpp.i
.PHONY : src/TuringMachine.cpp.i

src/TuringMachine.s: src/TuringMachine.cpp.s

.PHONY : src/TuringMachine.s

# target to generate assembly for a file
src/TuringMachine.cpp.s:
	$(MAKE) -f CMakeFiles/TuringSimulatorOut.x.dir/build.make CMakeFiles/TuringSimulatorOut.x.dir/src/TuringMachine.cpp.s
.PHONY : src/TuringMachine.cpp.s

src/TuringMachineState.o: src/TuringMachineState.cpp.o

.PHONY : src/TuringMachineState.o

# target to build an object file
src/TuringMachineState.cpp.o:
	$(MAKE) -f CMakeFiles/TuringSimulatorOut.x.dir/build.make CMakeFiles/TuringSimulatorOut.x.dir/src/TuringMachineState.cpp.o
.PHONY : src/TuringMachineState.cpp.o

src/TuringMachineState.i: src/TuringMachineState.cpp.i

.PHONY : src/TuringMachineState.i

# target to preprocess a source file
src/TuringMachineState.cpp.i:
	$(MAKE) -f CMakeFiles/TuringSimulatorOut.x.dir/build.make CMakeFiles/TuringSimulatorOut.x.dir/src/TuringMachineState.cpp.i
.PHONY : src/TuringMachineState.cpp.i

src/TuringMachineState.s: src/TuringMachineState.cpp.s

.PHONY : src/TuringMachineState.s

# target to generate assembly for a file
src/TuringMachineState.cpp.s:
	$(MAKE) -f CMakeFiles/TuringSimulatorOut.x.dir/build.make CMakeFiles/TuringSimulatorOut.x.dir/src/TuringMachineState.cpp.s
.PHONY : src/TuringMachineState.cpp.s

src/main.o: src/main.cpp.o

.PHONY : src/main.o

# target to build an object file
src/main.cpp.o:
	$(MAKE) -f CMakeFiles/TuringSimulatorOut.x.dir/build.make CMakeFiles/TuringSimulatorOut.x.dir/src/main.cpp.o
.PHONY : src/main.cpp.o

src/main.i: src/main.cpp.i

.PHONY : src/main.i

# target to preprocess a source file
src/main.cpp.i:
	$(MAKE) -f CMakeFiles/TuringSimulatorOut.x.dir/build.make CMakeFiles/TuringSimulatorOut.x.dir/src/main.cpp.i
.PHONY : src/main.cpp.i

src/main.s: src/main.cpp.s

.PHONY : src/main.s

# target to generate assembly for a file
src/main.cpp.s:
	$(MAKE) -f CMakeFiles/TuringSimulatorOut.x.dir/build.make CMakeFiles/TuringSimulatorOut.x.dir/src/main.cpp.s
.PHONY : src/main.cpp.s

test/Tests.o: test/Tests.cpp.o

.PHONY : test/Tests.o

# target to build an object file
test/Tests.cpp.o:
	$(MAKE) -f CMakeFiles/Testing.x.dir/build.make CMakeFiles/Testing.x.dir/test/Tests.cpp.o
.PHONY : test/Tests.cpp.o

test/Tests.i: test/Tests.cpp.i

.PHONY : test/Tests.i

# target to preprocess a source file
test/Tests.cpp.i:
	$(MAKE) -f CMakeFiles/Testing.x.dir/build.make CMakeFiles/Testing.x.dir/test/Tests.cpp.i
.PHONY : test/Tests.cpp.i

test/Tests.s: test/Tests.cpp.s

.PHONY : test/Tests.s

# target to generate assembly for a file
test/Tests.cpp.s:
	$(MAKE) -f CMakeFiles/Testing.x.dir/build.make CMakeFiles/Testing.x.dir/test/Tests.cpp.s
.PHONY : test/Tests.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... test"
	@echo "... doc"
	@echo "... TuringSimulatorOut.x"
	@echo "... edit_cache"
	@echo "... rm"
	@echo "... scan-build"
	@echo "... stats"
	@echo "... valgrind"
	@echo "... Testing.x"
	@echo "... rebuild_cache"
	@echo "... format"
	@echo "... src/GpUtils.o"
	@echo "... src/GpUtils.i"
	@echo "... src/GpUtils.s"
	@echo "... src/State.o"
	@echo "... src/State.i"
	@echo "... src/State.s"
	@echo "... src/TransitionBase.o"
	@echo "... src/TransitionBase.i"
	@echo "... src/TransitionBase.s"
	@echo "... src/TransitionValue.o"
	@echo "... src/TransitionValue.i"
	@echo "... src/TransitionValue.s"
	@echo "... src/TuringMachine.o"
	@echo "... src/TuringMachine.i"
	@echo "... src/TuringMachine.s"
	@echo "... src/TuringMachineState.o"
	@echo "... src/TuringMachineState.i"
	@echo "... src/TuringMachineState.s"
	@echo "... src/main.o"
	@echo "... src/main.i"
	@echo "... src/main.s"
	@echo "... test/Tests.o"
	@echo "... test/Tests.i"
	@echo "... test/Tests.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

