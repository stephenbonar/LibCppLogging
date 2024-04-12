// Logger.cpp - Defines the Logger class methods and functions.
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

#include "Logger.h"

using namespace Logging;

void Logger::Write(std::string message, LogLevel level)
{
    for (OutputChannel* channel : channels)
    {
        ChannelSettings settings = channel->Settings();
        LogMessage logMessage{ message, level };
        switch (level)
        {
            case LogLevel::Fatal:
                if (settings.includeFatal)
                    channel->Write(logMessage);
                break;
            case LogLevel::Error:
                if (settings.includeError)
                    channel->Write(logMessage);
                break;
            case LogLevel::Warning:
                if (settings.includeWarning)
                    channel->Write(logMessage);
                break;
            case LogLevel::Info:
                if (settings.includeInfo)
                    channel->Write(logMessage);
                break;
            case LogLevel::Debug:
                if (settings.includeDebug)
                    channel->Write(logMessage);
                break;
            case LogLevel::Trace:
                if (settings.includeTrace)
                    channel->Write(logMessage);
                break;
        }
    }
}

void Logger::WriteLine(std::string message, LogLevel level)
{

}

void Logger::Add(OutputChannel* channel)
{
    if (channel == nullptr)
        throw std::invalid_argument{ "Cannot add null channel" };
    channels.push_back(channel);
}

void Logger::Remove(OutputChannel* channel)
{
    auto result = std::find(channels.begin(), channels.end(), channel);
    if (result != channels.end())
    {
        channels.erase(result);
    }
}
