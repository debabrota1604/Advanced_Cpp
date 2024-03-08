#include<iostream>
#include "p1_logger.hpp"
#include<thread>
using namespace std;


void user1Log(){
    Logger* logger1 = Logger::getLogger();
    logger1->logMsg("This msg is from user 1");
}
void user2Log(){
    Logger* logger2 = Logger::getLogger();
    logger2->logMsg("This msg is from user 2");
    
}

int main(){
    thread t1(user1Log);
    thread t2(user2Log);
    

    t1.join();
    t2.join();
    return 0;
}

/*
As mutex is costly, we need to avoid using it when the instance is already created.
*/