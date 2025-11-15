#pragma once
#include <string>
#include <iostream>
using namespace std;

class Base
{
public:
	static string location_of_base;
	static string defense_of_base;

	static int people_on_base;
	static int vehicle_on_base;
	static double petrol_on_base;
	static double goods_on_base;
public:
	static string GetLocationOfBase()
	{
		return location_of_base;
	}
	static string GetDefenseOfBase()
	{
		return defense_of_base;
	}
	static void PrintDescription()
	{
		cout << "- AMERICAN MILITARY BASE DESCRIPTION -" << endl;
		cout << "Location: " << GetLocationOfBase() << endl;
		cout << "Defense: " << GetDefenseOfBase() << endl;
		cout << endl;
	}
	void static ShowStatus();

	static int GetPeopleOnBase()
	{
		return people_on_base;
	}
	static int GetVehicleOnBase()
	{
		return vehicle_on_base;
	}
	static double GetPetrolOnBase()
	{
		return petrol_on_base;
	}
	static double GetGoodsOnBase()
	{
		return goods_on_base;
	}
};

