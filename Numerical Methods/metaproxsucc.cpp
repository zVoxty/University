#include <iostream>
#include <math.h>

using namespace std;

float f(float x){
	return sqrt(10)/sqrt(x+4);
}

int main(){
	int itmax, it;
	
	float xz, xu, eps, dif;
		
	cout << "Introduceti eroare : ";
		cin >> eps;
	
	cout << " Introduceti nr max iteratii : ";
		cin >> itmax;
	cout << " Introduceti x(0): ";
		cin >> xz;
			
	it = 0;
	
	do{
		xu = f(xz) ;
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
