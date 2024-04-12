// Program.cpp - Declares the LogMessage class.
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

#ifndef LOGGING_LOG_MESSAGE_H
#define LOGGING_LOG_MESSAGE_H

#include <chrono>
#include <string>
#include "LogLevel.h"
#include "ChannelSettings.h"

namespace Logging
{
    class LogMessage
    {
    public:
        LogMessage(std::string text, LogLevel level);

        std::chrono::time_point<std::chrono::system_clock> Timestamp();

        LogLevel Level() const { return level; }

        std::string TimestampPrefix() const;

        std::string LevelPrefix() const;

        std::string Text() const { return text; }

        std::string PrefixedText(ChannelSettings settings) const;
    private:
        std::chrono::time_point<std::chrono::system_clock> timestamp;
        LogLevel level;
        std::string text;
    };
}

#endif