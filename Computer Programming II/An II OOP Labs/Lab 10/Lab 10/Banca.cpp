#include "Banca.h"



Banca::Banca()
{
	plafonBanca = 5000;
}


Banca::~Banca()
{
}

void Banca::InregistrareClient() {
	Client newClient;
	newClient.Register();
	users.push_back(newClient);
}

void Banca::Revizie() {
	std::cout << "Useri inregistrati : " << users.size() << std::endl;

	for (auto it : users) {
		std::cout << it.userName << " - " << it.bani << std::endl;
	}
}

bool Banca::FindPIN(int userindex, std::string PIN) {
	
	if (users[userindex].PIN != PIN)
		return false;

	return true;
}

int Banca::FindUsername(std::string username) {

	for (size_t i = 0; i < users.size(); i++) {
		if (users[i].userName != username)
			continue;
		else
			return i;
	}
	return INT_MAX;
}

bool Banca::Withdraw(int userindex) {
	std::cout << "Suma de retras : ";
	int numerar;
	std::cin >> numerar;

	try {
		if (numerar > 5000)
			throw("Numerar mai mare decat plafon !");

		if (numerar < 0)
			throw("Nu poti retrage numere negative !");

		if(numerar >= users[userindex].bani)
			throw("Nu aveti atat de multi bani in cont !");

		users[userindex].bani -= numerar;
		std::cout << "Au fost retrasi " << numerar << " in contul " << users[userindex].userName << " au mai ramas " << users[userindex].bani << " ! \n";
		return true;
			
	}
	catch (const char * msg) {
		MessageBoxA(NULL, msg, "Error", MB_OK | MB_ICONEXCLAMATION);
		return false;
	}
}

bool Banca::TransferBani(int baseIndexUser) {
	std::cout << "\n\n\t\tTransfer Bani\n";
	std::cout << "Unde transfer : ";
	std::string username;
	std::cin >> username;
	try {
		int userIndex = INT_MAX;
		if (FindUsername(username) == INT_MAX) {
			throw("Userul nu exista !");
		}
		else {
			userIndex = FindUsername(username);
		}

		std::cout << "Suma de transfer : ";
		int numerar;
		std::cin >> numerar;

		if (numerar > 5000)
			throw("Numerar mai mare decat plafon !");

		if (numerar < 0)
			throw("Nu poti retrage numere negative !");

		if (numerar >= users[baseIndexUser].bani)
			throw("Nu aveti atat de multi bani in cont !");

		users[baseIndexUser].bani -= numerar;
		users[userIndex].bani += numerar;
		return true;

	}
	catch (const char * msg) {
		MessageBoxA(NULL, msg, "Error", MB_OK | MB_ICONEXCLAMATION);
		return false;
	}
}

bool Banca::DepunereNumerar(int userindex){
	std::cout << "\n\n\t\tDepunere numerar\n";
	std::cout << "Cat doriti sa depuneti : ";
	int numerar;
	std::cin >> numerar;

	try {
		int randomNumber = rand() % 100 + 1;
		if (randomNumber < 10) {
			throw("O bacnota nu a fost recunoscuta in timpul depunerii !");
		}

		users[userindex].bani += numerar;
		return true;
	}
	catch (const char * msg) {
		MessageBoxA(NULL, msg, "Error", MB_OK | MB_ICONEXCLAMATION);
		return false;
	}
}

bool Banca::Lobby() {
	system("CLS");
	std::cout << "\n\n\t\tLobby\n";

	std::cout << "Username : ";
	std::string username;
	std::cin >> username;

	try {
		int userIndex = INT_MAX;
		if (FindUsername(username) == INT_MAX) {
			throw("Userul nu exista !");		
		}
		else {
			userIndex = FindUsername(username);
		}

		std::cout << "Introduce PINUL : ";
		std::string PIN;
		std::cin >> PIN;
		
		if (!FindPIN(userIndex, PIN)) {
			
			if (users[userIndex].PinGresit > 0) {
				users[userIndex].PinGresit--;
				std::cout << "Pin gresit incercari ramase " << users[userIndex].PinGresit;
			}
			else {
				throw("Cont blocat !");
				return false;
			}
			Sleep(2000);
			Lobby();
		}
		std::cout << "\n\t1) Withdraw\n";
		std::cout << "\t2) Transfer \n";
		std::cout << "\t3) Depunere numerar \n";
		std::cout << "Your Option : ";
		int option;
		std::cin >> option;
		switch (option)
		{
		case 1:
			if (!Withdraw(userIndex)) {
				throw("Eroare la retragere numerar ! ");
			}
			break;
		case 2:
			if (!TransferBani(userIndex)) {
				throw("Eroare la transferare bani ! ");
			}
			break;
		case 3:
			if (!DepunereNumerar(userIndex)) {
				throw("Eroare depunere numerar ! ");
			}
			break;
		default:
			throw("Wrong Option !");
			break;
		}
		

	}
	catch (const char * msg) {
		
		MessageBoxA(NULL, msg, "Error", MB_OK | MB_ICONEXCLAMATION);
		Lobby();
	}
	
	return true;
}