#include "Lion.h"



Lion::Lion(string name)
{
	cout << "I'm a lion my name is " << name << endl;
	Animal::_name = name;
}


Lion::~Lion()
{
}
