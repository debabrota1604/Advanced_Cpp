#include <iostream>
#include <stack>

/*
One real-world example where CRTP is commonly used is in the implementation of type-safe container adapters, such as std::stack, std::queue, and std::priority_queue in the C++ Standard Library.

Let's focus on std::stack as an example:
*/

template<typename T>
class LoggingStack : public std::stack<T> {
public:
    // Override push() to add logging functionality
    void push(const T& value) {
        std::cout << "Pushing value: " << value << std::endl;
        std::stack<T>::push(value); // Call base class push()
    }
};

int main() {
    LoggingStack<int> stack;

    stack.push(5);
    stack.push(10);
    stack.push(15);

    while (!stack.empty()) {
        std::cout << "Top element: " << stack.top() << std::endl;
        stack.pop();
    }

    return 0;
}


/*
In this example:
    We create a new class LoggingStack that inherits publicly from std::stack<T>.
    We override the push() function to add logging functionality before calling the base class implementation.
    By inheriting from std::stack<T> with LoggingStack, we're essentially using the CRTP. The LoggingStack class is parameterized by the type T, and it provides additional functionality on top of std::stack<T>.
    This allows us to reuse the existing functionality of std::stack<T> while extending it with custom behavior specific to LoggingStack.

This pattern is very powerful because it allows us to create specialized versions of standard containers with additional functionality, all while leveraging the implementation details of the base class. It's a clear example of how CRTP can be applied in real-world scenarios to achieve code reuse and extensibility.
*/