#include <iostream>
#include "Banca.h"
#include <stdlib.h>
#include <time.h>

using namespace std;

int main() {

	srand(rand() % 100 * time(NULL));

	Banca bank;

	bank.InregistrareClient();
	bank.InregistrareClient();

	bank.Lobby();

	bank.Revizie();

	system("PAUSE");
}