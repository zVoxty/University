#include <iostream>
#include <math.h>

using namespace std;

float f(float x){
	return 2*x - log(x) - 4;
}

float fder(float x){
	return 2 - 1/x;
}

int main(){
	int itmax, it;
	
	float xz, xu, eps, dif;
	
	cout << " Introduceti intervalul : ";
		cin >> xz >>xu;
		
	cout << "Introduceti eroare : ";
		cin >> eps;
	
	cout << " Introduceti nr max iteratii : ";
		cin >> itmax;
			
	it = 0;
	
	do{
		xu = xz - f(xz)/fder(xz) ;
		dif = fabs(xu - xz);
		xz = xu;
		it++;
	}while(dif >= eps && it <= itmax);
	
	if(it > itmax){
		cout << "Solutia nu s-a putut obtine in " << itmax << " iteratii !";
		return 0;
	}
	
	cout << "Solutia obtinuta in " << it << " iteratii cu precizia " << eps << " este "<< xu << " !";
	return 0;
}
