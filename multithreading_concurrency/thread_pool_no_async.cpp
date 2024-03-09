#include <iostream>
#include <functional>
#include <vector>
#include <queue>
#include <thread>
#include <mutex>
#include <condition_variable>

/*
Below is an example of a simple C++ thread pool class that you can use to create a thread pool with a fixed number of threads during initialization. You can enqueue tasks to be executed by the worker threads, and the threads will automatically handle them. At program exit, the threads will be joined and properly cleaned up.
*/

class ThreadPool {
public:
    explicit ThreadPool(size_t num_threads) {
        for (size_t i = 0; i < num_threads; ++i) {
            threads_.emplace_back([this] {
                while (true) {
                    std::function<void()> task;
                    {
                        std::unique_lock<std::mutex> lock(queue_mutex_);
                        cv_.wait(lock, [this] { return !tasks_.empty() || stop_; });
                        if (stop_ && tasks_.empty()) {
                            return;
                        }
                        task = std::move(tasks_.front());
                        tasks_.pop();
                    }
                    task();
                }
            });
        }
    }

    ~ThreadPool() {
        {
            std::unique_lock<std::mutex> lock(queue_mutex_);
            stop_ = true;
        }
        cv_.notify_all();
        for (auto& thread : threads_) {
            thread.join();
        }
    }

    void enqueue(std::function<void()> task) {
        {
            std::unique_lock<std::mutex> lock(queue_mutex_);
            tasks_.emplace(std::move(task));
        }
        cv_.notify_one();
    }

private:
    std::vector<std::thread> threads_;
    std::queue<std::function<void()>> tasks_;
    std::mutex queue_mutex_;
    std::condition_variable cv_;
    bool stop_ = false;
};

int main() {
    ThreadPool pool(4);

    // Enqueue some tasks
    for (int i = 0; i < 5; ++i) {
        pool.enqueue([i] {
            std::cout << "Task " << i << " is running on thread " << std::this_thread::get_id() << std::endl;
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        });
    }

    // The pool will be automatically cleaned up when it goes out of scope

    return 0;
}


/*
In this example:
    The ThreadPool class manages a pool of worker threads.
    Worker threads wait for tasks to be enqueued and execute them.
    The enqueue function adds tasks to the queue.
    
When the ThreadPool object is destroyed (e.g., at program exit), the threads are joined and properly cleaned up.
*/