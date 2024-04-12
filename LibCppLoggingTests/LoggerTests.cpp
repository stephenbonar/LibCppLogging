// LoggerTests.h - Defines the Logger tests.
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

#include "LoggerTests.h"

namespace Logging
{
    TEST_F(LoggerTests, ProperlyAddsOutputChannels)
    {
        Logger logger{};
        MockOutputChannel channel{};

        logger.Add(&channel);
        
        ASSERT_EQ(logger.Channels().size(), 1);
        EXPECT_EQ(logger.Channels().at(0), &channel);
    }

    TEST_F(LoggerTests, DoesNotAddNullChannels)
    {
        Logger logger{};

        EXPECT_THROW(logger.Add(nullptr), std::invalid_argument);
    }

    TEST_F(LoggerTests, ProperlyRemovesOutputChannels)
    {
        Logger logger{};
        MockOutputChannel channel1{};
        MockOutputChannel channel2{};

        logger.Add(&channel1);
        logger.Add(&channel2);
        logger.Remove(&channel1);
        
        ASSERT_EQ(logger.Channels().size(), 1);
        EXPECT_NE(logger.Channels().at(0), &channel1);
        EXPECT_EQ(logger.Channels().at(0), &channel2);
    }

    TEST_F(LoggerTests, WritesToMultipleChannels)
    {
        Logger logger{};
        MockOutputChannel channel1{};
        MockOutputChannel channel2{};
        logger.Add(&channel1);
        logger.Add(&channel2);
        ChannelSettings settings;
        settings.includeFatal = true;
        settings.includeError = true;
        settings.includeWarning = true;
        settings.includeInfo = true;
        settings.includeDebug = true;
        settings.includeTrace = true;

        EXPECT_CALL(channel1, Settings)
            .WillOnce(Return(settings));
        EXPECT_CALL(channel2, Settings)
            .WillOnce(Return(settings));
        EXPECT_CALL(channel1, Write(_))
            .Times(1);
        EXPECT_CALL(channel2, Write(_))
            .Times(1);
        
        logger.Write("Writing to both channels");
    }

    TEST_F(LoggerTests, IncludingFatalWritesToChannel)
    {
        Logger logger{};
        MockOutputChannel channel;
        ChannelSettings settings;
        settings.includeFatal = true;
        logger.Add(&channel);

        EXPECT_CALL(channel, Settings)
            .WillOnce(Return(settings));
        EXPECT_CALL(
            channel, 
            Write(Property(&LogMessage::Level, LogLevel::Fatal)))
            .Times(1);

        logger.Write("Fatal Test", LogLevel::Fatal);
    }

    TEST_F(LoggerTests, IncludingErrorWritesToChannel)
    {
        Logger logger{};
        MockOutputChannel channel;
        ChannelSettings settings;
        settings.includeError = true;
        logger.Add(&channel);

        EXPECT_CALL(channel, Settings)
            .WillOnce(Return(settings));
        EXPECT_CALL(
            channel, 
            Write(Property(&LogMessage::Level, LogLevel::Error)))
            .Times(1);

        logger.Write("Error Test", LogLevel::Error);
    }

    TEST_F(LoggerTests, IncludingWarningWritesToChannel)
    {
        Logger logger{};
        MockOutputChannel channel;
        ChannelSettings settings;
        settings.includeWarning = true;
        logger.Add(&channel);

        EXPECT_CALL(channel, Settings)
            .WillOnce(Return(settings));
        EXPECT_CALL(
            channel, 
            Write(Property(&LogMessage::Level, LogLevel::Warning)))
            .Times(1);

        logger.Write("Warning Test", LogLevel::Warning);
    }

    TEST_F(LoggerTests, IncludingInfoWritesToChannel)
    {
        Logger logger{};
        MockOutputChannel channel;
        ChannelSettings settings;
        settings.includeInfo = true;
        logger.Add(&channel);

        EXPECT_CALL(channel, Settings)
            .WillOnce(Return(settings));
        EXPECT_CALL(
            channel, 
            Write(Property(&LogMessage::Level, LogLevel::Info)))
            .Times(1);

        logger.Write("Info Test", LogLevel::Info);
    }
    
    TEST_F(LoggerTests, IncludingDebugWritesToChannel)
    {
        Logger logger{};
        MockOutputChannel channel;
        ChannelSettings settings;
        settings.includeDebug = true;
        logger.Add(&channel);

        EXPECT_CALL(channel, Settings)
            .WillOnce(Return(settings));
        EXPECT_CALL(
            channel, 
            Write(Property(&LogMessage::Level, LogLevel::Debug)))
            .Times(1);

        logger.Write("Debug Test", LogLevel::Debug);
    }

    TEST_F(LoggerTests, IncludingTraceWritesToChannel)
    {
        Logger logger{};
        MockOutputChannel channel;
        ChannelSettings settings;
        settings.includeTrace = true;
        logger.Add(&channel);

        EXPECT_CALL(channel, Settings)
            .WillOnce(Return(settings));
        EXPECT_CALL(
            channel, 
            Write(Property(&LogMessage::Level, LogLevel::Trace)))
            .Times(1);

        logger.Write("Trace Test", LogLevel::Trace);
    }

    TEST_F(LoggerTests, OnlyWritesToIncludedChannels)
    {
        Logger logger{};
        MockOutputChannel channel;
        ChannelSettings settings;
        settings.includeInfo = true;
        settings.includeError = true;
        settings.includeFatal = true;
        logger.Add(&channel);

        EXPECT_CALL(channel, Settings)
            .Times(6)
            .WillRepeatedly(Return(settings));
        EXPECT_CALL(
            channel, 
            Write(Property(&LogMessage::Level, LogLevel::Fatal)))
            .Times(1);
        EXPECT_CALL(
            channel, 
            Write(Property(&LogMessage::Level, LogLevel::Error)))
            .Times(1);
        EXPECT_CALL(
            channel, 
            Write(Property(&LogMessage::Level, LogLevel::Warning)))
            .Times(0);
        EXPECT_CALL(
            channel, 
            Write(Property(&LogMessage::Level, LogLevel::Info)))
            .Times(1);
        EXPECT_CALL(
            channel, 
            Write(Property(&LogMessage::Level, LogLevel::Debug)))
            .Times(0);
        EXPECT_CALL(
            channel, 
            Write(Property(&LogMessage::Level, LogLevel::Trace)))
            .Times(0);

        logger.Write("Test Fatal", LogLevel::Fatal);
        logger.Write("Test Error", LogLevel::Error);
        logger.Write("Test Warning", LogLevel::Warning);
        logger.Write("Test Info", LogLevel::Info);
        logger.Write("Test Debug", LogLevel::Debug);
        logger.Write("Test Trace", LogLevel::Trace);
    }
}
