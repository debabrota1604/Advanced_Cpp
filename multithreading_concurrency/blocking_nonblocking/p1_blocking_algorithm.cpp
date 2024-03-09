/*
Blocking and non-blocking algorithms in C++ refer to different approaches for handling concurrency and parallelism.
*/

/*
Blocking Algorithm:
    In a blocking algorithm, a thread is typically paused or blocked until a certain condition is met, such as the completion of an I/O operation or the availability of data.

    These algorithms often involve synchronization primitives like mutexes, condition variables, or semaphores to coordinate between threads.

    Blocking algorithms are more straightforward to implement but may lead to inefficiencies in resource utilization, especially in systems with a large number of threads.

Here's a simple example of a blocking algorithm using mutex and condition variables to synchronize access to a shared resource:
*/

#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>

std::mutex mtx;
std::condition_variable cv;
bool data_ready = false;
int shared_data = 0;

void producer() {
    std::this_thread::sleep_for(std::chrono::seconds(2)); // Simulate some work
    {
        std::lock_guard<std::mutex> lock(mtx);
        shared_data = 42;
        data_ready = true;
    }
    cv.notify_one();
}

void consumer() {
    std::unique_lock<std::mutex> lock(mtx);
    cv.wait(lock, []{ return data_ready; });
    std::cout << "Consumed data: " << shared_data << std::endl;
}

int main() {
    std::thread producer_thread(producer);
    std::thread consumer_thread(consumer);

    producer_thread.join();
    consumer_thread.join();

    return 0;
}

/*
In this example, the consumer function waits until data_ready becomes true, indicating that the producer thread has produced data. It blocks the execution until notified by the producer thread.
*/
