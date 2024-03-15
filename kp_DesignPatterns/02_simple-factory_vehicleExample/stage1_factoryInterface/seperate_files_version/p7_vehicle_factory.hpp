#include<iostream>
#include "p2_car.hpp"
#include "p4_bike.hpp"
using namespace std;

class VehicleFactory{
    public:
    static Vehicle* getVehicle(string vehicleType); //Can also be written without static: Then getVehicle will be called after creating an object
};