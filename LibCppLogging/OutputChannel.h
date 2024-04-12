// Program.cpp - Declares the OutputChannel class.
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

#ifndef LOGGING_OUTPUT_CHANNEL_H
#define LOGGING_OUTPUT_CHANNEL_H

#include "ChannelSettings.h"
#include "LogLevel.h"
#include "LogMessage.h"

namespace Logging
{
    class OutputChannel
    {
    public:
        virtual ~OutputChannel() = default;

        virtual ChannelSettings Settings() const = 0;

        virtual void SetSettings(ChannelSettings settings) = 0;

        virtual void SetMinLogLevel(LogLevel level) = 0;

        virtual void Write(LogMessage message) = 0;
    };
}

#endif