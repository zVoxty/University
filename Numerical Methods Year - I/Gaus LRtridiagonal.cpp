#include <iostream>

using namespace std;

int main(){
	int i,n;
	float a[10],b[10],c[10],t[10];
	cout << "insert number of lines and columns : ";
		cin >> n;
		cout << "Insert a." <<endl;
	for(i = 1; i <= n; i++){
		cin >> a[i];
	}
		cout << "Insert b." <<endl;
	for(i = 1; i <= n - 1; i++){
		cin >> b[i];
	}
		cout << "Insert c." <<endl;
	for(i = 1; i <= n - 1; i++){
		cin >> c[i];
	}
		cout << "Insert t." <<endl;
	for(i = 1; i <= n; i++){
		cin >> t[i];
	}
	//2
	for(i = 1; i <= n - 1; i++){
		//2.1
		if(a[i] == 0){
			cout << "Sist nu are sol";
			return 0;
		}
		//2.2
		c[i] /= a[i];
		//2.3
		a[i + 1] -= b[i] * c[i];
	}
	//3
	for(i = 2; i <= n; i++){
		t[i] -= c[i - 1] * t[i - 1];
	}
	//4
	if(a[n] == 0){
		cout << "Sist nu are sol unica";
		return 0;
	}
	//5
	t[n] /= a[n];
	//6
	for(i = n - 1; i >= 1; i--){
		t[i] = (t[i] - b[i] * t[i + 1]) / a[i];
	}
	//7
	for(i = 1; i <= n; i++){
		cout << "Sol sistemului este x[" << i << "] = "<< t[i] << endl;
	}
	
	return 0;
}
