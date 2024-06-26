#include <iostream>
#include <typeinfo>
using namespace std;

//Another use case of CRTP is, when it’s required to access the derived class object in the base class member functions then will have to use CRTP.


template <typename DerivedT>

class Base {
public:
	int accessDerivedData() // Parsing json object
	{
		// this will call the respective derived class object.
		auto derived = static_cast<DerivedT*>(this);

		// some generic parsing logic for any json object
		// then call derived objects to set parsed values
		derived->implementation();
		derived->display();
	}
};

class Derived1 : public Base<Derived1> // jsonMessage1
{
public:
	int data1;
	Derived1() { cout << "Derived1 constr" << endl; }
	void display()
	{
		cout << " data1:" << data1 << endl;
	}
	void implementation()
	{
		this->data1 = 8900;
	}
};

class Derived2 : public Base<Derived2> // jsonMessage2
{
public:
	int data2;
	Derived2() { cout << "Derived2 constr" << endl; }
	void display()
	{
		cout << " data2:" << data2 << endl;
	}
	void implementation()
	{
		this->data2 = 898;
	}
};

int main()
{
	auto obj1 = new Derived1;
	obj1->accessDerivedData();

	auto obj2 = new Derived2;
	obj2->accessDerivedData();
}
