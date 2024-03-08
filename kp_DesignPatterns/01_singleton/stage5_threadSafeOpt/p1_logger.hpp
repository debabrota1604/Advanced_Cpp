#include <string>
#include<mutex>
using namespace std;


class Logger{
        static int objCount;
        Logger();
        static Logger* loggerInstance;
        static mutex mtx;
    public:
        static Logger* getLogger();
        void logMsg(string msg);


        Logger operator=(const Logger&) = delete;
        Logger(const Logger&) = delete;
}; 