#include <iostream>
#include <thread>
#include <mutex>

using namespace std;

mutex mtx;

// Function to print odd or even numbers based on thread ID
void print_numbers(int& count, bool print_odd) {
    while (count < 10) {
        mtx.lock(); // Lock before access
        if ((print_odd && count % 2 != 0) || (!print_odd && count % 2 == 0)) {
            if (print_odd)
                cout << "ODD: " << count << endl;
            else
                cout << "EVEN: " << count << endl;
            count++;
        }
        mtx.unlock(); // Unlock post access
    }
}

int main() {
    int count = 1; // Shared variable to keep track of count

    thread t1(print_numbers, ref(count), true); // Thread for printing odd numbers
    thread t2(print_numbers, ref(count), false); // Thread for printing even numbers

    t1.join();
    t2.join();

    return 0;
}
