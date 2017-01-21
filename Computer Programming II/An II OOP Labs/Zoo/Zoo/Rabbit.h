#pragma once
#include "Core.h"
#include "Ierbivor.h"

class Rabbit : public Animal
{
public:
	Rabbit(string name);
	~Rabbit();

	void getDataRabbit() {
		Animal::getData();
		cout << "Insert minum surface of rabbit: ";
		cin >> _minimSurface;
	}
	void displayDeer() {
		Animal::display();
		cout << "Number of deer Childs is : " << _minimSurface << endl;
	}
private:
	int _minimSurface;
};

