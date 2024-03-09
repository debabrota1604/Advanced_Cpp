#include <iostream>

/*
const_cast is a type of C++ casting operator used to add or remove the const qualifier from a pointer or reference. It is often used when you have a pointer or reference to a const object and need to perform operations that modify the object. Keep in mind that using const_cast to remove the const qualifier and modify a truly const object results in undefined behavior.
*/

void const_cast_example() {
    const int x = 5;

    // Using const_cast to remove const qualifier
    int* nonConstPtr = const_cast<int*>(&x);

    // Modifying the value through the non-const pointer
    *nonConstPtr = 10;

    // Note: Modifying a const object is undefined behavior!
    // The above line results in undefined behavior.

    // Printing the modified value
    std::cout << "Modified value: " << x << std::endl;

}
/*
In this example, we have a const integer x, and we use const_cast to create a non-const pointer nonConstPtr. Then, we attempt to modify the value pointed to by nonConstPtr. However, keep in mind that modifying a const object in this way results in undefined behavior.

It's important to use const_cast judiciously and be aware of the implications, as improper usage can lead to unexpected and undefined behavior in your program.
*/



/*
reinterpret_cast is a type of casting operator in C++ that is used for low-level casting between pointer types and integral types. It can perform conversions that would be considered unsafe or implementation-dependent by other casting operators.

Here's an example illustrating the use of reinterpret_cast:
*/
void reinterpret_cast_example() {
    // Example 1: Casting between pointer types
    int x = 10;
    int* ptr = &x;

    // Using reinterpret_cast to cast from int* to void*
    void* voidPtr = reinterpret_cast<void*>(ptr);

    // Using reinterpret_cast to cast back from void* to int*
    int* originalPtr = reinterpret_cast<int*>(voidPtr);

    // Example 2: Casting between pointer and integral types
    long longValue = 123456789012345;

    // Using reinterpret_cast to cast from long to int*
    int* intPtr = reinterpret_cast<int*>(&longValue);

    // Using reinterpret_cast to cast back from int* to long
    long originalLongValue = reinterpret_cast<long>(intPtr);

    // Printing results
    std::cout << "Original value: " << *originalPtr << std::endl;
    std::cout << "Original long value: " << originalLongValue << std::endl;

}

/*
In this Example, reinterpret_cast is used to convert between a pointer to int and a pointer to void and back. In Example 2, it is used to reinterpret a long value as a pointer to int and back. These examples demonstrate how reinterpret_cast can be used for low-level casting but should be used with caution, as it can lead to undefined behavior if misused. Always make sure that the conversion makes sense in the context of your program and that you understand the potential risks involved.
*/


int main(){
    const_cast_example();
    reinterpret_cast_example();

    return 0;
}

