// OutputChannelTests.h - Defines the OutputChannel tests.
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

#include "OutputChannelTests.h"

namespace Logging
{
    OutputChannelTests::OutputChannelTests()
    {
        initialSettings.includeFatal = false;
        initialSettings.includeError = false;
        initialSettings.includeWarning = false;
        initialSettings.includeInfo = false;
        initialSettings.includeDebug = false;
        initialSettings.includeTrace = false;      
        initialSettings.includeTimestamp = false;
        initialSettings.includeLogLevel = false;
    }

    TEST_F(OutputChannelTests, MinLogLevelTraceIncludesAllLevels)
    {
        MockOutputChannel channel{};
        ChannelSettings expectedSettings;
        expectedSettings.includeFatal = true;
        expectedSettings.includeError = true;
        expectedSettings.includeWarning = true;
        expectedSettings.includeInfo = true;
        expectedSettings.includeDebug = true;
        expectedSettings.includeTrace = true;
        expectedSettings.includeTimestamp = false;
        expectedSettings.includeLogLevel = false;
        
        EXPECT_CALL(channel, Settings)
            .WillOnce(Return(initialSettings));
        EXPECT_CALL(
            channel, 
            SetSettings(
                FieldsAre(
                    expectedSettings.includeFatal,
                    expectedSettings.includeError,
                    expectedSettings.includeWarning,
                    expectedSettings.includeInfo,
                    expectedSettings.includeDebug,
                    expectedSettings.includeTrace,
                    expectedSettings.includeTimestamp,
                    expectedSettings.includeLogLevel)))
            .Times(1);

        channel.SetMinLogLevel(Logging::LogLevel::Trace);
    }

    TEST_F(OutputChannelTests, MinLogLevelDebugIncludesDebugAndAbove)
    {
        MockOutputChannel channel{};
        ChannelSettings expectedSettings;
        expectedSettings.includeFatal = true;
        expectedSettings.includeError = true;
        expectedSettings.includeWarning = true;
        expectedSettings.includeInfo = true;
        expectedSettings.includeDebug = true;
        expectedSettings.includeTrace = false;
        expectedSettings.includeTimestamp = false;
        expectedSettings.includeLogLevel = false;
        
        EXPECT_CALL(channel, Settings)
            .WillOnce(Return(initialSettings));
        EXPECT_CALL(
            channel,
            SetSettings(
                FieldsAre(
                    expectedSettings.includeFatal,
                    expectedSettings.includeError,
                    expectedSettings.includeWarning,
                    expectedSettings.includeInfo,
                    expectedSettings.includeDebug,
                    expectedSettings.includeTrace,
                    expectedSettings.includeTimestamp,
                    expectedSettings.includeLogLevel)))
            .Times(1);

        channel.SetMinLogLevel(Logging::LogLevel::Debug);
    }

    TEST_F(OutputChannelTests, MinLogLevelInfoIncludesInfoAndAbove)
    {
        MockOutputChannel channel{};
        ChannelSettings expectedSettings;
        expectedSettings.includeFatal = true;
        expectedSettings.includeError = true;
        expectedSettings.includeWarning = true;
        expectedSettings.includeInfo = true;
        expectedSettings.includeDebug = false;
        expectedSettings.includeTrace = false;
        expectedSettings.includeTimestamp = false;
        expectedSettings.includeLogLevel = false;
        
        EXPECT_CALL(channel, Settings)
            .WillOnce(Return(initialSettings));
        EXPECT_CALL(
            channel,
            SetSettings(
                FieldsAre(
                    expectedSettings.includeFatal,
                    expectedSettings.includeError,
                    expectedSettings.includeWarning,
                    expectedSettings.includeInfo,
                    expectedSettings.includeDebug,
                    expectedSettings.includeTrace,
                    expectedSettings.includeTimestamp,
                    expectedSettings.includeLogLevel)))
            .Times(1);

        channel.SetMinLogLevel(Logging::LogLevel::Info);
    }

    TEST_F(OutputChannelTests, MinLogLevelWarningIncludesWarningAndAbove)
    {
        MockOutputChannel channel{};
        ChannelSettings expectedSettings;
        expectedSettings.includeFatal = true;
        expectedSettings.includeError = true;
        expectedSettings.includeWarning = true;
        expectedSettings.includeInfo = false;
        expectedSettings.includeDebug = false;
        expectedSettings.includeTrace = false;
        expectedSettings.includeTimestamp = false;
        expectedSettings.includeLogLevel = false;
        
        EXPECT_CALL(channel, Settings)
            .WillOnce(Return(initialSettings));
        EXPECT_CALL(
            channel,
            SetSettings(
                FieldsAre(
                    expectedSettings.includeFatal,
                    expectedSettings.includeError,
                    expectedSettings.includeWarning,
                    expectedSettings.includeInfo,
                    expectedSettings.includeDebug,
                    expectedSettings.includeTrace,
                    expectedSettings.includeTimestamp,
                    expectedSettings.includeLogLevel)))
            .Times(1);

        channel.SetMinLogLevel(Logging::LogLevel::Warning);
    }

    TEST_F(OutputChannelTests, MinLogLevelErrorIncludesErrorAndAbove)
    {
        MockOutputChannel channel{};
        ChannelSettings expectedSettings;
        expectedSettings.includeFatal = true;
        expectedSettings.includeError = true;
        expectedSettings.includeWarning = false;
        expectedSettings.includeInfo = false;
        expectedSettings.includeDebug = false;
        expectedSettings.includeTrace = false;
        expectedSettings.includeTimestamp = false;
        expectedSettings.includeLogLevel = false;
        
        EXPECT_CALL(channel, Settings)
            .WillOnce(Return(initialSettings));
        EXPECT_CALL(
            channel,
            SetSettings(
                FieldsAre(
                    expectedSettings.includeFatal,
                    expectedSettings.includeError,
                    expectedSettings.includeWarning,
                    expectedSettings.includeInfo,
                    expectedSettings.includeDebug,
                    expectedSettings.includeTrace,
                    expectedSettings.includeTimestamp,
                    expectedSettings.includeLogLevel)))
            .Times(1);
        
        channel.SetMinLogLevel(Logging::LogLevel::Error);
    }

    TEST_F(OutputChannelTests, MinLogLevelFatalIncludesOnlyFatal)
    {
        MockOutputChannel channel{};
        ChannelSettings expectedSettings;
        expectedSettings.includeFatal = true;
        expectedSettings.includeError = false;
        expectedSettings.includeWarning = false;
        expectedSettings.includeInfo = false;
        expectedSettings.includeDebug = false;
        expectedSettings.includeTrace = false;
        expectedSettings.includeTimestamp = false;
        expectedSettings.includeLogLevel = false;
        
        EXPECT_CALL(channel, Settings)
            .WillOnce(Return(initialSettings));
        EXPECT_CALL(
            channel,
            SetSettings(
                FieldsAre(
                    expectedSettings.includeFatal,
                    expectedSettings.includeError,
                    expectedSettings.includeWarning,
                    expectedSettings.includeInfo,
                    expectedSettings.includeDebug,
                    expectedSettings.includeTrace,
                    expectedSettings.includeTimestamp,
                    expectedSettings.includeLogLevel)))
            .Times(1);

        channel.SetMinLogLevel(Logging::LogLevel::Fatal);
    }
}
