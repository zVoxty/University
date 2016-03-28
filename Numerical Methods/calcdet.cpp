#include <iostream>

using namespace std;

int main(){
	//1
	float a[10][10];
	int n, i, j;
    int det;
	
	cin >> n;
	
	for(i =1; i<= n; i++){
		for(j = 1; j <= n; j++){
			cin >> a[i][j];
		}
	}
	//2
	det = 1;
	//3
	do{
		//3.1
		if(a[1][1] == 0){
			
			//3.1.1
			i = 2;
			
			//3.1.2
			while( i <= n && a[i][1] == 0){
				i++;
			}
			
			//3.1.3
			if(i > n){
				cout << "Determinat a = 0 \n";
				return 0;
			}
			
			//3.1.4
			for(j = 1; j <= n; j++){
				float aux = a[1][j];
				a[1][j] = a[i][j];
				a[i][j] = aux;
			}
			
			//3.1.5
			det = -det;
		}
		
		//3.2
		for(i = 1; i <= n - 2; i++){
			det = det * a[1][1];
		}
		
		//3.3
		for(i = 2; i <= n; i++){
			
			//3.3.1
			for(j = 2; j <= n; j++){
				
				//3.3.1.1
				a[i][j] = a[i][j] * a[1][1] - a[i][1] * a[1][j];
			}
		}
		
		//3.4
		n--;
		
		//3.5
		for(i = 1; i <= n; i++){
			
			//3.5.1
			for(j = 1; j <= n; j++){
				
				//3.5.1.1
				a[i][j] = a[i + 1][j + 1];
			}
		}
	}while(n != 1);
	
	//4
	det = a[1][1]/det;
	
	//5
	cout << "Determinantul este egal cu = "<<det;
	
	return 0;
}
