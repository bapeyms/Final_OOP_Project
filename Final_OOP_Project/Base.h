#pragma once
#include <string>
using namespace std;

class Base
{
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
	void PrintDescription();

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

