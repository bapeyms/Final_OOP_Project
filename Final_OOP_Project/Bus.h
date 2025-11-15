#pragma once
#include "Base.h"
#include "Vehicle.h"
#include <iostream>
#include <algorithm>
using namespace std;

class Bus :public Vehicle
{
	int people;
	int max_people;
public:
    Bus(int people_count, int max_people_count, double petrol_amount, double tank_vol)
        : Vehicle(petrol_amount, tank_vol), people(people_count), max_people(max_people_count) {}

    int GetPeopleCount() const 
    { 
        return people; 
    }
    int GetMaxPeople() const 
    { 
        return max_people; 
    }

    void Arrive()
    {
        Base::people_on_base += 1 + people;
        Base::vehicle_on_base += 1;
        people = 0;
        cout << "Bus has arrived at the base" << endl;
    }

    bool Leave() 
    {
        double needed_petrol = tank_volume - petrol;
        if (Base::petrol_on_base >= needed_petrol && Base::people_on_base > 0) 
        {
            petrol = tank_volume;
            Base::petrol_on_base -= needed_petrol;
            Base::people_on_base -= 1;
            Base::vehicle_on_base -= 1;
            int taking_people = min(max_people, Base::people_on_base);
            people = taking_people;
            Base::people_on_base -= taking_people;

            cout << "Bus is leaving base with " << people << " passengers" << endl;
            return true;
        }
        else 
        {
            cout << "Bus cannot leave the base" << endl;
            return false;
        }
    }
};

