#include "Core.h"
#include "PhoneBook.h"

int checkIfExist(PhoneBook phoneBook, string contactName) {
	int indexOfContact;
	bool finded = false;
	for (int i = 0; i < phoneBook.contacts.size(); i++)
	{
		if (contactName == phoneBook.contacts[i].getContactName()) {
			indexOfContact = i;
			return indexOfContact;
		}
	}

	return -1;
}

int main() {

	PhoneBook phoneBook;
	Contacts contact;

	bool ProgramOn = true;
	int option;

	while (ProgramOn) {
		Intro();
		cin >> option;
		cout << endl;
		switch (option)
		{
		case 1:
			cout << "Insert contact data : \n ";
			contact.getData(phoneBook);
			phoneBook.contacts.push_back(contact);
			break;
		case 2: {
			string contactName;
			cout << "Insert contact name : ";
			cin >> contactName;

			if (checkIfExist(phoneBook, contactName) != -1) {
				phoneBook.contacts[checkIfExist(phoneBook, contactName)].showContact();
			}
			else {
				cout << "Contact " << contactName << " doesn't exist !\n";
			}
		}
			break;
		case 3: {
			string contactName;
			cout << "\n Contacts in phoneBook : "<< phoneBook.getContactNumbers() <<"\n";
			for (int i = 0; i < phoneBook.contacts.size(); i++)
			{
				cout << phoneBook.contacts[i].getContactName();
				cout << "\n\n";
			}
		}
			break;
		case 4:
			ProgramOn = false;
			break;
		default:
			cout << "Wrong option ! ";
			break;
		}
	}

	system("PAUSE");
}