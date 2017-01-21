#pragma once
#include "Client.h"
#include <vector>
#include <Windows.h>

class Banca
{
public:
	Banca();
	~Banca();

	bool Lobby();
	void InregistrareClient();
	void Revizie();

private:
	bool TransferBani(int baseIndexUser);
	int FindUsername(std::string username);
	bool FindPIN(int userindex, std::string PIN);
	bool Withdraw(int userindex);
	bool DepunereNumerar(int userindex);

private:
	std::vector<Client> users;
	int plafonBanca;
};

