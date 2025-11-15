#include <iostream>
#include "Base.h"
#include "Vehicle.h"
#include "Bus.h"
#include "Truck.h"
using namespace std;

enum MENU
{
	EXECUTE_MOVEMENT_CYCLE = 1,
	TERMINATE_PROGRAM = 0
};

int MenuChoice(int menuNumber)
{
	int menuChoice;
	cout << "Enter the menu number to perform a desired action" << endl;
	cout << "Number: ";
	cin >> menuChoice;
	cin.ignore(1000, '\n');
	while (menuChoice < 0 || menuChoice > menuNumber)
	{
		cout << "Enter a number from 0 to " << menuNumber << "!" << endl;
		cout << "Number: ";
		cin >> menuChoice;
		cin.ignore(1000, '\n');
	}
	cout << endl;
	return menuChoice;
}

int main()
{
    cout << "--- OOP FINAL PROJECT ---" << endl << endl;
	Base::PrintDescription();

	while (true)
	{
		cout << "-- MENU --" << endl;
		cout << "1) Execute Movement Cycle" << endl;
		cout << "0) Terminate Program" << endl << endl;

		int menuNumber = 2;
		int menuChoice = MenuChoice(menuNumber);

		switch (menuChoice) {
		case EXECUTE_MOVEMENT_CYCLE: {
			Base::ShowStatus();

			Vehicle v(10, 50);
			Bus b(20, 40, 30, 60);
			Truck t(15, 30, 20, 80);

			v.Arrive();
			b.Arrive();
			t.Arrive();
			Base::ShowStatus();

			v.Leave();
			b.Leave();
			t.Leave();
			Base::ShowStatus();
			cout << "!! CYCLE IS MADE !!" << endl << endl;
			break;
		}
		case TERMINATE_PROGRAM: {
			cout << "Program is termanating..." << endl;
			return 0;
		}
		}
	}
}