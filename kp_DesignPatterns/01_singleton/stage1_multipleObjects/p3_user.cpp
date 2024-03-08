#include<iostream>
#include "p1_logger.hpp"
using namespace std;


int main(){
    Logger* logger1 = new Logger();
    logger1->logMsg("This msg is from user 1");

    Logger* logger2 = new Logger();
    logger2->logMsg("This msg is from user 2");
    return 0;
}

/*
For two invocation of the constructor, two logger objects are created. This is the problem we want to solve.
Our next task is to prohibit the creation of multiple objects.
*/

