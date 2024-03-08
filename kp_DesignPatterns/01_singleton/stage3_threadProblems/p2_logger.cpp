#include<iostream>
#include "p1_logger.hpp"
using namespace std;


int Logger::objCount =0;
Logger* Logger::loggerInstance = nullptr;

Logger::Logger(){
    Logger::objCount++;
    cout << "Logger instance created " << Logger::objCount << endl;
}

void Logger::logMsg(string msg){
    cout << msg << endl;
}

Logger* Logger::getLogger(){
    if(nullptr == loggerInstance){ 
        loggerInstance = new Logger();
    }
    cout << "Active logger instances: " << Logger::objCount << endl;
    return loggerInstance;
}
