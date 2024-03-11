#include <iostream>

class MyOperators {
public:
    int value;

    // Constructor to initialize the value
    MyOperators() : value(0) {}
    MyOperators(int val) : value(val) {}

// Arithmetic Operators    

    // Overload the addition operator (+)
    MyOperators operator+(const MyOperators& other) const {
        return MyOperators(value + other.value);
    }

    // Overload the subtraction operator (-)
    MyOperators operator-(const MyOperators& other) const {
        return MyOperators(value - other.value);
    }

    // Overload the multiplication operator (*)
    MyOperators operator*(const MyOperators& other) const {
        return MyOperators(value * other.value);
    }

    // Overload the division operator (/)
    MyOperators operator/(const MyOperators& other) const {
        if (other.value != 0) {
            return MyOperators(value / other.value);
        } else {
            std::cerr << "Error: Division by zero!" << std::endl;
            return MyOperators(0);
        }
    }

    // Overload the modulo operator (%)
    MyOperators operator%(const MyOperators& other) const {
        if (other.value != 0) {
            return MyOperators(value % other.value);
        } else {
            std::cerr << "Error: Division by zero!" << std::endl;
            return MyOperators(0);
        }
    }

// Overload the compound assignment operators
    MyOperators& operator+=(const MyOperators& other) {
        value += other.value;
        return *this;
    }

    MyOperators& operator-=(const MyOperators& other) {
        value -= other.value;
        return *this;
    }

    MyOperators& operator*=(const MyOperators& other) {
        value *= other.value;
        return *this;
    }

    MyOperators& operator/=(const MyOperators& other) {
        if (other.value != 0) {
            value /= other.value;
        } else {
            std::cerr << "Error: Division by zero!" << std::endl;
            value = 0;
        }
        return *this;
    }

//Logical Operators

    // Overload the equality operator (==)
    bool operator==(const MyOperators& other) const {
        return value == other.value;
    }

    // Overload the inequality operator (!=)
    bool operator!=(const MyOperators& other) const {
        return value != other.value;
    }

    // Overload the less than operator (<)
    bool operator<(const MyOperators& other) const {
        return value < other.value;
    }

    // Overload the greater than operator (>)
    bool operator>(const MyOperators& other) const {
        return value > other.value;
    }

    // Overload the less than or equal to operator (<=)
    bool operator<=(const MyOperators& other) const {
        return value <= other.value;
    }

    // Overload the greater than or equal to operator (>=)
    bool operator>=(const MyOperators& other) const {
        return value >= other.value;
    }

    // Overload the assignment operator (=)
    MyOperators& operator=(const MyOperators& other) {
        if (this != &other) {
            value = other.value;
        }
        return *this;
    }

// unary operators: ++x and x++

    // Overload the prefix increment operator (++)
    MyOperators& operator++() {
        ++value;
        return *this;
    }

    // Overload the postfix increment operator (++)
    MyOperators operator++(int) {
        MyOperators temp(*this);
        ++value;
        return temp;
    }

//Bitwise operators

    // Bitwise AND operator
    MyOperators operator&(const MyOperators& other) const {
        MyOperators result;
        result.value = value & other.value;
        return result;
    }

    // Bitwise OR operator
    MyOperators operator|(const MyOperators& other) const {
        MyOperators result;
        result.value = value | other.value;
        return result;
    }

    // Left shift operator
    MyOperators operator<<(int shift) const {
        MyOperators result;
        result.value = value << shift;
        return result;
    }

    // Right shift operator
    MyOperators operator>>(int shift) const {
        MyOperators result;
        result.value = value >> shift;
        return result;
    }

    // Bitwise NOT operator
    MyOperators operator~() const {
        MyOperators result;
        result.value = ~value;
        return result;
    }

    // Bitwise XOR operator
    MyOperators operator^(const MyOperators& other) const {
        MyOperators result;
        result.value = value ^ other.value;
        return result;
    }

// Additional bitwise operators
    MyOperators& operator&=(const MyOperators& other) {
        value &= other.value;
        return *this;
    }

    MyOperators& operator|=(const MyOperators& other) {
        value |= other.value;
        return *this;
    }

    MyOperators& operator<<=(const MyOperators& other) {
        value <<= other.value;
        return *this;
    }

    MyOperators& operator>>=(const MyOperators& other) {
        value >>= other.value;
        return *this;
    }

    MyOperators& operator^=(const MyOperators& other) {
        value ^= other.value;
        return *this;
    }

//Overloading special operators

    // Overload the function call operator ()
    int operator()() const { //Not relevant for this example, just for syntax
        return value;
    }

    // Overload the subscript operator []
    int operator[](int index) const { //Not relevant for this example, just for syntax
        // Example: myOperators[0] returns the value itself
        return value;
    }

    // Overload the new operator
    void* operator new(size_t size) {
        std::cout << "Overloading new operator with size: " << size << std::endl;
        void* p = ::operator new(size);
        return p;
    }

    // Overload the delete operator
    void operator delete(void* p) {
        std::cout << "Overloading delete operator" << std::endl;
        ::operator delete(p);
    }

    // Overloaded arrow operator
    int* operator->() {
        return &value;
    }

    // Display the value
    void display() const {
        std::cout << "Value: " << value << std::endl;
    }
};

int main() {
    MyOperators a(10);
    MyOperators b(5);

    MyOperators sum = a + b;
    MyOperators diff = a - b;
    MyOperators product = a * b;
    MyOperators quotient = a / b;

    std::cout << "Sum: ";
    sum.display();

    std::cout << "Difference: ";
    diff.display();

    std::cout << "Product: ";
    product.display();

    std::cout << "Quotient: ";
    quotient.display();

    std::cout << "a == b: " << (a == b) << std::endl;
    std::cout << "a != b: " << (a != b) << std::endl;
    std::cout << "a < b: " << (a < b) << std::endl;
    std::cout << "a > b: " << (a > b) << std::endl;
    std::cout << "a <= b: " << (a <= b) << std::endl;
    std::cout << "a >= b: " << (a >= b) << std::endl;

    // Assignment operator
    MyOperators c = a;
    std::cout << "After assignment: ";
    c.display();

    // Prefix increment
    ++a;
    std::cout << "After prefix increment: ";
    a.display();

    // Postfix increment
    MyOperators d = a++;
    std::cout << "After postfix increment: ";
    d.display();

    // Example usage
    a += b; // Equivalent to a = a + b
    b *= a; // Equivalent to b = b * a

    std::cout << "a += b: " << a.value << std::endl;
    std::cout << "b *= a: " << b.value << std::endl;

    MyOperators* p = new MyOperators(42);
    delete p;

    MyOperators *obj = new MyOperators(42);
    int& ptr = obj->value; // Access the 'value' member using the arrow operator
    ptr = 100; // Modify the value through the pointer

    std::cout << "Modified value: " << obj->value << std::endl;


    return 0;
}
