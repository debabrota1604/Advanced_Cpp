
#include<iostream>
#include "p7_vehicle_factory.hpp" //Only include the factory header
using namespace std;

int main(){
    string vType;
    cin>>vType;

    Vehicle* vehicle = VehicleFactory::getVehicle(vType); // Create vehicle based on type
    vehicle->createVehicle();

    return 0;
}