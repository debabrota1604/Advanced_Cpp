
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
