// LogMessageTests.h - Defines the LogMessage tests.
//
// Copyright (C) 2024 Stephen Bonar
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

#include "LogMessageTests.h"

namespace Logging
{
    LogMessageTests::LogMessageTests()
    {

    }

    TEST_F(LogMessageTests, ProperlyCreatesLogMessage)
    {
        LogMessage message{ "Test", LogLevel::Info, &dateTimeService };

        EXPECT_EQ(message.Text(), "Test");
        EXPECT_EQ(message.Level(), LogLevel::Info);
    }

    TEST_F(LogMessageTests, PrefixedTextHasNoPrefixIfNoPrefixesIncluded)
    {
        LogMessage message{ "Test", LogLevel::Info, &dateTimeService };
        ChannelSettings settings;
        settings.includeTimestamp = false;
        settings.includeLogLevel = false;

        EXPECT_EQ(message.PrefixedText(settings), "Test");
    }

    TEST_F(LogMessageTests, PrefixTextIncludesFatalIfLogLevelIncluded)
    {
        LogMessage message{ "Test", LogLevel::Fatal, &dateTimeService };
        ChannelSettings settings;
        settings.includeTimestamp = false;
        settings.includeLogLevel = true;

        EXPECT_EQ(message.PrefixedText(settings).rfind("FATAL ERROR:", 0), 0);
    }

    TEST_F(LogMessageTests, PrefixTextIncludesErrorIfLogLevelIncluded)
    {
        LogMessage message{ "Test", LogLevel::Error, &dateTimeService };
        ChannelSettings settings;
        settings.includeTimestamp = false;
        settings.includeLogLevel = true;

        EXPECT_EQ(message.PrefixedText(settings).rfind("ERROR:", 0), 0);
    }

    TEST_F(LogMessageTests, PrefixTextIncludesWarningIfLogLevelIncluded)
    {
        LogMessage message{ "Test", LogLevel::Warning, &dateTimeService };
        ChannelSettings settings;
        settings.includeTimestamp = false;
        settings.includeLogLevel = true;

        EXPECT_EQ(message.PrefixedText(settings).rfind("WARNING:", 0), 0);
    }

    TEST_F(LogMessageTests, PrefixTextIncludesInfoIfLogLevelIncluded)
    {
        LogMessage message{ "Test", LogLevel::Info, &dateTimeService };
        ChannelSettings settings;
        settings.includeTimestamp = false;
        settings.includeLogLevel = true;

        EXPECT_EQ(message.PrefixedText(settings).rfind("INFO:", 0), 0);
    }

    TEST_F(LogMessageTests, PrefixTextIncludesDebugIfLogLevelIncluded)
    {
        LogMessage message{ "Test", LogLevel::Debug, &dateTimeService };
        ChannelSettings settings;
        settings.includeTimestamp = false;
        settings.includeLogLevel = true;

        EXPECT_EQ(message.PrefixedText(settings).rfind("DEBUG:", 0), 0);
    }

    TEST_F(LogMessageTests, PrefixTextIncludesTraceIfLogLevelIncluded)
    {
        LogMessage message{ "Test", LogLevel::Trace, &dateTimeService };
        ChannelSettings settings;
        settings.includeTimestamp = false;
        settings.includeLogLevel = true;

        EXPECT_EQ(message.PrefixedText(settings).rfind("TRACE:", 0), 0);
    }

    TEST_F(LogMessageTests, PrefixTextIncludesTimestampIfMarkedIncluded)
    {
        EXPECT_CALL(dateTimeService, Now)
            .WillRepeatedly(Return("Www Mmm dd hh:mm:ss yyyy"));

        LogMessage message{ "Test", LogLevel::Info, &dateTimeService };
        ChannelSettings settings;
        settings.includeTimestamp = true;
        settings.includeLogLevel = false;

        EXPECT_EQ(
            message.PrefixedText(settings).rfind("Www Mmm dd hh:mm:ss yyyy", 0),
            0);        
    }

    TEST_F(LogMessageTests, PrefixTextIncludesBothIfBothIncluded)
    {
        EXPECT_CALL(dateTimeService, Now)
            .WillRepeatedly(Return("Www Mmm dd hh:mm:ss yyyy"));

        LogMessage message{ "Test", LogLevel::Info, &dateTimeService };
        ChannelSettings settings;
        settings.includeTimestamp = true;
        settings.includeLogLevel = true;

        EXPECT_EQ(
            message.PrefixedText(settings), 
            "Www Mmm dd hh:mm:ss yyyy INFO: Test");        
    }
}
