#include <iostream>
#include <math.h>
#include <vector>
using namespace std;

class OneDimensionArray {
public:
	OneDimensionArray(int size = 10) {
		this->size = size;
		elements.resize(size);
	}

	double &operator [](int nr) {
		return elements[nr];
	}

	int size;
	vector<double> elements;
};


void main() {
	OneDimensionArray a1(20);
	OneDimensionArray a2;

	for (int i = 0; i < a1.size; i++) {
		a1[i] = 7.5;
	}

	for (int i = 0; i < a1.size; i++)
		cout << a1.elements[i] << " ";

	cout << endl;
	system("PAUSE");
}