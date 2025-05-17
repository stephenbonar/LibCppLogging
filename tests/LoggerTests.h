// LoggerTests.h - Declares the LoggerTests fixture.
//
// Copyright (C) 2025 Stephen Bonar
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
// http ://www.apache.org/licenses/LICENSE-2.0
// 
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissionsand
// limitations under the License.

#ifndef LOGGING_LOGGER_TESTS_H
#define LOGGING_LOGGER_TESTS_H

#include <exception>
#include "gtest/gtest.h"
#include "Logger.h"
#include "MockOutputChannel.h"

using ::testing::Eq;
using ::testing::Property;
using ::testing::Return;
using ::testing::_;

namespace Logging
{
    class LoggerTests : public ::testing::Test
    {
    protected:
        /// @brief Constructs the LoggerTests fixture.
        ///
        /// Initializes shared data common to all Logger tests.
        LoggerTests(){}
    };
}

#endif