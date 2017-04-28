#include <iostream>
#include <vector>
#include "Complex.h"
#include <time.h>
#include <stdlib.h>

#define generateNumber (rand() % 10 + 1);

using namespace std;

int main() {
	
	srand((rand() % 100 + 1) * time(NULL));

	vector<Complex> complexNumbers;

	int N;
	cout << "How many complex numbers : ";
	cin >> N;

	Complex complexNumber;
	Complex Over;
	Complex Under;

	for (int i = 0; i < N; i++) {
		string name = "z" + to_string(i+1);
		complexNumber.setName(name);
		complexNumber._realPart = generateNumber;
		complexNumber._imaginarPart = generateNumber;

		complexNumbers.push_back(complexNumber);
	}

	for (int i = 0; i < complexNumbers.size(); i++) {
		cout << complexNumbers[i].getName() << " = " << complexNumbers[i].getRealPart() << " + " << complexNumbers[i].getImaginarPart() << "i" << endl;
	}

	cout << "\n Request : \n";
	cout << "Z = (";

	for (int i = 0; i < complexNumbers.size(); i++) {
		if (i % 2 == 0) {
			if (i + 2 != complexNumbers.size()) {
				cout << complexNumbers[i].getName() << " + ";
			}
			else{
				cout << complexNumbers[i].getName();
			}

			Over = Over + complexNumbers[i];
		}
	}

	cout << ") / (";

	for (int i = 0; i < complexNumbers.size(); i++) {
		if (i % 2 == 1) {
			if (i + 1 != complexNumbers.size()) {
				cout << complexNumbers[i].getName() << " + ";
			}
			else {
				cout << complexNumbers[i].getName();
			}
			Under = Under + complexNumbers[i];
		}
	}

	cout << ")\n\n";
	Over.setName("Over");
	Over.Print();
	cout << endl;
	Under.setName("Under");
	Under.Print();
	cout << endl;

	Complex Z;

	Z = Over / Under;
	Z.setName("Z");
	Z.Print();
	cout << endl;

	system("PAUSE");
}