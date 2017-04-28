#include <iostream>
#include <math.h>

using namespace std;

int main(){
	
	int n, i, j, k;
	float y[10][10];
	float z[10][10],SUM;

	float a[100];
	float b[100];
	float c[100];
	float x1 ,x2;
	float p,q,eps;
	float delta,S,R;
	
	cout << "Introduceti n : ";
		cin >> n;
	
	for(i = 1; i<= n;i++){
		for(j = 1; j<= n; j++){
			cin >> y[i][j];
		}
	}
	
	for(i = 1; i<= n; i++){
		cin >> z[i][n];
		
	}
	
	for(j = n - 1; j>= 1; j--){
		for(i = 1; i<=n;i++){
			z[i][j] = 0;
			for(k = 1; k<=n;k++){
				z[i][j] = z[i][j] + y[i][k] * z[k][j+1];
			}
		}
	}
	
	for(i = 1; i<=n;i++){
		z[i][n+1] = 0;
		for( k = 1; k<=n;k++){
			z[i][n+1] = z[i][n+1] + y[i][k]* z[k][1];
		}
		z[i][n+1] = -z[i][n+1];
	}
	
	//-----------------------GAUSS
	
	for(k = 1; k <= n-1; k++){
		//2.1		
		if(z[k][k] != 0){
			//2.1.1
			for(i = k + 1; i <= n; i++){
				//2.1.1.1
				z[i][k] = z[i][k] / z[k][k];
				//2.1.1.2	
				for(j = k + 1; j <= n + 1; j++){
					//2.1.1.2.1
					z[i][j] = z[i][j] - z[i][k] * z[k][j];
				}
			}
		}
		//2.2
		else{
			break;
		}
	}
	//3
	if(z[n][n] == 0){
		//3.1
		cout << "Sistemul nu are sol unica!" << endl;
	}
	//4
	else{
		//4.1
		z[n][n + 1] = z[n][n + 1] / z[n][n];
	}
	//5
	for(i = n - 1; i >= 1; i--){
		//5.1
		SUM = 0;
		//5.2	
		for( j = i + 1; j <= n; j++){
			//5.2.1
			SUM = SUM + z[i][j] * z[j][n + 1];
		}
		//5.3	
		z[i][n + 1] = (z[i][n + 1] - SUM) / z[i][i];
	}
	//6
	for(i = 1; i <= n; i++){
		cout << " Solutia x" << i << "=" << z[i][n+1];
		cout << endl;
	}
	
	for(i = 0; i <= n; i++){
		cout << "Insert a["<<i<< "] = :";
		cin >> a[i];
	}
	
	for(i = 0; i < n; i++){
		cout << "a["<<i<<"] este :"<< a[i] <<endl;
	}
	
	while(n > 2){
		cout << "Insert p \n";
		cin >> p;
		cout << "Insert q \n";
		cin >> q;
		cout << "Insert eps \n";
		cin >> eps;
		
		do{
			b[0] = a[0];
			b[1] = a[1] - p*b[0];
			for(k = 2; k <= n; k++){
				b[k] = a[k] - p *b[k-1] - q * b[k-2];
			}
			
			c[0] = b[0];
			c[1] = b[1] - p * c[0];
			
			for(k = 2; k <= n-1; k++){
				c[k] = b[k] - p * c[k-1] - q * c[k-2];
			}
			
			delta = pow(c[n-2],2) - c[n - 1] * c[n - 3] + b[n - 1] * c[n - 3];
			R = b[n] * c[n-3] - b[n-1] * c[n-2];
			S = b[n -1] * c[n-1] - pow(b[n-1], 2) - b[n] * c[n-2];
			
			p = p - R/delta;
			q = q - S/delta;
		}while(fabs(R + S/delta) > eps);
		
		cout << " P este : \n"<< p <<" \n Q este \n"<< q << endl;
		if((pow(p,2) - 4*q) >= 0){
			
			x1 = (-p - sqrt(pow(p,2) - 4*q))/2;
			x2 = (-p + sqrt(pow(p,2) - 4*q))/2;
			
			cout <<"x1 = "<< x1 << ", x2 = " << x2 << endl;
		}
		else{
			cout << "x1 = " << -p/2 << "-" << "i * " << sqrt(4*q - pow(p,2))/2<<endl;
			cout << "x1 = " << -p/2 << "+" << "i * " << sqrt(4*q - pow(p,2))/2<<endl;
		}
		
		n = n - 2;
		
		for( k = 0; k <= n; k++){
			a[k] = b[k];
		}
	}
	
	if(n == 1){
		cout << "Se obtine un factor liniar b[0]x + b[1] cu solutia \n" <<  -b[1]/b[0];
	}
	else{
		cout << "Se obtine un factor patratic b[0]x^2 + b[1]x + b[2]\n";
		if(pow(b[1],2) - 4*b[0]* b[2] >= 0){
			int ecz = sqrt(pow(b[1],2)) - 4*b[0]*b[2];
			x1 = (-b[1] - ecz) / 2* b[0];
			x2 = (-b[1] + ecz) / 2* b[0];
		}
		cout <<"x1 = "<< x1<< endl << " x2 = " << x2 <<endl;
	}
	
	return 0;
}
