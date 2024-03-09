#include <iostream>
#include <vector>
#include <shared_mutex> // Include shared_mutex header

template <typename T>
class ThreadSafeVector {

private:
    std::vector<T> vec_;
    mutable std::shared_mutex mutex_; // Use shared_mutex, Mutable to allow locking in const member functions
public:
    // Constructor
    ThreadSafeVector() = default;

    // Add an element to the vector
    void push_back(const T& value) {
        std::lock_guard<std::shared_mutex> lock(mutex_);
        vec_.push_back(value);
    }

    // Get the size of the vector
    size_t size() const {
        std::lock_guard<std::shared_mutex> lock(mutex_);
        return vec_.size();
    }

    // Write an element to some index: LHS side
    T& operator[](int index) {
        std::unique_lock<std::shared_mutex> lock(mutex_);
        return vec_[index];
    }
    // Access an element by index (read-only) : RHS side
    const T& operator[](int index) const {
        std::shared_lock<std::shared_mutex> lock(mutex_);
        return vec_[index];
    }

    // Print all elements
    void print() const {
        std::lock_guard<std::shared_mutex> lock(mutex_);
        for (const auto& value : vec_) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }
};

int main() {
    ThreadSafeVector<int> tsVector;

    // Push elements from multiple threads
    for (int i = 0; i < 10; ++i) {
        tsVector.push_back(i);
    }

    // Access elements concurrently
    std::cout << "Vector size: " << tsVector.size() << std::endl;
    tsVector.print();

    // Modify an element
    tsVector[3] = 42;

    // Print modified elements
    tsVector.print();

    return 0;
}
