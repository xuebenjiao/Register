# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.14

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "D:\Program Files\JetBrains\CLion 2019.2.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "D:\Program Files\JetBrains\CLion 2019.2.1\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = E:\androidProject\ClionProject\Register

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = E:\androidProject\ClionProject\Register\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/firstDyLib.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/firstDyLib.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/firstDyLib.dir/flags.make

CMakeFiles/firstDyLib.dir/DynamicRegister.c.obj: CMakeFiles/firstDyLib.dir/flags.make
CMakeFiles/firstDyLib.dir/DynamicRegister.c.obj: ../DynamicRegister.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=E:\androidProject\ClionProject\Register\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/firstDyLib.dir/DynamicRegister.c.obj"
	"D:\Program Files (x86)\MinGW64\mingw64\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\firstDyLib.dir\DynamicRegister.c.obj   -c E:\androidProject\ClionProject\Register\DynamicRegister.c

CMakeFiles/firstDyLib.dir/DynamicRegister.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/firstDyLib.dir/DynamicRegister.c.i"
	"D:\Program Files (x86)\MinGW64\mingw64\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E E:\androidProject\ClionProject\Register\DynamicRegister.c > CMakeFiles\firstDyLib.dir\DynamicRegister.c.i

CMakeFiles/firstDyLib.dir/DynamicRegister.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/firstDyLib.dir/DynamicRegister.c.s"
	"D:\Program Files (x86)\MinGW64\mingw64\bin\gcc.exe" $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S E:\androidProject\ClionProject\Register\DynamicRegister.c -o CMakeFiles\firstDyLib.dir\DynamicRegister.c.s

# Object files for target firstDyLib
firstDyLib_OBJECTS = \
"CMakeFiles/firstDyLib.dir/DynamicRegister.c.obj"

# External object files for target firstDyLib
firstDyLib_EXTERNAL_OBJECTS =

libfirstDyLib.dll: CMakeFiles/firstDyLib.dir/DynamicRegister.c.obj
libfirstDyLib.dll: CMakeFiles/firstDyLib.dir/build.make
libfirstDyLib.dll: CMakeFiles/firstDyLib.dir/linklibs.rsp
libfirstDyLib.dll: CMakeFiles/firstDyLib.dir/objects1.rsp
libfirstDyLib.dll: CMakeFiles/firstDyLib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=E:\androidProject\ClionProject\Register\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C shared library libfirstDyLib.dll"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\firstDyLib.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/firstDyLib.dir/build: libfirstDyLib.dll

.PHONY : CMakeFiles/firstDyLib.dir/build

CMakeFiles/firstDyLib.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\firstDyLib.dir\cmake_clean.cmake
.PHONY : CMakeFiles/firstDyLib.dir/clean

CMakeFiles/firstDyLib.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" E:\androidProject\ClionProject\Register E:\androidProject\ClionProject\Register E:\androidProject\ClionProject\Register\cmake-build-debug E:\androidProject\ClionProject\Register\cmake-build-debug E:\androidProject\ClionProject\Register\cmake-build-debug\CMakeFiles\firstDyLib.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/firstDyLib.dir/depend

