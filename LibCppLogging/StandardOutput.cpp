// StandardOutput.cpp - Defines the StandardOutput class methods and functions.
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

#include "StandardOutput.h"

using namespace Logging;

StandardOutput::StandardOutput()
{
    // The default settings assume we don't want to see error messages on
    // standard output since those should be logged to standard error
    // instead.
    settings.includeFatal = false;
    settings.includeError = false;
    settings.includeWarning = false;

    // The default settings assume we want informational messages on standard
    // output but suppress debug / trace as those shouldn't be on by default.
    settings.includeInfo = true;
    settings.includeTrace = false;
    settings.includeDebug = false;

    // We assumed standard output is not going to want to see timestamps or
    // prefixes under normal operation (those would likely go to a log file).
    settings.includeTimestamp = false;
    settings.includeLogLevel = false;
}

void StandardOutput::Write(LogMessage message)
{
    std::cout << message.PrefixedText(settings) << std::endl;
}