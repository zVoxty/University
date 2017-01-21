#include <iostream>
#include <string>

using namespace std;

class Caine {
	//numele, înãlþime, greutate, vârstã, culoare
public:
	string nume;
	string culoare;
	int inaltime;
	int greutate;
	int varsta;

	virtual void Citire() {
		cout << "Nume : ";
		cin >> this->nume;
		cout << "Culoare : ";
		cin >> this->culoare;
		cout << "Inaltime : ";
		cin >> this->inaltime;
		cout << "Greutate : ";
		cin >> this->greutate;
		cout << "Varsta : ";
		cin >> this->varsta;
	}

	virtual void Afisare() {
		cout << this->nume << " " << this->culoare << " " << this->inaltime << " " << this->greutate << " " << this->varsta;
	}
};

class CaineCuPete : public Caine {
public:
	int numarDePete;

	void Citire() {
		Caine::Citire();
		cout << "Numar de pete : ";
		cin >> this->numarDePete;
	}

	void Afisare() {
		Caine::Afisare();
		cout << " " << this->numarDePete << endl;
	}
};

class CaineFaraPete : public Caine {
public:
	void Citire() {
		Caine::Citire();
	}
	void Afisare() {
		Caine::Afisare();
	}
};


int main() {

	CaineCuPete caineCuPete;
	caineCuPete.Citire();
	caineCuPete.Afisare();

	cout << "\n\n";

	CaineFaraPete caineFaraPete;
	caineFaraPete.Citire();
	caineFaraPete.Afisare();

	system("PAUSE");
}