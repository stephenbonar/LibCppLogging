// ChannelSettings.h - Declares the ChannelSettings struct.
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

#ifndef LOGGER_CHANNEL_SETTINGS_H
#define LOGGER_CHANNEL_SETTINGS_H

namespace Logging
{
    struct ChannelSettings
    {
        bool includeFatal = false;
        bool includeError = false;
        bool includeWarning = false;
        bool includeInfo = false;
        bool includeDebug = false;
        bool includeTrace = false;
        bool includeTimestamp = false;
        bool includeLogLevel = false;
    };
}

#endif