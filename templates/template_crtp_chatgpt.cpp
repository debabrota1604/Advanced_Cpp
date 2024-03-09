#include<bits/stdc++.h>

/*
CRTP stands for Curiously Recurring Template Pattern. It's a design pattern in C++ that involves using templates and inheritance to achieve static polymorphism. The basic idea behind CRTP is to have a base class template that takes a derived class as a template parameter. The derived class inherits from the base class, passing itself as the template argument to the base class. This allows the base class to access members of the derived class through static polymorphism.

Here's a simple example to illustrate the CRTP:
*/


// Base class template using CRTP
template <typename Derived>
class Base {
public:
    void interface() {
        // Call implementation from the derived class
        static_cast<Derived*>(this)->implementation();
    }

    // This is a static polymorphic function
    void sharedFunction() {
        std::cout << "Base sharedFunction()" << std::endl;
    }
};

// Derived class inheriting from Base using CRTP
class DerivedClass : public Base<DerivedClass> {
public:
    void implementation() {
        std::cout << "DerivedClass implementation()" << std::endl;
    }

    // This function overrides the sharedFunction of Base
    void sharedFunction() {
        std::cout << "Derived sharedFunction()" << std::endl;
    }
};

int main() {
    DerivedClass obj;
    obj.interface(); // Calls DerivedClass implementation()
    obj.sharedFunction(); // Calls Derived sharedFunction()

    return 0;
}



/*
In this example:
    Base is a template class that expects a derived class type as a template parameter.
    interface() is a member function of Base that calls a virtual function named implementation() from the derived class. It uses static polymorphism to call the appropriate function.
    DerivedClass inherits from Base<DerivedClass>, passing itself as the template argument to Base.
    implementation() is a virtual function in the derived class that provides the implementation specific to that class.
    sharedFunction() is a member function in both Base and DerivedClass. When called on an object of DerivedClass, it overrides the implementation in Base.
CRTP is useful in scenarios where you want to achieve compile-time polymorphism without the overhead of virtual function calls, as it allows the compiler to inline function calls. It's commonly used in template libraries and for performance-critical code where dynamic polymorphism is not necessary.
*/