#include <iostream>
#include "Dices.h"
#include <vector>

using namespace std;

int main() {

	vector<Dices> dices;
	vector<int> drops;
	vector<int> consecutiveDrops;
	drops.resize(6);
	consecutiveDrops.resize(6);

	cout << "Insert number of drops : ";
	int dropsNumber;
	cin >> dropsNumber;

	dices.resize(dropsNumber);

	for (int i = 0; i < dropsNumber; i++) {
		dices[i].dropDice();

		if (dices[i].getDiceValue() == 1) {
			drops[0]++;
		}
		else if (dices[i].getDiceValue() == 2) {
			drops[1]++;
		}
		else if (dices[i].getDiceValue() == 3) {
			drops[2]++;
		}
		else if (dices[i].getDiceValue() == 4) {
			drops[3]++;
		}
		else if (dices[i].getDiceValue() == 5) {
			drops[4]++;
		}
		else if (dices[i].getDiceValue() == 6) {
			drops[5]++;
		}

		if (i != 0) {
			if (dices[i].getDiceValue() == 1 && dices[i-1].getDiceValue() == 1) {
				consecutiveDrops[0]++;
			}
			else if (dices[i].getDiceValue() == 2 && dices[i - 1].getDiceValue() == 2) {
				consecutiveDrops[1]++;
			}
			else if (dices[i].getDiceValue() == 3 && dices[i - 1].getDiceValue() == 3) {
				consecutiveDrops[2]++;
			}
			else if (dices[i].getDiceValue() == 4 && dices[i - 1].getDiceValue() == 4) {
				consecutiveDrops[3]++;
			}
			else if (dices[i].getDiceValue() == 5 && dices[i - 1].getDiceValue() == 5) {
				consecutiveDrops[4]++;
			}
			else if (dices[i].getDiceValue() == 6 && dices[i - 1].getDiceValue() == 6) {
				consecutiveDrops[5]++;
			}
		}
	}

	int indexOfFrecventValue;
	int indexOfFrecventConsecutiveValue;
	int frecventValue = 0;
	int frecventConsecutiveValue = 0;
	int minimFrecventValue = dropsNumber;
	int indexOfMinimFrecventValue = 0;

	for (int i = 0; i < drops.size(); i++) {
		if (drops[i] >= frecventValue) {
			frecventValue = drops[i];
			indexOfFrecventValue = i;
		}
		if (drops[i] <= minimFrecventValue) {
			minimFrecventValue = drops[i];
			indexOfMinimFrecventValue = i;

		}
		if (consecutiveDrops[i] >= frecventConsecutiveValue) {
			frecventConsecutiveValue = consecutiveDrops[i];
			indexOfFrecventConsecutiveValue = i;
		}
	}

	cout << "One : " << drops[0] << endl;
	cout << "Two : " << drops[1] << endl;
	cout << "Three : " << drops[2] << endl;
	cout << "Four : " << drops[3] << endl;
	cout << "Five : " << drops[4] << endl;
	cout << "Six : " << drops[5] << endl << endl;

	cout << "One : " << consecutiveDrops[0] << endl;
	cout << "Two : " << consecutiveDrops[1] << endl;
	cout << "Three : " << consecutiveDrops[2] << endl;
	cout << "Four : " << consecutiveDrops[3] << endl;
	cout << "Five : " << consecutiveDrops[4] << endl;
	cout << "Six : " << consecutiveDrops[5] << endl << endl;

	printFrecventValue(indexOfFrecventValue);
	printFrecventMinimValue(indexOfMinimFrecventValue);
	printFrecventConsecutiveValue(indexOfFrecventConsecutiveValue);

	system("PAUSE");
}