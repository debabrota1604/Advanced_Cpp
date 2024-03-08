#include<iostream>
#include "p1_logger.hpp"
using namespace std;

// Initialize/define all static members
int Logger::objCount =0;
Logger* Logger::loggerInstance = nullptr;
mutex Logger::mtx;

Logger::Logger(){
    Logger::objCount++;
    cout << "Logger instance created " << Logger::objCount << endl;
}

void Logger::logMsg(string msg){
    cout << msg << endl;
}

Logger* Logger::getLogger(){
    // Before the first instance is created, we need lock to avoid duplicate object creation. This is handled.
    // But after the one and only object is created, do we need the lock every time to access the static object? Answer is no.
    // The solution is to add another check before the mutex.lock() for "instance == nullptr"

    if(nullptr == loggerInstance){ // This new check is added
        mtx.lock();
        if(nullptr == loggerInstance){
            loggerInstance = new Logger();
        }
        cout << "Active logger instances: " << Logger::objCount << endl;
        mtx.unlock();
    }
    return loggerInstance;
}
