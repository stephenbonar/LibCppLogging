// CTimeService.h - Declares the CTimeService class.
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

#ifndef CTIME_SERVICE_H
#define CTIME_SERVICE_H

#include <string>
#include <chrono>
#include <ctime>
#include "DateTimeService.h"

namespace Logging
{
    class CTimeService : public DateTimeService
    {
    public:
        std::string Now() const override;
    };
}

#endif