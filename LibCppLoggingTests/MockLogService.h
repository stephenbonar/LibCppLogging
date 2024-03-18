#ifndef LOGGING_MOCK_LOG_SERVICE
#define LOGGING_MOCK_LOG_SERVICE

#include <gmock/gmock.h>
#include "LogService.h"

namespace Logging
{
    class MockLogService : public LogService
    {
    public:
        MOCK_METHOD(void, WriteStandardOutput, (std::string message), (const, override));
        MOCK_METHOD(void, WriteLineStandardOutput, (std::string message), (const, override));
        MOCK_METHOD(void, WriteStandardError, (std::string message), (const, override));
        MOCK_METHOD(void, WriteLineStandardError, (std::string message), (const, override));
    };
}

#endif