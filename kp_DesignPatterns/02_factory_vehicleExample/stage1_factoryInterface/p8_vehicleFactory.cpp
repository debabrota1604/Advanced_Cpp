#include "p7_vehicle_factory.hpp"
using namespace std;


Vehicle* VehicleFactory::getVehicle(string vType){
    Vehicle* vehicle;
    // based on object request, create the object
    if(vType == "car") vehicle = new Car();
    else if(vType == "bike") vehicle = new Bike();

    return vehicle;
}