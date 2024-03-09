#include <iostream>
#include <thread>
#include <atomic>

std::atomic<int> count = 0;

void increase_counter(int i) {
    int old_value = count.load();
    while (!count.compare_exchange_weak(old_value, old_value + 1)) {
        // Keep retrying until the CAS succeeds
    }
}

int main() {
    const int thread_num = 10;
    std::thread t[thread_num];

    for (int i = 0; i < thread_num; ++i) {
        t[i] = std::thread(increase_counter, i);
    }

    for (int i = 0; i < thread_num; ++i) {
        t[i].join();
    }

    std::cout << "Final counter value: " << count << std::endl;
}


/*
Explanation:
    We define a shared counter as std::atomic<int> count.
    The increase_counter function attempts to increment the counter using CAS.
    If the CAS fails (i.e., another thread modified the counter), it retries until successful.
    The main function creates multiple threads, each calling increase_counter.
    
    
Remember that CAS ensures atomicity without busy waiting, making it a great choice for concurrent programming
*/