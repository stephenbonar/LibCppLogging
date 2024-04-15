// StandardError.cpp - Defines the StandardError class methods and functions.
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

#include "StandardError.h"

using namespace Logging;

StandardError::StandardError()
{
    // The default settings assume we want to include all errors on
    // standard error.
    settings.includeFatal = true;
    settings.includeError = true;
    settings.includeWarning = true;

    // The default settings also assume we wouldn't output informational or
    // other log level messages on standard error.
    settings.includeInfo = false;
    settings.includeTrace = false;
    settings.includeDebug = false;

    // The default assumes we don't want to see a timestamp on standard error.
    settings.includeTimestamp = false;

    // The default assumes we do want to see the prefix so we know what type
    // of error has occured.
    settings.includeLogLevel = false;
}

void StandardError::Write(LogMessage message)
{
    std::cerr << message.PrefixedText(settings) << std::endl;
}