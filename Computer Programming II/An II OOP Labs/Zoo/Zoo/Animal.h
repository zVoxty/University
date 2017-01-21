#pragma once
#include "Core.h"

class Animal
{
	public:
		Animal();
		~Animal();

		void getData();
		void display();

		string _name;
		string _animalType;

	private:
		//nume, data aducerii,
		//	greutate, hrana preferata, cantitate pe zi
		string _date;
		int _weight;
		string _preferedFood;
		int _foodPerDay;

};

