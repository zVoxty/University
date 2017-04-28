#include <iostream>
#include <string>
#include "engine.h"

using namespace std;

int main() {

	string mainSecv;
	string searchSecv;

	cout << "Insert main secvence : ";
	cin >> mainSecv;

	cout << "Insert searched secvence : ";
	cin >> searchSecv;

	cout << secvenceExist(mainSecv, searchSecv) << endl;

	system("PAUSE");
}