#pragma once
class Dices
{
public:
	Dices();
	~Dices();

	void dropDice();

	//Getters
	int getDiceValue() {
		return _diceValue;
	}

private:
	int _diceFaces;
	int _diceValue;
};

void printFrecventValue(int valueIndex);
void printFrecventMinimValue(int valueIndex);
void printFrecventConsecutiveValue(int valueIndex);

