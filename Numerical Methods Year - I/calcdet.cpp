#include <iostream>

using namespace std;

float a[10][10];
int i, j;

int main() {

	int val_det;
	int n; /* n = Number of lines and columns */
	cout << " Insert number of lines and columns : ";
	cin >> n;

	/* Read Matrix */
	for (i = 1; i <= n; i++) {
		for (j = 1; j <= n; j++) {
			cin >> a[i][j];
		}
	}
	
	if (a[1][1] == 0) {
		cout << "First determinant is 0 !\n ";
	}
	else {
	
		cout << "First determinant is " << a[1][1] << " !\n";
	}

	if (a[1][1] * a[2][2] - a[1][2] * a[2][1] == 0) {
		cout << "Second determinant is 0 !\n";
	}
	else{
		cout << "Second determinant is " << a[1][1] * a[2][2] - a[1][2] * a[2][1] << " !\n";
	}

	/* Set default value */
	val_det = 1;

	do {
		/* If first element is 0 search on next lines an element != 0 */
		if (a[1][1] == 0) {
			/* Set i = next line */
			i = 2;
			
			while (i <= n && a[i][1] == 0) {
				i++;
			}

			
			if (i > n) {
				cout << "Determinat a = 0 \n";
				return 0;
			}

			
			for (j = 1; j <= n; j++) {
				float aux = a[1][j];
				a[1][j] = a[i][j];
				a[i][j] = aux;
			}

		
			val_det = -val_det;
		}

		
		for (i = 1; i <= n - 2; i++) {
			val_det = val_det * a[1][1];
		}

		
		for (i = 2; i <= n; i++) {
			for (j = 2; j <= n; j++) {

			
				a[i][j] = a[i][j] * a[1][1] - a[i][1] * a[1][j];
			}
		}

	
		n--;

		
		for (i = 1; i <= n; i++) {

		
			for (j = 1; j <= n; j++) {

				
				a[i][j] = a[i + 1][j + 1];
			}
		}
	} while (n != 2);

		val_det = a[1][1] / val_det;

		cout << "Third determinant is " << val_det << " !\n";

	system("PAUSE");
}
