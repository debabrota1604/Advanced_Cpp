#include <iostream>
using namespace std;

enum class LogLevel { DEBUG, INFO, ERROR };

class ILogger {
    public:
        virtual void log(const string& msg) = 0;
        virtual ~ILogger() {}
};

class DebugLogger : public ILogger {
    public:
        void log(const string& msg){ cout<<"DEBUG : "<<msg<<endl; }
};

class ErrorLogger : public ILogger{
    public:
        void log(const string& msg){ cout<<"ERROR : "<<msg<<endl; }
};

class InfoLogger : public ILogger {
    public:
        void log(const string& msg){ cout<<"INFO : "<<msg<<endl; }
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

class ILoggerFactory {
    public:
        virtual ILogger* createLogger() = 0;
};

class DebugLoggerFactory : public ILoggerFactory{
    public:
        ILogger* createLogger() {
            return new DebugLogger();
        }
};

class ErrorLoggerFactory : public ILoggerFactory{
    public:
        ILogger* createLogger() {
            return new ErrorLogger();
        }
};
class InfoLoggerFactory : public ILoggerFactory{
    public:
        ILogger* createLogger() {
            return new InfoLogger();
        }
};


int main() {
    ILoggerFactory* loggerFactory1 = new InfoLoggerFactory;
    ILogger* infoLogger = loggerFactory1->createLogger();

    ILoggerFactory* loggerFactory2 = new ErrorLoggerFactory;
    ILogger* errorLogger = loggerFactory2->createLogger();

    ILoggerFactory* loggerFactory3 = new DebugLoggerFactory;
    ILogger* debugLogger = loggerFactory3->createLogger();

    debugLogger->log("This is a debug log msg");
    infoLogger->log("This is an info log msg");
    errorLogger->log("This is an error log msg");

    delete debugLogger;
    delete infoLogger;
    delete errorLogger;

    return 0;
}