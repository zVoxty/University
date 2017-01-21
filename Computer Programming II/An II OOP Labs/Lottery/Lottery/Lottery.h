#pragma once
#include "Core.h"
#include "Jackpot.h"

class Lottery
{
public:
	Lottery(string lotteryName);
	~Lottery();

	Jackpot jackpot;

private:
	string _lotteryName;
};

