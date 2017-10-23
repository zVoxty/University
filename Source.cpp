#include <iostream>
#include <time.h>

using namespace std;

//MS LAB 1
int main() {

	srand(time(NULL));
	
	int x0 = 27, a = 17, c = 43, m = 100;
	int i = 1;
	int temp, temp2;

	while (m+1 != i) 
	{
		temp = a*x0 + c;
		temp2 = temp % m;
		cout << "X" << i << " = " << "(" << a << "x" << x0 << "+" << c << ")" << "%" << m << "=" << temp << "%" << m << "=" << temp2 << endl;
		cout << "R" << i << " = " << temp << "%" << m << "=" << temp2 << endl << endl;
		x0 = temp2;
		i++;
	}

	system("pause");
}

