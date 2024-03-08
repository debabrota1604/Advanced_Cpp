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
    mtx.lock(); //Lock before critical section
    if(nullptr == loggerInstance){
        loggerInstance = new Logger();
    }
    cout << "Active logger instances: " << Logger::objCount << endl;
    mtx.unlock(); // Unlock after critical section
    return loggerInstance;
}