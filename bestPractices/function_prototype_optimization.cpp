#include<bits/stdc++.h>
using namespace std;


void f1(vector<int> v){
    // Copies the vector from caller function to this function
    // Any change to this vector not reflected to the caller
}

void f2(vector<int>& v){
    // No copy from caller to callee. Only reference is passed. Performance gains.
    // Change to this vector is reflected to the caller also
}

void f3(const vector<int> v){
    // v is copied but cannot change the value inside this function. Compiler can optimize the copy
}

void f4(const vector<int>& v){
    // as v is declared const and passed through reference, vector is not copied and not modifiable.
    // compiler can highly optimize this vector access.
}

void f5(vector<int> v) const { // called as const function
    // If this function is part of a class, then this function cannot modify the state of the object of this class.
    // another optimization possibility given to the compiler
    
    // can change any static members of the class as they are not part of the object state
}