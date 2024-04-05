#include<iostream> 
using namespace std; 

/*
Which of the following is true about virtual functions in C++.
    (A) Virtual functions are functions that can be overridden in derived class with the same signature.
    (B) Virtual functions enable run-time polymorphism in a inheritance hierarchy.
    (C) If a function is ‘virtual’ in the base class, the most-derived class’s implementation of the function is called according to the actual type of the object referred to, regardless of the declared type of the pointer or reference.
    In non-virtual functions, the functions are called according to the type of reference or pointer.
    (D) All of the above
Ans: D

Which of the following is true about pure virtual functions?
    1) Their implementation is not provided in a class where they are declared.
    2) If a class has a pure virtual function, then the class becomes abstract class and an instance of this class cannot be created.
Ans:  Only 2
*/

class Base 
{ 
public: 
    virtual void show() { cout<<" In Base \n"; } 
}; 
  
class Derived: public Base 
{ 
public: 
    void show() { cout<<"In Derived \n"; } 
}; 
  
int main1(void) 
{ 
    Base *bp = new Derived; 
    bp->show(); 
  
    Base &br = *bp; 
    br.show(); 
  
    return 0; 
} 

/*
Output: 
In Derived
In Derived

Since show() is virtual in base class, it is called according to the type of object being referred or pointed, rather than the type of pointer or reference.

*/

class Base2
{ 
public: 
    virtual void show() { cout<<" In Base \n"; } 
}; 
  
class Derived2: public Base2
{ 
public: 
    void show() { cout<<"In Derived \n"; } 
}; 
  
int main2(void) 
{ 
    Base2 *bp, b; 
    Derived2 d; 
    bp = &d; 
    bp->show(); 
    bp = &b; 
    bp->show(); 
    return 0; 
} 
/*
Output:
In Derived
In Base

Initially base pointer points to a derived class object. Later it points to base class object,
*/


class Base3
{ 
public: 
    virtual void show() = 0; 
}; 
  
int main3(void) 
{ 
    Base3 b; 
    Base3 *bp; 
    return 0; 
} 
/*
Output: 
There is compiler error in line “Base b;”

Explanation: 
    Since Base has a pure virtual function, it becomes an abstract class and an instance of it cannot be created.
    So there is an error in line “Base b”.
    Note that there is no error in line “Base *bp;”. We can have pointers or references of abstract classes.
*/

class Base4
{ 
public: 
    virtual void show() = 0; 
}; 
  
class Derived4 : public Base4 { }; 
  
int main4(void) 
{ 
    Derived q; 
    return 0; 
} 
/*
Output: Compiler Error: Derived is abstract
If we don’t override the pure virtual function in derived class, then derived class also becomes abstract class.
*/

class Base5
{ 
public: 
    virtual void show() = 0; 
}; 
  
class Derived5: public Base5
{ 
public: 
    void show() { cout<<"In Derived \n"; } 
}; 
  
int main5(void) 
{ 
    Derived5 d; 
    Base5 &br = d; 
    br.show(); 
    return 0; 
}
/*
Output:  In Derived

Explanation: https://www.geeksforgeeks.org/c-plus-plus-gq/virtual-functions-gq/
*/

class Base6 { 
public: 
  virtual ~Base() {}    
}; 
int main6() { 
   return 0; 
} 
/*
Output: Program will compile and run

Explanation: A destructor can be virtual. We may want to call appropriate destructor when a base class pointer points to a derived class object and we delete the object. If destructor is not virtual, then only the base class destructor may be called. For example, consider the following program.
*/