#include <iostream>
#include <thread>
#include <atomic>

using namespace std;

atomic<int> counter(1); // Shared counterer variable

// Function to print odd numbers
void print_odd() {
    while (counter <= 10) {
        int current_counter = counter.load(memory_order_relaxed); // Read the current value
        if (current_counter % 2 != 0) {
            cout << "ODD: " << current_counter << endl;
            counter.fetch_add(1, memory_order_relaxed); // Increment the counterer
        }
    }
}

// Function to print even numbers
void print_even() {
    while (counter <= 10) {
        int current_counter = counter.load(memory_order_relaxed); // Read the current value
        if (current_counter % 2 == 0) {
            cout << "EVEN: " << current_counter << endl;
            counter.fetch_add(1, memory_order_relaxed); // Increment the counterer
        }
    }
}

int main() {
    // Start two threads
    thread t1(print_odd);
    thread t2(print_even);

    // Join the threads
    t1.join();
    t2.join();

    return 0;
}
