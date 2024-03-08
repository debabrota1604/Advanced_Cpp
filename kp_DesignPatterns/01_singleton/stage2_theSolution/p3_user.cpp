#include<iostream>
#include "p1_logger.hpp"
using namespace std;


int main(){
    Logger* logger1 = Logger::getLogger();
    logger1->logMsg("This msg is from user 1");

    Logger* logger2 = Logger::getLogger();
    logger2->logMsg("This msg is from user 2");
    return 0;
}