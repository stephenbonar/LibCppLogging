// LogMessage.cpp - Defines the LogMessage class methods.
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

#include "LogMessage.h"

using namespace Logging;

LogMessage::LogMessage(
    std::string text, 
    LogLevel level, 
    DateTimeService* dateTimeService) :
    text{ text }, 
    level { level },
    dateTimeService { dateTimeService },
    timestamp{ "" }
{
}

std::string LogMessage::TimestampPrefix() const
{
    return dateTimeService->Now();
}

std::string LogMessage::LevelPrefix() const
{
    switch (level)
    {
        case LogLevel::Fatal:
            return "FATAL ERROR:";
        case LogLevel::Error:
            return "ERROR:";
        case LogLevel::Warning:
            return "WARNING:";
        case LogLevel::Info:
            return "INFO:";
        case LogLevel::Debug:
            return "DEBUG:";
        case LogLevel::Trace:
            return "TRACE:";
    }

    return "";
}

std::string LogMessage::PrefixedText(ChannelSettings settings) const
{
    std::stringstream stream;
    if (settings.includeTimestamp)
        stream << TimestampPrefix() << " ";
    if (settings.includeLogLevel)
        stream << LevelPrefix() << " ";
    stream << text;
    return stream.str();
}