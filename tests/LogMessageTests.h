// LogMessageTests.h - Declares the LogMessageTests fixture.
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

#ifndef LOGGING_LOG_MESSAGE_TESTS_H
#define LOGGING_LOG_MESSAGE_TESTS_H

#include <exception>
#include <chrono>
#include <ctime>
#include "gtest/gtest.h"
#include "LogMessage.h"
#include "MockDateTimeService.h"

using ::testing::Return;

namespace Logging
{
    class LogMessageTests : public ::testing::Test
    {
    protected:
        /// @brief Constructs the LogMessageTests fixture.
        ///
        /// Initializes shared data common to all Logger tests.
        LogMessageTests();

        MockDateTimeService dateTimeService;
    };
}

#endif