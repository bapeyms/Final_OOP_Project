#pragma once
#include "Base.h"
#include <string>
#include <iostream>
using namespace std;

class Vehicle
{
protected:
	double petrol;
	double tank_volume;
public:
    Vehicle(double petrol_amount, double tank_volume): petrol(petrol_amount), tank_volume(tank_volume) {}
    virtual ~Vehicle() {}

    double getTankVolume() const 
    { 
        return tank_volume; 
    }
    double getPetrolAmount() const 
    { 
        return petrol; 
    }

    virtual void Arrive()
    {
        Base::people_on_base += 1;
        Base::vehicle_on_base += 1;
        cout << "Vehicle has arrived at the base" << endl;
    }
    virtual bool Leave() 
    {
        double needed_petrol = tank_volume - petrol;
        if (Base::petrol_on_base >= needed_petrol && Base::people_on_base > 0) 
        {
            petrol = tank_volume;
            Base::petrol_on_base -= needed_petrol;
            Base::people_on_base -= 1;
            Base::vehicle_on_base -= 1;
            cout << "Vehicle has left the base" << endl;
            return true;
        }
        else 
        {
            cout << "Vehicle cannot leave the base" << endl;
            return false;
        }
    }
};

