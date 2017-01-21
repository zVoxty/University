#include "engine.h"
#include "Bank.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

void intro() {
	cout << "\t\t Welcome To ATM \n";
	cout << "\t\t Options : \n\n";
	cout << "\t\t1) Start Session\n";
	cout << "\t\t2) Register new account\n";
	cout << "\t\t3) Exit \n";
	cout << "\t\t4) Show Users\n\n";
	cout << "\t\t Insert your option : ";
}

void fetchDatabase(vector<Bank> users) {
	string firstName;
	string lastName;
	string cardNumber;
	string cardPIN;
	string money;
	string str;
	int usr = 0;
	ifstream dataBase("dataBase.txt");
	while (getline(dataBase, str)) {
		int i, nextElement;
		int size = str.length();
		nextElement = 0;
		for (i = nextElement; i <= size; i++) {
			if (str[i] != ' ') {
				cardNumber += str[i];
			}
			else {
				nextElement = i + 1;
				break;
			}
		}
		for (i = nextElement; i <= size; i++) {
			if (str[i] != ' ') {
				cardPIN += str[i];
			}
			else {
				nextElement = i + 1;
				break;
			}
		}
		for (i = nextElement; i <= size; i++) {
			if (str[i] != ' ') {
				firstName += str[i];
			}
			else {
				nextElement = i + 1;
				break;
			}
		}
		for (i = nextElement; i <= size; i++) {
			if (str[i] != ' ') {
				lastName += str[i];
			}
			else {
				nextElement = i + 1;
				break;
			}
		}
		for (i = nextElement; i <= size; i++) {
			if (str[i] != ' ') {
				money += str[i];
			}
			else {
				nextElement = i + 1;
				break;
			}
		}

		
		users[usr].setCardNumber(cardNumber);
		users[usr].setCardPIN(cardPIN);
		users[usr].setFirstName(firstName);
		users[usr].setLastName(lastName);

		usr++;
		cardNumber = "";
		cardPIN = "";
		firstName = "";
		lastName = "";
		money = "";
	}
}

int getSizeOfDatabase() {
	ifstream dataBase("dataBase.txt");
	string str;
	int size = 0;
	while (getline(dataBase, str)) {
		size++;
	}

	return size;
}