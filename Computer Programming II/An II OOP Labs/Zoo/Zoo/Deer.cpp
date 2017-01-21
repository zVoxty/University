#include "Deer.h"

Deer::Deer(string name) {
	cout << "I'm a deer and my name is " << name << endl;
	Animal::_name = name;
}


Deer::~Deer()
{
}
