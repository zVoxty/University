#include "Complex.h"

Complex::Complex(string functionName, int realPart , int imaginarPart)
{	
	_functionName = functionName;
	_realPart = realPart;
	_imaginarPart = imaginarPart;
}

Complex::~Complex()
{
}

void Complex::Print() {
	cout << _functionName << " = " << _realPart << " + " << _imaginarPart << "i\n";
}
