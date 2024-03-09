#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

/*
A condition variable is a synchronization primitive that allows multiple threads to communicate with each other.

It enables some threads to wait (possibly with a timeout) for notification from another thread that they may proceed.

Condition variables are useful for scenarios where one thread needs to wait for a specific condition to be met before continuing.

*/

std::mutex mtx;
std::condition_variable cv;
bool ready = false;

void worker() {
    std::cout << "worker thread started" << std::endl;
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, [&]() { return ready; });
    std::cout << "Worker thread: Condition met! Exiting..." << std::endl;
}

int main() {
    std::thread t(worker);
    std::cout << "Main thread going to sleep for 2 sec" << std::endl;
    std::this_thread::sleep_for(std::chrono::seconds(2));
    {
        std::lock_guard<std::mutex> lock(mtx);
        ready = true;
    }
    cv.notify_one();
    t.join();
    return 0;
}

/*
debabrota@DEBABROTAs-MBP testDir % g++ condition_variable.cpp --std=c++11
debabrota@DEBABROTAs-MBP testDir % ./a.out                               
Main thread going to sleep for 2 sec
worker thread started
Worker thread: Condition met! Exiting...
debabrota@DEBABROTAs-MBP testDir % 
*/
