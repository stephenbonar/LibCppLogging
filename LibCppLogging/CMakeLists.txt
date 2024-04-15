# CMakeLists.txt - Builds the LibCppLogging library.
#
# Copyright (C) 2024 Stephen Bonar
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http ://www.apache.org/licenses/LICENSE-2.0
# 
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissionsand
# limitations under the License.

# cmake v3.12 is the minimum needed for the library.
cmake_minimum_required(VERSION 3.12)

# Define the source files needed to build the library.
set(SOURCES 
    Logger.cpp 
    LogMessage.cpp 
    OutputChannel.cpp 
    StandardOutput.cpp
    CTimeService.cpp)

# Configure the library build target. Any cmake project that adds
# this library's directory using add_subdirectory() and 
# target_include_directories(), as well as links it to a build target using
# target_link_libraries() can easily add this library to their build.
add_library(LibCppLogging ${SOURCES})

# Override the default behavior of prefixing "lib" on the library binary so
# we end up with LibCppCmdLine.a isntead of libLibCppCmdLine.a.
set_target_properties(LibCppLogging PROPERTIES PREFIX "")

# Added to ensure the header files are automatically resolved when linking
# to this library.
target_include_directories(LibCppLogging PUBLIC .)
