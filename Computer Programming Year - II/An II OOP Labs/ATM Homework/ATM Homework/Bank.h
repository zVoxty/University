#pragma once

#include <string>

using namespace std;

class Bank
{
public:
	Bank();
	~Bank();

	//Getters
	int getMoney();
	string getCardNumber();
	string getCardPIN();
	string getFirstName();
	string getLastName();

	//Setters
	void setMoney(int money);
	void setFirstName(string firstName);
	void setLastName(string lastName);
	void setCardNumber(string cardNumber);
	void setCardPIN(string cardPIN);

private:
	int _money;
	string _cardNumber;
	string _cardPIN;
	string _firstName;
	string _lastName;
};

