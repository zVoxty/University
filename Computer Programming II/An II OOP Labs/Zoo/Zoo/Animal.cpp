#include "Animal.h"



Animal::Animal()
{
}


Animal::~Animal()
{
}

void Animal::getData() {
	cout << "Insert animal date : ";
	cin >> _date;
	cout << "Insert animal weight : ";
	cin >> _weight;
	cout << "Insert animal prefered food : ";
	cin >> _preferedFood;
	cout << "Insert animal food consumbtion per day : ";
	cin >> _foodPerDay;
}

void Animal::display() {
	cout << "Animal name is : " << _name << endl;
	cout << "Animal date is : " << _date << endl;
	cout << "Animal weight is : " << _weight << endl;
	cout << "Animal prefered food is : " << _preferedFood << endl;
	cout << "Animal food per day is  : " << _foodPerDay << endl;
}