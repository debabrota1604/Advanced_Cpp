#include<bits/stdc++.h>
using namespace std;


int main(){
    int x=0, num, pos, bit;
    // Basics

    // Set a particular bit:
    x = x | (1 << 3);
    cout << "Setting bit 3:" << x << endl;

    // Reset a particular bit:
    x = x & ~(1<<3);
    cout << "Resetting bit 3:" << x << endl;

    // Toogle a particular bit:
    x = x ^ (1<<3);
    cout << "Toogling bit 3:" << x << endl;
    x = x ^ (1<<3);
    cout << "Toogling bit 3 again:" << x << endl;

    // check bit at k-th position
    pos = x & (1 << 3);
    cout << "bit at position 3:" << pos << endl;

    //remove the lowest set bit
    x = 15;
    x = x & (x-1);
    cout << "after removing last bit from 15: " << x << endl;

    // Get the lowest set bit
    /*
    This is done by using the expression ‘X &(-X)’Let us see this by taking an example: Let X = 00101100. So ~X(1’s complement) will be ‘11010011’ and 2’s complement will be (~X+1 or -X) i.e.  ‘11010100’.So if we ‘AND’ original number ‘X’ with its two’s complement which is ‘-X’, we get the lowest set bit. 
    */
    bit = x & -x;
    cout << "lowest set bit in " << x << ": " << bit << endl; 

    // Multiply or divide by 2:
    num = x << 1;
    cout << "Double of " << x << ": " << num << endl;
    num = x >> 1;
    cout << "Half of " << x << ": " << num << endl;

    //count set bits in a number:
    /*
     if we subtract a number by 1 and do it bitwise & with itself (n & (n-1)), we unset the rightmost set bit. If we do n & (n-1) in a loop and count the number of times the loop executes, we get the set bit count. 
    */
    unsigned int count = 0, n=x;
    while (n) {
        n &= (n - 1);
        count++;
    }
    cout << "Set bits in " << x << ": " << count << endl;
    
    //Toogle a range of bits in range (l to r)
    x = 245;


    return 0;
}