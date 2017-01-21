#include "Rabbit.h"



Rabbit::Rabbit(string name)
{
	Animal::_name = name;
	cout << "I'm a rabbit my name is " << name;
}


Rabbit::~Rabbit()
{
}
