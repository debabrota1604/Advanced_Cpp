#include<iostream>
using namespace std;
//memset, memmove, and memcpy in C++:

/*  memset:
    The memset function is used to set a block of memory to a specific value.
    It takes three arguments:
    A pointer to the memory block (usually an array or buffer).
    The value to set (usually an integer or character).
    The number of bytes to set.
    Example usage:
*/
char buffer[100];
memset(buffer, 0, sizeof(buffer));  // Set all bytes in buffer to 0
// Note: memset works with raw memory and does not perform any type checking or conversions. It is commonly used for initializing arrays or buffers.

/*  memmove:
    The memmove function is used to copy a block of memory from one location to another.
    Unlike memcpy, memmove handles overlapping memory regions correctly.
    It takes three arguments:
    A pointer to the destination memory.
    A pointer to the source memory.
    The number of bytes to copy.
    Example usage:
*/
char source[100];
char destination[100];
memmove(destination, source, sizeof(source));  // Safely copy data from source to destination
//memmove ensures that data is correctly copied even if the source and destination regions overlap.

/*  memcpy:
    The memcpy function is used to copy a block of memory from one location to another.
    It does not handle overlapping memory regions, so it should be used carefully.
    It takes three arguments:
    A pointer to the destination memory.
    A pointer to the source memory.
    The number of bytes to copy.
    Example usage:
*/
char source[100];
char destination[100];
memcpy(destination, source, sizeof(source));  // Copy data from source to destination (no overlap handling)
// Use memcpy when you are sure that the memory regions do not overlap.