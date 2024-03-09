#include <iostream>
#include <thread>
#include <barrier> //requires c++20

std::barrier b(3); // Wait for 3 threads

void worker(int id) {
    std::cout << "Thread " << id << " started." << std::endl;
    b.arrive_and_wait();
    std::cout << "Thread " << id << " finished." << std::endl;
}

int main() {
    std::thread t1(worker, 1);
    std::thread t2(worker, 2);
    std::thread t3(worker, 3);
    t1.join();
    t2.join();
    t3.join();
    return 0;
}
