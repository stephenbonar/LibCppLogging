// CTimeService.cpp - Defines the CTimeService class methods.
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

#include "CTimeService.h"

using namespace Logging;

std::string CTimeService::Now() const
{
    std::chrono::system_clock::time_point now = 
        std::chrono::system_clock::now();
    
    // Convert to a time_t so we can get the formatted time from ctime.
    std::time_t nowTimeT = std::chrono::system_clock::to_time_t(now);
    
    return std::ctime(&nowTimeT);
}
