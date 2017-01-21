#include "Client.h"



Client::Client()
{
	bani = 10000;
	PinGresit = 3;
}


Client::~Client()
{
}

void Client::Register() {
	system("CLS");
	std::cout << "\n\n\t\tInregistrare Client\n";

	std::cout << "Set username : ";
	std::cin >> userName;

	std::cout << "Set PIN : ";
	std::cin >> PIN;
}
