#pragma once
#include<bits/stdc++.h>
using namespace std;

// The interface for different vehicles
class Vehicle{
    public:
    virtual void createVehicle() =0;
};

class Car: public Vehicle{
    public:
    void createVehicle(){cout << "Creating Car" << endl;}
};

class Bike: public Vehicle{
    public:
    void createVehicle(){cout << "Creating Bike\n";}
};


class VehicleFactory{
    public:
    static Vehicle* getVehicle(string vehicleType){
         //Can also be written without static: Then getVehicle will be called after creating an object
         
        Vehicle* vehicle;
        // based on object request, create the object
        if(vehicleType == "car") vehicle = new Car();
        else if(vehicleType == "bike") vehicle = new Bike();

        return vehicle;
    }
};


int main(){
    string vType;
    cin>>vType;

    Vehicle* vehicle = VehicleFactory::getVehicle(vType); // Create vehicle based on type
    vehicle->createVehicle();

    return 0;
}