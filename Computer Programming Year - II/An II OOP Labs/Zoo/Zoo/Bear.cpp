#include "Bear.h"

Bear::Bear(string name)
{
	cout << "I'm a bear my name is " << name << endl;
	Animal::_name = name;
}


Bear::~Bear()
{
}
