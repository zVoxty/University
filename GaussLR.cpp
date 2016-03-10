#include <iostream>
#include <windows.h>

using namespace std;

int main(){
	
	int n, i, k, j;
	float a[10][10]	, aux, S, piv;
	
	cout << "Insert number of lines and columns : ";
		cin >> n;
	//1	
	for(i = 1; i <= n; i++){
		for(j = 1; j <= n + 1; j++){
			cin >> a[i][j];
		}
	}
	//2
	if(a[1][1] == 0){
		//2.1
		i = 1;
		//2.2
		do{
			i++;
		}while(a[i][1] == 0 && i <=n);
		//2.3
		if(i > n){
			cout << "Sist nu are solutie unica ! \n";
			system("PAUSE");
		}
		//2.4
		for(j = 1; j <= n + 1; j++){
			aux = a[1][j];
			a[1][j] = a[i][j];
			a[i][j] = aux;
		}
	}
	//3
	for(i = 2; i <= n; i++){
		a[i][1] /= a[1][1];
	}
	//4
	for(k = 2; k <= n; k++){
		i = k;
		do{
			S = 0;
			for(int h = 1; h <= k - 1; h++){
				S += a[i][h] * a[h][k];
			}
			piv = a[i][k] - S;
			i++;
		}while(piv == 0 && i <=n);
		//4.3
		if(piv == 0){
			cout << "Sist nu are sol";
			system("PAUSE");
		}
		//4.4
		if(i != k + 1){
			for(j = 1; j <= n + 1; j++){
				aux = a[k][j];
				a[k][j] = a[i - 1][j];
				a[i-1][j] = aux;
			}
		}
		//4.5
		for(j = k; j <= n; j++){
			S = 0;
			for(int h = 1; h <= k - 1; h++){
				S = S + a[k][h] * a[h][j];
			}
			a[k][j] = a[k][j] - S;
		}
		//4.6
		for( i = k + 1; i <= n; i++){
			S = 0;
			for(int h = 1; h <= k - 1; h++){
				S = S + a[i][h] * a[h][k];
			}
			a[i][k] = (a[i][k] - S) / a[k][k];
		}
	}
	//5
	for(i = 2; i <= n;i++){
		S = 0;
		for(j = 1; j <= i - 1; j++){
			S = S + a[i][j] * a[j][n + 1];
		}
		a[i][n + 1] = a[i][n + 1] - S;
	}
	//6
	a[n][n + 1] = a[n][n + 1] / a[n][n];
	//7
	for(i = n - 1; i >= 1; i--){
		S = 0;
		for(j = i + 1; j <= n; j++){
			S = S + a[i][j] * a[j][n+1];
		}
		a[i][n + 1] = (a[i][n+1] - S) / a[i][i];
	}
	
	for(i = 1; i <= n; i++){
		cout << "x["<<i<<"] = "<<a[i][n + 1] <<endl;
	}
	
	system("PAUSE");
}
