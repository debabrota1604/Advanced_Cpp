#include <iostream>
#include <thread>
#include <atomic>

using namespace std;

atomic<int> sharedCounterAtomic(0); // Shared atomic counter

void incrementLockFree() {
    for (int i = 0; i < 100000; ++i) {
        sharedCounterAtomic.fetch_add(1, memory_order_relaxed); // Atomic increment
    }
}

int main() {
    thread t1(incrementLockFree);
    thread t2(incrementLockFree);

    t1.join();
    t2.join();

    cout << "Shared counter (lock-free): " << sharedCounterAtomic.load(memory_order_relaxed) << endl;
    return 0;
}
/*
In this code:
    We use an atomic<int> variable (sharedCounterAtomic) to achieve lock-free synchronization.
    Both threads increment the counter 100,000 times each using fetch_add.
    Atomic operations ensure that no locks are needed, allowing concurrent updates without blocking.
*/