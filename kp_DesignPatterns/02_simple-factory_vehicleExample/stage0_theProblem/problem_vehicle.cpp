
#include<bits/stdc++.h>
using namespace std;


class Vehicle{
    public:
    virtual void createVehicle() =0; //defining as interface so that all subclasses implement this method
};


class Car: public Vehicle{
    public:
    void createVehicle();
};


void Car::createVehicle(){
    cout << "Creating Car" << endl;
}

class Bike: public Vehicle{
    public:
    void createVehicle();
};

void Bike::createVehicle(){
    cout << "Creating Bike\n";
}

int main(){
    string vType;
    cin>>vType;
    Vehicle* v;

    // based on object request, create the object
    if(vType == "car") v = new Car();
    else if(vType == "bike") v = new Bike();

    // Create the vehicle.
    v->createVehicle();

    return 0;
}