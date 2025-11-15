#include "Base.h"
#include <iostream>
#include <string>
using namespace std;

string Base::location_of_base = "in the middle of the desert";
string Base::defense_of_base = "a five-meter-high fence";

int Base::people_on_base = 100;
int Base::vehicle_on_base = 25;
double Base::petrol_on_base = 20000.0;
double Base::goods_on_base = 500.0;


void Base::ShowStatus()
{
	cout << "On base:" << endl;
	cout << "- number of people: " << people_on_base << endl;
	cout << "- number of people: " << vehicle_on_base << endl;
	cout << "- amount of petrol: " << petrol_on_base << endl;
	cout << "- amount of goods: " << goods_on_base  << endl;
	cout << endl;
}
