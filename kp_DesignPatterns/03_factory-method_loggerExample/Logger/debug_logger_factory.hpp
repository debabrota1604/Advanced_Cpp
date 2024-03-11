#pragma once

#include "logger_factory.hpp"

class DebugLoggerFactory : public ILoggerFactory{
    public:
        ILogger* createLogger() {
            return new DebugLogger();
        }
};

/*
From Simple factory's logger_factory.cpp:

ILogger* LoggerFactory::createLogger(LogLevel pLogLevel) {
    if(pLogLevel == LogLevel::DEBUG)
        return new DebugLogger();
    if(pLogLevel == LogLevel::INFO)
        return new InfoLogger();
    if(pLogLevel == LogLevel::ERROR)
        return new ErrorLogger();
    return nullptr;
}

This if-else have been broken down into separate logger interfaces: debug, info and error
*/