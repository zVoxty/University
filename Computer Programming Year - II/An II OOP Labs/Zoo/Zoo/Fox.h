#pragma once
#include "Core.h"
#include "Carnivor.h"

class Fox : public Animal
{
public:
	Fox(string name);
	~Fox();

	void getDataFox() {
		Animal::getData();
		cout << "Insert fox type : ";
		cin >> _foxType;
		cout << "Insert max temperature : ";
		cin >> _maxTemperature;
	}
	void displayFox() {
		Animal::display();
		cout << "Fox type is : " << _foxType << endl;
		cout << "Fox max temperature is : " << _maxTemperature << endl;
	}

private:

	string _foxType;
	int _maxTemperature;
};

