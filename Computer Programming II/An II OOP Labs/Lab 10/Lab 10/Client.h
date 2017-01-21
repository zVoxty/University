#pragma once
#include <iostream>
#include <string>

class Banca;

class Client
{
public:
	Client();
	~Client();

	friend Banca;

	void Register();

private:
	std::string userName;
	std::string PIN;
	int bani;
	int PinGresit;
};

