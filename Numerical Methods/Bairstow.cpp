#include <iostream>
#include <math.h>

using namespace std;

int main(){
	
	int i, n, k;
	float a[100];
	float b[100];
	float c[100];
	float x1 ,x2;
	float p,q,eps;
	float delta,S,R;
	
	cout << "Insert n : ";
	cin >> n;
	
	for(i = 0; i <= n; i++){
		cout << "Insert a["<<i<<"] : ";
		cin >> a[i];
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
