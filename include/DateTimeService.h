// DateTimeService.h - Declares the DateTimeService class.
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

#ifndef LOGGING_DATE_TIME_SERVICE_H
#define LOGGING_DATE_TIME_SERVICE_H

#include <string>

namespace Logging
{
    class DateTimeService
    {
    public:
        virtual ~DateTimeService() = default;

        virtual std::string Now() const = 0;
    };
}

#endif