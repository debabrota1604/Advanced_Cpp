#include <iostream>
#include <thread>
#include <future>

/*
std::promise is used by the producer/writer of an asynchronous operation, while std::future is used by the consumer/reader.
The producer sets a value using promise.set_value(...), and the consumer retrieves it using future.get().
*/

int main() {
    std::promise<std::string> promise;
    auto producer = std::thread([&] { promise.set_value("Hello, World!"); });
    auto future = promise.get_future();
    auto consumer = std::thread([&] { std::cout << future.get(); });
    producer.join();
    consumer.join();
    return 0;
}
// In this example, the producer sets the value “Hello, World!” using set_value, and the consumer retrieves it with get()