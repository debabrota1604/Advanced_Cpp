/*
Purpose:
    std::async is designed for asynchronous execution of a function or callable object.
    It allows you to launch a task and obtain a future to retrieve its result.
Abstraction Level:
    Higher level of abstraction compared to std::thread.
    Abstracts away thread management details.
Execution Context:
    The system decides whether the associated function should run asynchronously or synchronously.
    Usually implemented using thread pools.
Ownership and Cleanup:
    The thread destructor is called automatically when the std::async task completes.
    Reduces the risk of concurrency bugs.
Use Cases:
    Well-suited for long-running computations or IO-bound tasks.
    Not ideal for finer-grained workloads due to potential overhead.
*/

#include <iostream>
#include <future>

int main() {
    auto future = std::async([] { return "Hello from async!"; });
    std::cout << future.get() << std::endl;
    return 0;
}
