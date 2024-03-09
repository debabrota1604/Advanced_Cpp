#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

using namespace std;

mutex mtx;  // Mutex for synchronization
condition_variable cv; // Condition variable for synchronization

// Function to print odd numbers
void print_odd(int& count) {
    while (true) {
        unique_lock<mutex> lock(mtx); // Lock the mutex for exclusive access
        cv.wait(lock, [&] { return (count % 2 == 1) || (count >= 10); }); // Wait until it's the odd number's turn or count exceeds 10
        if (count >= 10) { 
            break; 
        }
        cout << "ODD: " << count << endl; 
        ++count; 
        cv.notify_one(); // Notify one waiting thread
    }
}

// Function to print even numbers
void print_even(int& count) {
    while (true) {
        unique_lock<mutex> lock(mtx); // Lock the mutex for exclusive access
        cv.wait(lock, [&] { return (count % 2 == 0) || (count >= 10); }); // Wait until it's the even number's turn or count exceeds 10
        if (count >= 10) { 
            break; 
        }
        cout << "EVEN: " << count << endl; 
        ++count; 
        cv.notify_one(); // Notify one waiting thread
    }
}

int main() {
    int count = 0; // Shared variable to keep track of count 

    thread t1(print_odd, ref(count)); // Thread for printing odd numbers
    thread t2(print_even, ref(count)); // Thread for printing even numbers

    t1.join(); 
    t2.join(); 

    return 0;
}
