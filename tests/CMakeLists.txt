# CMakeLists.txt - Builds the LibCppLogging tests.
#
# Copyright (C) 2025 Stephen Bonar
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

# Define the source files needed to build the tests.
set(SOURCES 
    LoggerTests.cpp 
    OutputChannelTests.cpp 
    LogMessageTests.cpp)

# Define the directories that contain header files the tests need.
set(INCLUDES ${PROJECT_SOURCE_DIR}/include)

# Define the libraries the tests need to link against.
set(LIBRARIES
    LibCppLogging
    gtest
    gtest_main
    gmock)

include(FetchContent)
FetchContent_Declare(
    googletest
    URL https://github.com/google/googletest/archive/03597a01ee50ed33e9dfd640b249b4be3799d395.zip
)
# For Windows: Prevent overriding the parent project's compiler/linker settings
#set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)
FetchContent_MakeAvailable(googletest)

# Configure the binary build target.
add_executable(loggingtests ${SOURCES})

# Include all the directories that contain headers that we need which are not
# in the current directory, otherwise the compiler won't find them.
target_include_directories(loggingtests PRIVATE ${INCLUDES})

# Configure the tunebeepertests target to link to the necessary libraries.
target_link_libraries(loggingtests ${LIBRARIES})
