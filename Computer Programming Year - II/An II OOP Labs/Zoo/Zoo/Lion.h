#pragma once
#include "Core.h"
#include "Carnivor.h"

class Lion : public Animal
{
public:
	Lion(string name);
	~Lion();

	void getDataLion() {
		Animal::getData();
		cout << "Insert lion provenience country : ";
		cin >> _provenienceCountry;
		cout << "Insert lion supported temperature : ";
		cin >> _supportedTemp;
	}
	void displayLionDeer() {
		Animal::display();
		cout << "Lion provenience country is: " << _provenienceCountry << endl;
		cout << "Lion supported temperature is: " << _supportedTemp << endl;
	}

private:
	string _provenienceCountry;
	int _supportedTemp;
};

