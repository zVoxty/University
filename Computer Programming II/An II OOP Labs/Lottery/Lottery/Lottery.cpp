#include "Lottery.h"

Lottery::Lottery(string lotteryName)
{
	_lotteryName = lotteryName;
	cout << "Lottery " << _lotteryName << " was been created! \n";
}


Lottery::~Lottery()
{
	cout << "Lottery was been destroyed \n";
}
