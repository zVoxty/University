#include <iostream>
#include <math.h>
#include <windows.h>

using namespace std;



int main() {
	int n, i, j, k;
	cout << "Number of lines and columns: ";
	cin >> n;

	float a[10][10];
	float S;
	// 1
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n + 1; j++) {
			cin >> a[i][j];
		}
	}

	// 2
	for (k = 1; k <= n - 1; k++) {
		//2.1
		if (a[k][k] != 0) {
			//2.1.1
			for (i = k + 1; i <= n; i++) {
				//2.1.1.1
				a[i][k] = a[i][k] / a[k][k];
				//2.1.1.2
				for (j = k + 1; j <= n + 1; j++) {
					//2.1.1.2.1
					a[i][j] = a[i][j] - a[i][k] * a[k][j];
				}
			}
		}
		//2.2
		else {
			cout << "STOP" << endl;
			break;
		}
	}
	//3
	if (a[n][n] == 0) {
		cout << "Sistemul nu are sol unica!" << endl;
	}
	//4
	else {
		a[n][n + 1] = a[n][n + 1] / a[n][n];
	}
	//5
	for (i = n - 1; i >= 1; i--) {
		//5.1
		S = 0;
		//5.2
		for (j = i + 1; j <= n; j++) {
			//5.2.1
			S = S + a[i][j] * a[j][n + 1];
		}
		//5.3
		a[i][n + 1] = (a[i][n + 1] - S) / a[i][i];
	}
	//6
	for (i = 1; i <= n; i++) {
		//6.1
		cout << " Solutia x" << i << "=" << a[i][n + 1];
		cout << endl;
	}
	Sleep(1000000);
	return 0;
}
