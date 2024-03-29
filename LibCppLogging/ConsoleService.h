// ConsoleService.h - Declares the ConsoleService base class.
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

#ifndef LOGGING_CONSOLE_SERVICE_H
#define LOGGING_CONSOLE_SERVICE_H

#include <string>

namespace Logging
{
    class ConsoleService
    {
    public:
        /// @brief Destructs a ConsoleService.
        virtual ~ConsoleService() = default;

        virtual void WriteStandardOutput(std::string message) = 0;

        virtual void WriteLineStandardOutput(std::string message) = 0;

        virtual void WriteStandardError(std::string message) = 0;

        virtual void WriteLineStandardError(std::string message) = 0;
    };
}

#endif