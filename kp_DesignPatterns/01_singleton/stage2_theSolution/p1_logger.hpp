#include <string>
using namespace std;


class Logger{
        static int objCount;
        Logger(); //Step1: Make the constructor private to prohibit new object creation
        static Logger* loggerInstance; // Step2: Create a static obj pointer that will be returned for all calls
    public:
        static Logger* getLogger(); // Step3: Use the custom getObj function to access the instance
        void logMsg(string msg);

        // Block the other ways to call the constructor: The copy constructor and operator=() overload
        Logger operator=(const Logger&) = delete;
        Logger(const Logger&) = delete;
}; 