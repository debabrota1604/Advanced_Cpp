/*
Non-blocking Algorithm:
    In a non-blocking algorithm, a thread can perform other tasks or be scheduled to do other work while waiting for an operation to complete or a condition to be met.
    
    These algorithms are often more complex to implement as they require mechanisms like asynchronous I/O, event loops, or atomic operations.
    
    Non-blocking algorithms can improve system responsiveness and scalability by allowing threads to continue working on other tasks instead of waiting idly.
    
Here's a simple example of a non-blocking algorithm using std::atomic for atomic operations:
*/

#include <iostream>
#include <thread>
#include <atomic>

std::atomic<int> shared_data(0);

void increment_data() {
    for (int i = 0; i < 1000000; ++i) {
        shared_data.fetch_add(1, std::memory_order_relaxed);
    }
}

int main() {
    std::thread t1(increment_data);
    std::thread t2(increment_data);

    t1.join();
    t2.join();

    std::cout << "Final value of shared_data: " << shared_data << std::endl;

    return 0;
}

/*
In this example, two threads increment the value of shared_data concurrently using atomic operations. The threads do not block each other, and the increment operation is non-blocking.
*/