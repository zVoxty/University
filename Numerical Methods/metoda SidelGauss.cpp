#include <iostream>
#include <math.h>

using namespace std;

int main(){
	
	float eps ,max;
	int itmax = 50;
	float a[10][10];
	float t[10];
	float y;
	float x[10], S;
	int n, i, j, it;
	
	cout << " Insert eps : " << endl;
	cin >> eps;
	
	cout << "Insert nr of lines and columns : "<<endl;
		cin >> n;
	for(i = 1; i <= n; i++){
		for(j = 1; j <= n; j++){
			cin >> a[i][j];
		}
	}
	cout << "Insert x : ";
	for(i = 1; i <= n; i++ ){
		cin >>x[i];
	}
	
	cout << "Insert t : ";
	for(i = 1; i <= n; i ++){
		cin >> t[i];
	}
	
	//2
	it = 0;
	//3
	
	do{
		//3.1
		max = 0;
		//3.2
		for(i = 1; i <= n; i++){
			//3.2.1
			S = 0;
			//3.2.2
			for(j = 1; j <= n; j++){
				//3.2.2.1
				if(j != i){
					//3.2.2.1.1
					S = S + a[i][j] * x[j];
				}
			}
			//3.2.3
			y = (t[i] - S) / a[i][i];
			//3.2.4
			if(max < fabs(y - x[i])){
				//3.2.4.1
				max = fabs(y - x[i]);
			}
			//3.2.5
			x[i] = y;
		}
		//3.3
		it++;
	}while(max >= eps && it <= itmax);
	//4
	if(it > itmax){
		cout << "Sol sist nu s-a putut obtine in " << it << " iteratii cu precizia " << eps <<endl;
		return 0;
	}
	//5
	for(i = 1; i <= n; i++){
		cout << "Solutia obtinuta in " << it << " iteratii este " << x[i] <<endl;
	}
	
	return 0;
	
}
