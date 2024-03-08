
#include<bits/stdc++.h>
#include "p2_car.hpp"
#include "p4_bike.hpp"
using namespace std;

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

/*
Problems in this design:

1. Violation of OCP: To add a new vehicle, we need to change in the client code, both in include clause and in object creation logic
2. Tight Coupling: Client code is very tightly coupled with the library. Every time client has to change the library and modify own code to get the changes reflected.
*/