#pragma once
#include "Vehicle.h"
#include "Base.h"
#include <iostream>
#include <algorithm>
using namespace std;

class Truck :public Vehicle
{
    double load;
    double max_load;

public:
    Truck(double current_load, double max_load_value, double petrol_amount, double tank_vol)
        : Vehicle(petrol_amount, tank_vol), load(current_load), max_load(max_load_value) {}

    double getCurrentLoad() const 
    { 
        return load; 
    }
    double getMaxLoad() const 
    { 
        return max_load; 
    }

    void Arrive() 
    {
        Base::people_on_base += 1;
        Base::vehicle_on_base += 1;
        Base::goods_on_base += load;
        load = 0;
        cout << "Truck has arrived at the base" << endl;
    }

    bool Leave() {
        double needed_petrol = tank_volume - petrol;
        if (Base::petrol_on_base >= needed_petrol && Base::people_on_base > 0) 
        {
            petrol = tank_volume;
            Base::petrol_on_base -= needed_petrol;
            Base::people_on_base -= 1;
            Base::vehicle_on_base -= 1;

            double taking_load = min(max_load, Base::goods_on_base);
            load = taking_load;
            Base::goods_on_base -= taking_load;

            cout << "Truck is leaving base with " << load << " tones of goods" << endl;
            return true;
        }
        else 
        {
            cout << "Truck cannot leave the base" << endl;
            return false;
        }
    }
};

