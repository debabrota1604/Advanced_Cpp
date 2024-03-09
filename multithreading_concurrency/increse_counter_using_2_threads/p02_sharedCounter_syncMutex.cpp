#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

#define LOOP 100000

int counter=0;
mutex mtx;

void increment() {
    int loop = LOOP;
    while(loop-->0){
        mtx.lock();
        counter +=1;
        mtx.unlock();
        //cout << this_thread::get_id() << ": After increment: " << counter << endl;
    }
}

void increment_RAII() {
    int loop = LOOP;
    while(loop-->0){
        lock_guard<mutex> lock(mutex); // lock persists till end of this scope
        counter +=1;
        //cout << this_thread::get_id() << ": After increment: " << counter << endl;
    }
}

int main() {
    thread t1(increment);
    thread t2(increment);

    t1.join();
    t2.join();
    std::cout << "Final counter value: " << counter << std::endl;

    return 0;
}
