#include <iostream> 
using namespace std; 
int main_fun1() 
{ 
   int x = -1; 
   try { 
      cout << "Inside try \n"; 
      if (x < 0) 
      { 
         throw x; 
         cout << "After throw \n"; 
      } 
   } 
   catch (int x ) { 
      cout << "Exception Caught \n"; 
   } 
  
   cout << "After catch \n"; 
   return 0; 
} 

/*
    Inside try
    Exception Caught
    After catch
    
Logic: 
    When an exception is thrown, lines of try block after the throw statement are not executed.
    When exception is caught, the code after catch block is executed. Catch blocks are generally written at the end through.
*/


class Base {}; 
class Derived: public Base {}; 
int main_fun2() 
{ 
    Derived d; 
    try { 
        throw d; 
    } 
    catch(Base b) { 
            cout<<"Caught Base Exception"; 
    } 
    catch(Derived d) { 
            cout<<"Caught Derived Exception"; 
    } 
    return 0; 
} 
/*
Output of following program:  Caught Base Exception
    If both base and derived classes are caught as exceptions then catch block of derived class must appear before the base class. If we put base class first then the derived class catch block will never be reached.

    In Java, catching a base class exception before derived is not allowed by the compiler itself. In C++, compiler might give warning about it, but compiles the code.
*/

int main_fun3() 
{ 
	try
	{ 
	throw 'a'; 
	} 
	catch (int param) 
	{ 
		cout << "int exception\n"; 
	} 
	catch (...) 
	{ 
		cout << "default exception\n"; 
	} 
	cout << "After Exception"; 
	return 0; 
} 
/*
Output:
    default exception
    After Exception

    Explanation:
    The block catch(…) is used for catch all, when a data type of a thrown exception doesn’t match with any other catch block, the code inside catch(…) is executed.

    Note that the implicit type conversion doesn’t happen when exceptions are caught. The character ‘a’ is not automatically converted to int.
*/

int main_fun4() 
{ 
    try
    { 
       throw 10; 
    } 
    catch (...) 
    { 
        cout << "default exception\n"; 
    } 
    catch (int param) 
    { 
        cout << "int exception\n"; 
    } 
  
    return 0; 
} 

/*
Output: Compiler Error

Explanation:
It is compiler error to put catch all block before any other catch. The catch(…) must be the last catch block.

*/

int main_fun5() 
{ 
    try
    { 
        try
        { 
            throw 20; 
        } 
        catch (int n) 
        { 
            cout << "Inner Catch\n"; 
            throw; 
        } 
    } 
    catch (int x) 
    { 
        cout << "Outer Catch\n"; 
    } 
    return 0; 
} 
/*
Output:
Inner Catch
Outer Catch

Explanation:
 The statement ‘throw;’ is used to re-throw an exception. This is useful when a function can handles some part of the exception handling and then delegates the remaining part to the caller. A catch block cleans up resources of its function, and then rethrows the exception for handling elsewhere.
*/

class Test { 
public: 
   Test() { cout << "Constructing an object of Test " << endl; } 
  ~Test() { cout << "Destructing an object of Test "  << endl; } 
}; 
  
int main() { 
  try { 
    Test t1; 
    throw 10; 
  } catch(int i) { 
    cout << "Caught " << i << endl; 
  } 
} 

/*
Output:
Constructing an object of Test 
Destructing an object of Test 
Caught 10

Explanation:
When an object is created inside a try block, destructor for the object is called before control is transferred to catch block.
*/

class Test { 
  static int count; 
  int id; 
public: 
  Test() { 
    count++; 
    id = count; 
    cout << "Constructing object number " << id << endl; 
    if(id == 4) 
       throw 4; 
  } 
  ~Test() { cout << "Destructing object number " << id << endl; } 
}; 
  
int Test::count = 0; 
  
int main() { 
  try { 
    Test array[5]; 
  } catch(int i) { 
    cout << "Caught " << i << endl; 
  } 
} 

/*
Constructing object number 1
Constructing object number 2
Constructing object number 3
Constructing object number 4
Destructing object number 3
Destructing object number 2
Destructing object number 1
Caught 4
*/

int fun() throw (int) 
{ 
    throw 10; 
} 
  
int main() { 
  
  fun(); 
  
  return 0; 
} 
/*
Output: Abnormal Program termination
When an exception is thrown and not caught, the program terminates abnormally.
*/


int fun() 
{ 
    throw 10; 
} 
  
int main() 
{ 
    try
    { 
        fun(); 
    } 
    catch (int ) 
    { 
        cout << "Caught"; 
    } 
    return 0; 
} 
/*
Output: No compiler Error. Output is “Caught”
C++ compiler doesn’t check enforce a function to list the exceptions that it can throw. In Java, it is enforced.

It is up to the programmer to specify. Being a civilized programmer, a programmer should specify the list.
*/



/*
What is the advantage of exception handling ?
    Remove error-handling code from the software’s main line of code.
    A method writer can choose to handle certain exceptions and delegate others to the caller.
    An exception that occurs in a function can be handled anywhere in the function call stack.
    Separating Error-Handling Code from “Regular” Code.
    Propagating Errors Up the Call Stack.

What should be put in a try block?
    The statements which may cause problems are put in try block. Also, the statements which should not be executed after a problem occurred, are put in try block. Note that once an exception is caught, the control goes to the next line after the catch block.

Which of the following is true about exception handling in C++?
    1) There is a standard exception class like Exception class in Java.
    2) All exceptions are unchecked in C++, i.e., compiler doesn’t check if the exceptions are caught or not.
    3) In C++, a function can specify the list of exceptions that it can throw using comma separated list like following.
    void fun(int a, char b) throw (Exception1, Exception2, ..) 

    Answer: All 3
    https://www.geeksforgeeks.org/c-plus-plus-gq/exception-handling-gq/

*/