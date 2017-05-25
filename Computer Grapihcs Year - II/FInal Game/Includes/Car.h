#ifndef _CAR_H
#define _CAR_H
#include "Main.h"
#include "Sprite.h"
#include "MovingObject.h"

class Car :public MovingObject
{
public:
	Car(const BackBuffer *pBackBuffer);
	virtual ~Car();

	void					Update(float dt);
	void					Draw();

	Sprite*					getSprite() { return m_pSprite; }
};

#endif 