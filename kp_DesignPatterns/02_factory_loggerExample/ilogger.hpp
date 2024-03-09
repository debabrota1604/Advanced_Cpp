#pragma once
#include "common.hpp"

// Interface class for the loggers

class ILogger {
    public:
        virtual void log(const string& msg) = 0; //virtual function to be implemented by all custom loggers
        virtual ~ILogger() {}
};