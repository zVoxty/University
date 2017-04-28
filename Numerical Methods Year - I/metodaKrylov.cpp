#include <iostream>

using namespace std;

int main(){
	
	int n, i, j, k;
	float a[10][10];
	float b[10][10],S;
	
	cout << "Introduceti n : ";
		cin >> n;
	
	for(i = 1; i<= n;i++){
		for(j = 1; j<= n; j++){
			cin >> a[i][j];
		}
	}
	
	for(i = 1; i<= n; i++){
		cin >> b[i][n];
		
	}
	
	for(j = n - 1; j>= 1; j--){
		for(i = 1; i<=n;i++){
			b[i][j] = 0;
			for(k = 1; k<=n;k++){
				b[i][j] = b[i][j] + a[i][k] * b[k][j+1];
			}
		}
	}
	
	for(i = 1; i<=n;i++){
		b[i][n+1] = 0;
		for( k = 1; k<=n;k++){
			b[i][n+1] = b[i][n+1] + a[i][k]* b[k][1];
		}
		b[i][n+1] = -b[i][n+1];
	}
	
	//-----------------------GAUSS
	
	for(k = 1; k <= n-1; k++){
		//2.1		
		if(b[k][k] != 0){
			//2.1.1
			for(i = k + 1; i <= n; i++){
				//2.1.1.1
				b[i][k] = b[i][k] / b[k][k];
				//2.1.1.2	
				for(j = k + 1; j <= n + 1; j++){
					//2.1.1.2.1
					b[i][j] = b[i][j] - b[i][k] * b[k][j];
				}
			}
		}
		//2.2
		else{
			break;
		}
	}
	//3
	if(b[n][n] == 0){
		//3.1
		cout << "Sistemul nu are sol unica!" << endl;
	}
	//4
	else{
		//4.1
		b[n][n + 1] = b[n][n + 1] / b[n][n];
	}
	//5
	for(i = n - 1; i >= 1; i--){
		//5.1
		S = 0;
		//5.2	
		for( j = i + 1; j <= n; j++){
			//5.2.1
			S = S + b[i][j] * b[j][n + 1];
		}
		//5.3	
		b[i][n + 1] = (b[i][n + 1] - S) / b[i][i];
	}
	//6
	for(i = 1; i <= n; i++){
		cout << " Solutia x" << i << "=" << b[i][n+1];
		cout << endl;
	}
	
	return 0;
}
