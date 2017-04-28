#pragma warning(disable:4996)
#include <iostream>
#include "Bank.h"
#include "engine.h"
#include <windows.h>
#include <string>
#include <stdio.h>
#include <fstream>
#include <vector>

using namespace std;

int main() {
	
	bool atmOpen = true;
	string firstName;
	string lastName;
	string cardNumber;
	string cardPIN;
	string money;
	Bank newAccount;
	

	while (atmOpen == true) {

		//Check this out
		vector<Bank> users;
		users.resize(getSizeOfDatabase());
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
			int moneyInt = atoi(money.c_str());
			users[usr].setMoney(moneyInt);

			usr++;
			cardNumber = "";
			cardPIN = "";
			firstName = "";
			lastName = "";
			money = "";
		}

		intro();
		int option;
		cin >> option;
		switch (option)
		{
			case 1:{
				char ch;
				FILE *f = fopen("dataBase.txt", "r");

				if (fscanf(f, "%c", &ch) == EOF)
				{
					cout << "\n\t\t Cannot start session dataBase empty!\n\n";
					break;
				}
				fclose(f);
				bool sessionCardNumber = true;
				bool sessionCardPin = true;
				bool mainSession = true;
				while (sessionCardNumber) {
					cout << "\n\t\t\t Session Started\n";
					cout << "\t\t Insert your cardNumber: \n";
					string cNumber;
					cin >> cNumber;
					for (int i = 0; i < users.size(); i++) {
						if (users[i].getCardNumber() == cNumber) {
							while (sessionCardPin) {
								cout << "\t\t Insert your cardPIN: \n";
								string cPIN;
								cin >> cPIN;
								if (users[i].getCardPIN() == cPIN) {
									while (mainSession) {
										system("cls");
										int sessionOption;
										cout << "\n\n\t\t Hello " << users[i].getFirstName() << " !\n";
										cout << "\t\t Your Ballance : " << users[i].getMoney() << " $ \n\n";

										cout << "\t\t Options : \n";
										cout << "\t\t 1) Withdraw money. \n";
										cout << "\t\t 2) Send money. \n";
										cout << "\t\t 3) Exit to menu. \n";
										cout << "\t\t Your option : ";
										cin >> sessionOption;
										switch (sessionOption)
										{
											case 1: {
												cout << "\t\tInsert withdraw sum : ";
												int withdrawSum;
												cin >> withdrawSum;
												
												int lastBallance = users[i].getMoney();
												int newBallance;
												newBallance = lastBallance - withdrawSum;
												users[i].setMoney(newBallance);
												cout << "\t\t You withdraw " << withdrawSum << " now your ballance is " << newBallance;
												FILE *dataBase = fopen("dataBase.txt", "w");
													for (int j = 0; j < users.size(); j++) {
														fprintf(dataBase, "%s %s %s %s %d\n", users[j].getCardNumber().c_str(), users[j].getCardPIN().c_str(), users[j].getFirstName().c_str(), users[j].getLastName().c_str(), users[j].getMoney());
													}
												fclose(dataBase);
												Sleep(3000);

											}
												break;
											case 2: {
												cout << "\t\tInsert your friend first name : ";
												string friendFirstName;
												cin >> friendFirstName;

												cout << "\t\tInsert the sum of money to send : ";
												int sendMoney;
												cin >> sendMoney;

												for (int j = 0; j < users.size(); j++) {
													if (users[j].getFirstName() == friendFirstName) {
														int lastBallanceY = users[i].getMoney();
														int newBallanceY = lastBallanceY - sendMoney;
														users[i].setMoney(newBallanceY);

														int lastBallanceH = users[j].getMoney();
														int newBallanceH = lastBallanceH + sendMoney;
														users[j].setMoney(newBallanceH);

														cout << "You send to " << users[j].getFirstName() << " " << sendMoney << " $!";
														Sleep(3000);
														FILE *dataBase = fopen("dataBase.txt", "w");
														for (int k = 0; k < users.size(); k++) {
															fprintf(dataBase, "%s %s %s %s %d\n", users[k].getCardNumber().c_str(), users[k].getCardPIN().c_str(), users[k].getFirstName().c_str(), users[k].getLastName().c_str(), users[k].getMoney());
														}
														fclose(dataBase);
													}
												}

											}
												break;
											case 3:
												mainSession = false;
												sessionCardNumber = false;
												sessionCardPin = false;
												break;
											default:
												cout << "\t\t Wrong option !\n";
												break;
										}
									}
								}
								else {
									cout << "\t\t Invalid Pin ! \n";
								}
							}
						}
					}
					cout << "\t\t Can't found your number in database \n ";
				}
			}
				break;
			case 2:{
				FILE *dataBase = fopen("dataBase.txt", "a");
				cout << "\n\t\t Welcome To Registration Mode\n";
				cout << "\t\t Enter your first name: ";
				cin >> firstName;
				newAccount.setFirstName(firstName);

				cout << "\t\t Enter your last name: ";
				cin >> lastName;
				newAccount.setLastName(lastName);

				cout << "\t\t Enter your cardNumber: ";
				cin >> cardNumber;
				newAccount.setCardNumber(cardNumber);

				cout << "\t\t Enter your cardPIN: ";
				cin >> cardPIN;
				newAccount.setCardPIN(cardPIN);

				cout << "\t\t Registered Succesfull !\n\n";
				fprintf(dataBase, "%s %s %s %s %d\n", newAccount.getCardNumber().c_str(), newAccount.getCardPIN().c_str(), firstName.c_str(), lastName.c_str(), newAccount.getMoney());
				Sleep(1000);
				fclose(dataBase);	
			}
			break;
			case 3:
				atmOpen = false;
				break;

			case 4:
				for (int i = 0; i < users.size(); i++) {
					cout << users[i].getCardNumber() << " " << users[i].getCardPIN() << " " << users[i].getFirstName() << " " << users[i].getLastName() << " " << users[i].getMoney() << endl;
 				}
				break;

			default:
				cout << "Wrong option !";
				Sleep(2000);
				break;
		}
	}
}