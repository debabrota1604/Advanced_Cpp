#include <iostream>
#include <atomic>
#include<thread>
using namespace std;

#define LOOP 100000

atomic<int> counter(0);

void increment() {
    int loop = LOOP;
    while(loop-->0){
        ++counter;
        //cout << this_thread::get_id() << ": After increment: " << counter << endl;
    }
}

int main() {
    thread t1(increment);
    thread t2(increment);

    t1.join();
    t2.join();
    cout << "Final counter value: " << counter << endl;
    return 0;
}
