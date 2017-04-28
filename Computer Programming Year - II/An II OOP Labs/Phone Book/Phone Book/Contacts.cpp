#include "Contacts.h"

Contacts::Contacts()
{
}


Contacts::~Contacts()
{
}

void Contacts::showContact() {
	cout << "Contact name is " << _contactName << " .\n";
	cout << "Address of " << _contactName << " is " << _contactAddress << " .\n";
	cout << toupper(_contactName[0]) << " number is " << _phoneNumber << " .\n";
}

void Contacts::getData(PhoneBook phoneBook) {
	cout << "Contact name : ";
	cin >> _contactName;
	cout << "Contact address : ";
	cin >> _contactAddress;
	cout << "Contact number : ";
	cin >> _phoneNumber;
	phoneBook._numberOfContacts++; // Acces to number of contacts using friend

	cout << "\nContact succesfully submited !\n\n";
}
