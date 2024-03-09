#include <iostream>
#include <thread>
using namespace std;

#define LOOP 100000

int counter=0;

void increment() {
    int loop = LOOP;
    while(loop-->0){
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

    /*
    As there is no lock, both threads change the counter value and the final value ends up between loop, nThreads*loop.
    */

    return 0;
}
