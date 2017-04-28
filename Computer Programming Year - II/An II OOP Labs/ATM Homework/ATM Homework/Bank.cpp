#include "Bank.h"
#include <string>

using namespace std;

Bank::Bank()
{
	_money = 500;
}


Bank::~Bank()
{
}


//Getters
int Bank::getMoney() {
	return _money;
}

string Bank::getCardNumber() {
	return _cardNumber;
}

string Bank::getCardPIN() {
	return _cardPIN;
}

string Bank::getFirstName() {
	return _firstName;
}

string Bank::getLastName() {
	return _lastName;
}


//Setters
void Bank::setMoney(int money) {
	_money = money;
}

void Bank::setCardNumber(string cardNumber) {
	_cardNumber = cardNumber;
}

void Bank::setCardPIN(string cardPIN) {
	_cardPIN = cardPIN;
}

void Bank::setFirstName(string firstName) {
	_firstName = firstName;
}

void Bank::setLastName(string lastName) {
	_lastName = lastName;
}