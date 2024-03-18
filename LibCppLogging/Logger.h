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
#include <memory>
#include "LogService.h"
#include "Level.h"
#include "Destination.h"

namespace Logging
{
    /// @brief Provides the ability to log messages to the console or a file.
    class Logger
    {
    public:
        /// @brief Creates a new instance of Logger.
        /// @param service The log service to inject into the logger.
        /// @param minLevel The minimum logging level to include.
        /// @invariant The service should not be null.
        Logger(
            std::shared_ptr<LogService> service, 
            Level minLevel = Level::Info);

        /// @brief Writes a message to the logging destination.
        /// @param message The message to write to the logging destination.
        /// @param level The logging level of the message.
        void Write(std::string message, Level level = Level::Info);

        /// @brief Writes a message to the logging destination with a new line.
        /// @param message The message to write to the logging destination.
        /// @param level The logging level of the message.
        void WriteLine(std::string message, Level level = Level::Info);
    private:
        std::string fileName;
        Level minLevel;
        Destination destination;
    };
}

#endif