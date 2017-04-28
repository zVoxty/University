#include "Dices.h"
#include <stdlib.h>
#include <time.h>
#include <iostream>

using namespace std;

Dices::Dices()
{
	_diceFaces = 6;
}


Dices::~Dices()
{
}

void Dices::dropDice() {
	srand(rand() % 1000 + time(NULL) * rand() % 20);
	_diceValue = rand() % _diceFaces + 1;
}

void printFrecventValue(int valueIndex) {
	if (valueIndex == 0) {
		cout << "Frecvent value is one !" << endl;
	}
	else if (valueIndex == 1) {
		cout << "Frecvent value is two !" << endl;
	}
	else if (valueIndex == 2) {
		cout << "Frecvent value is three !" << endl;
	}
	else if (valueIndex == 3) {
		cout << "Frecvent value is four !" << endl;
	}
	else if (valueIndex == 4) {
		cout << "Frecvent value is five !" << endl;
	}
	else if (valueIndex == 5) {
		cout << "Frecvent value is six !" << endl;
	}
}

void printFrecventMinimValue(int valueIndex) {
	if (valueIndex == 0) {
		cout << "Minim frecvent value is one !" << endl;
	}
	else if (valueIndex == 1) {
		cout << "Minim frecvent value is two !" << endl;
	}
	else if (valueIndex == 2) {
		cout << "Minim frecvent value is three !" << endl;
	}
	else if (valueIndex == 3) {
		cout << "Minim frecvent value is four !" << endl;
	}
	else if (valueIndex == 4) {
		cout << "Minim frecvent value is five !" << endl;
	}
	else if (valueIndex == 5) {
		cout << "Minim frecvent value is six !" << endl;
	}
}

void printFrecventConsecutiveValue(int valueIndex) {
	if (valueIndex == 0) {
		cout << "Frecvent consecutive value is one !" << endl;
	}
	else if (valueIndex == 1) {
		cout << "Frecvent consecutive value is two !" << endl;
	}
	else if (valueIndex == 2) {
		cout << "Frecvent consecutive value is three !" << endl;
	}
	else if (valueIndex == 3) {
		cout << "Frecvent consecutive value is four !" << endl;
	}
	else if (valueIndex == 4) {
		cout << "Frecvent consecutive value is five !" << endl;
	}
	else if (valueIndex == 5) {
		cout << "Frecvent consecutive value is six !" << endl;
	}
}
