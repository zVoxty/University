#pragma once
#include "Core.h"

class Ball
{
public:
	Ball();
	~Ball();

	//Setters
	void setBallValue(int ballValue) {
		_ballValue = ballValue;
	}
	//Getters
	int getBallValue() {
		return _ballValue;
	}
private:
	int _ballValue;
};

