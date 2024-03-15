#include "logger_factory.hpp"

ILogger* LoggerFactory::createLogger(LogLevel pLogLevel) {
    if(pLogLevel == LogLevel::DEBUG)
        return new DebugLogger();
    if(pLogLevel == LogLevel::INFO)
        return new InfoLogger();
    if(pLogLevel == LogLevel::ERROR)
        return new ErrorLogger();
    return nullptr;
}

/*
If I need to add a new logger, I need to make change in this class, which violates the OCP of SOLID.
Solution is to use factory_method design pattern.
*/