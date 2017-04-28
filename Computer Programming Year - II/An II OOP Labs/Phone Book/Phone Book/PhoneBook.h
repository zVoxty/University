#pragma once
#include "Core.h"
#include "Contacts.h"

class PhoneBook
{
public:
	PhoneBook();
	~PhoneBook();

	friend class Contacts;
	vector<Contacts> contacts;

	int getContactNumbers() {
		return _numberOfContacts;
	}

	void setContactNumbers(int numbersOfContacts) {
		_numberOfContacts = numbersOfContacts;
	}

private:
	int _numberOfContacts;
};

