#include <iostream>
#include <shared_mutex>
#include <thread>

std::shared_mutex mutx; // Our shared mutex
int shared_data = 11;   // Shared data (initial value)

void readData() {
    std::shared_lock<std::shared_mutex> lock(mutx); // Acquire shared lock
    std::cout << "Read Thread " << std::this_thread::get_id() << ": ";
    std::cout << shared_data << std::endl;
}

void writeData(int n) {
    std::unique_lock<std::shared_mutex> lock(mutx); // Acquire unique (exclusive) lock
    shared_data = n; // Modify shared data
    std::cout << "Write Thread " << std::this_thread::get_id() << ": " << std::endl;
}

int main() {
    std::thread t1(readData); // Read thread
    std::thread t2(writeData, 128); // Write thread
    std::thread t3(writeData, 10); // Another write thread
    std::thread t4(readData); // Another read thread

    t1.join();
    t2.join();
    t3.join();
    t4.join();

    return 0;
}

/*
In this example:
    We create a shared mutex (mutx) that allows multiple threads to read the shared data simultaneously using shared locks.

    The readData function acquires a shared lock to read the data without blocking other readers.

    The writeData function acquires a unique (exclusive) lock to modify the shared data.

The output might look like this:
    Read Thread 140122977658432: 11
    Write Thread 140122960873024
    Write Thread 140122969265728
    Read Thread 140122952480320: 128

Remember that multiple threads can acquire shared locks simultaneously, but only one thread can acquire the exclusive lock at a time. This combination of shared and exclusive locks makes std::shared_mutex useful for scenarios with read-heavy access patterns and occasional writes
*/
