#pragma once
#include "Core.h"
#include "Ierbivor.h"
#include "Carnivor.h"

class Bear : public Ierbivor, Carnivor
{
public:
	Bear(string name);
	~Bear();

	void getDataBear() {
		Animal::getData();
		cout << "Insert bear hibernation date : ";
		cin >> _hibernationDate;
	}
	void displayBear() {
		Animal::display();
		cout << "Bear hibernation date is : " << _hibernationDate << endl;
	}

private:
	string _hibernationDate;
};

