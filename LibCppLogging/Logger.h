// Program.cpp - Declares the Logger class.
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

#ifndef LOGGING_LOGGER_H
#define LOGGING_LOGGER_H

#include <string>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include "CTimeService.h"
#include "OutputChannel.h"
#include "LogMessage.h"
#include "LogLevel.h"

namespace Logging
{
    /// @brief Provides the ability to log messages to different channels.
    class Logger
    {
    public:
        /// @brief Creates a new instance of Logger.
        Logger();

        void Write(std::string message, LogLevel level = LogLevel::Info);

        /// @brief Adds the specified OutputChannel to the logger.
        /// @param channel The channel to add.
        /// @pre Channel is not null.
        /// @exception Throws std::invalid_argument exception on null.
        void Add(OutputChannel* channel);

        /// @brief Removes the specified OutputChannel from the logger.
        /// @param channel The channel to remove.
        void Remove(OutputChannel* channel);

        std::vector<OutputChannel*> Channels() { return channels; }
    private:
        std::vector<OutputChannel*> channels;
        CTimeService timeService;
    };
}

#endif