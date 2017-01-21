#pragma once
#include "Core.h"
#include "PhoneBook.h"

using namespace std;

class PhoneBook;

class Contacts
{
public:
	Contacts();
	~Contacts();

	void showContact();
	void getData(PhoneBook phoneBook);

	string getContactName() {
		return _contactName;
	}

private:
	string _contactName;
	string _contactAddress;
	string _phoneNumber;
};

