#include <iostream>
#include <thread>
#include <vector>
#include <stack>
#include <shared_mutex>

class SharedStack {
public:
    void push(int value) {
        std::unique_lock<std::shared_mutex> writeLock(mutex_);
        stack_.push(value);
    }

    int pop() {
        std::unique_lock<std::shared_mutex> writeLock(mutex_);
        if (stack_.empty()) {
            return -1; // Stack is empty
        }
        int value = stack_.top();
        stack_.pop();
        return value;
    }

private:
    std::stack<int> stack_;
    mutable std::shared_mutex mutex_; // Mutable for read access
};

void producer(SharedStack& stack, int id) {
    for (int i = 0; i < 5; ++i) {
        stack.push(id * 100 + i);
        std::this_thread::sleep_for(std::chrono::milliseconds(10));
    }
}

void consumer(SharedStack& stack, int id) {
    for (int i = 0; i < 5; ++i) {
        int value = stack.pop();
        if (value != -1) {
            std::cout << "Consumer " << id << " popped: " << value << std::endl;
        } else {
            std::cout << "Consumer " << id << " found stack empty." << std::endl;
        }
        std::this_thread::sleep_for(std::chrono::milliseconds(20));
    }
}

int main() {
    SharedStack stack;

    std::vector<std::thread> producers;
    std::vector<std::thread> consumers;

    for (int i = 0; i < 3; ++i) {
        producers.emplace_back(producer, std::ref(stack), i);
        consumers.emplace_back(consumer, std::ref(stack), i);
    }

    for (auto& t : producers) {
        t.join();
    }
    for (auto& t : consumers) {
        t.join();
    }

    return 0;
}


/*
In this example:
    Multiple producer threads (producers) push values onto the shared stack.
    Multiple consumer threads (consumers) pop values from the stack.
    The SharedStack class uses a shared mutex to protect access to the stack.
    Producers and consumers can work concurrently without blocking each other.
    
Remember to adjust the sleep durations and customize the logic according to your specific use case.
*/