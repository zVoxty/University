#include "Core.h"
#include "Reservation.h"

int main() {

	bool programOnOff = true;
	int option;

	Reservation reservation;
	vector<Bear> bears;
	vector<Fox> foxs;
	vector<Lion> lions;
	vector<Rabbit> rabbits;
	vector<Deer> deers;

	cout << "\t\t Welcome to zoo ! \n\n";
	

	while (programOnOff == true) {
		cout << "There are " << reservation.animalsInReservation << " animals in our reservation\n";
		mainMenu();
		cin >> option;
		
		switch (option)
		{
		case 1: {
			string newAnimalType;
			//Case for insert animal
			cout << "What's the type of animal (bear, fox, rabbit, lion, deer): ";
			cin >> newAnimalType;
			
			if (newAnimalType == "bear") {
				cout << "\n Insert name of " << newAnimalType << " : ";
				string bearName;
				cin >> bearName;
				Bear bear(bearName);
				bear.getDataBear();
				bears.push_back(bear);
				reservation.animalsInReservation++;

			}
			else if (newAnimalType == "fox") {
				cout << "\n Insert name of " << newAnimalType << " : ";
				string foxName;
				cin >> foxName;
				Fox fox(foxName);
				fox.getDataFox();
				foxs.push_back(fox);
				reservation.animalsInReservation++;
			}
			else if (newAnimalType == "rabbit") {
				cout << "\n Insert name of " << newAnimalType << " : ";
				string rabbitName;
				cin >> rabbitName;
				Rabbit rabbit(rabbitName);
				rabbit.getDataRabbit();
				rabbits.push_back(rabbit);
				reservation.animalsInReservation++;
			}
			else if (newAnimalType == "lion") {
				cout << "\n Insert name of " << newAnimalType << " : ";
				string lionName;
				cin >> lionName;
				Lion lion(lionName);
				lion.getDataLion();
				lions.push_back(lion);
				reservation.animalsInReservation++;
			}
			else if (newAnimalType == "deer") {
				cout << "\n Insert name of " << newAnimalType << " : ";
				string deerName;
				cin >> deerName;
				Deer deer(deerName);
				deer.getDataDeer();
				deers.push_back(deer);
				reservation.animalsInReservation++;
			}
			else {
				cout << "\n I don't know this animal type ! \n";
			}
		}
			

				break;

		case 2:
			cout << "There are " << bears.size() << " bears in reservation !\n";
			cout << "There are " << lions.size() << " lions in reservation !\n";
			cout << "There are " << deers.size() << " deers in reservation !\n";
			cout << "There are " << rabbits.size() << " rabbits in reservation !\n";
			cout << "There are " << foxs.size() << " foxs in reservation !\n";
			break;
		default:
			cout << "\nWrong option !\n";
			break;
		}
	}

	system("PAUSE");
}