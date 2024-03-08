#include <string>
using namespace std;


class Logger{
    static int objCount;
    public:
        Logger();
        void logMsg(string msg);
}; 