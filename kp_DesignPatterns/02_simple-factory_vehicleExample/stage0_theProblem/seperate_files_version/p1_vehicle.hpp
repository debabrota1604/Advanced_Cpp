#pragma once
#include<bits/stdc++.h>
using namespace std;


class Vehicle{
    public:
    virtual void createVehicle() =0; //defining as interface so that all subclasses implement this method
};