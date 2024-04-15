// LogFile.cpp - Defines the LogFile class methods and functions.
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

#include "LogFile.h"

using namespace Logging;

LogFile::LogFile(std::string fileName)
{
    // The default settings assume we want to log all errors to the log file.
    settings.includeFatal = true;
    settings.includeError = true;
    settings.includeWarning = true;

    // The default settings assume we want informational messages written to
    // the log file.
    settings.includeInfo = true;

    // The default settings assume trace and debug should not write to the log
    // file by default and should only be turned on as necessary.
    settings.includeTrace = false;
    settings.includeDebug = false;

    // The default settings assume we want both the timestamp and the log level
    // written to the log file.
    settings.includeTimestamp = true;
    settings.includeLogLevel = true;

    writeStream = std::ofstream{ fileName };
}

void LogFile::Write(LogMessage message)
{
    writeStream << message.PrefixedText(settings) << std::endl;
}