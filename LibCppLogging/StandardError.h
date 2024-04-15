// StandardError.h - Declares the StandardError class.
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

#ifndef LOGGING_STANDARD_ERROR_H
#define LOGGING_STANDARD_ERROR_H

#include <iostream>
#include "ChannelSettings.h"
#include "LogLevel.h"
#include "LogMessage.h"
#include "OutputChannel.h"

namespace Logging
{
    class StandardError : public OutputChannel
    {
    public:
        StandardError();
        
        virtual ChannelSettings Settings() const override { return settings; }

        virtual void SetSettings(ChannelSettings settings) override 
        {
            this->settings = settings; 
        }

        virtual void Write(LogMessage message) override;
    private:
        ChannelSettings settings;
    };
}

#endif