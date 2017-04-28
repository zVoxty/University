#pragma once
#include <iostream>
#include <string>
#include <math.h>

using namespace std;

class Complex
{
public:
	Complex(string functionName = "", int realPart = 0, int imaginarPart = 0);
	~Complex();

	Complex operator+(Complex secondFunction) {
		Complex temp;
		temp._realPart = this->_realPart + secondFunction._realPart;
		temp._imaginarPart = this->_imaginarPart + secondFunction._imaginarPart;
		return temp;
	}

	/*Produsul a două numere complexe z = (a, b) = a + bi și w = (c, d) = c + di este zw = (ac - bd, bc + ad) = (ac - bd) + i(bc + ad).*/
	Complex operator*(Complex secondFunction) {
		Complex temp;
		temp._realPart = (this->_realPart * secondFunction._realPart) - (this->_imaginarPart * secondFunction._imaginarPart);
		temp._imaginarPart = (this->_imaginarPart * secondFunction._realPart) + (this->_realPart*secondFunction._imaginarPart);
		return temp;
	}

	Complex operator^(int n) {
		Complex ONE("one", 1, 0);
		if (n <= 0) {
		return ONE;
		}
		return ((*this)*((*this) ^ (n - 1)));
	}

	Complex operator/(Complex c)
	{
		int div = (c._realPart*c._realPart) + (c._imaginarPart*c._imaginarPart);
		Complex tmp;
		tmp._realPart = (_realPart*c._realPart) + (_imaginarPart*c._imaginarPart);
		tmp._realPart /= div;
		tmp._imaginarPart = (_imaginarPart*c._realPart) - (_realPart*c._imaginarPart);
		tmp._imaginarPart /= div;
		return tmp;
	}

	double operator~() {
		return sqrt((this->_realPart ^ 2) + (this->_imaginarPart ^ 2));
	}

	void setName(string name) {
		_functionName = name;
	}

	string getName() {
		return _functionName;
	}

	int getRealPart() {
		return _realPart;
	}

	int getImaginarPart() {
		return _imaginarPart;
	}

	void Print();

public:
	string _functionName;
	int _realPart;
	int _imaginarPart;
};

