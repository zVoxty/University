#pragma once
#include "Core.h"
#include "Ierbivor.h"

class Deer : public Ierbivor
{
public:
	Deer(string name);
	~Deer();

	void getDataDeer() {
		Animal::getData();
		cout << "Insert number of deer childs : ";
		cin >> _numberOfDeerChilds;
	}
	void displayDeer() {
		Animal::display();
		cout << "Number of deer Childs is : " << _numberOfDeerChilds << endl;
	}

private:
	int _numberOfDeerChilds;
};

