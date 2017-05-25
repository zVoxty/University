#ifndef _COIN_H_
#define _COIN_H_

#include "Main.h"
#include "Sprite.h"
#include "MovingObject.h"

class Coin : public MovingObject
{
public:

	Coin(const BackBuffer *pBackBuffer);
	virtual ~Coin();

	void					Draw();

	Sprite*					getSprite() { return m_pSprite; }

	int avaiable;
	bool spawned;

	void coinAvaiable();
};


#endif // !_COIN_H_

