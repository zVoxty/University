
#ifndef _STREET_H
#define _STREET_H
#include "Main.h"
#include "Sprite.h"
#include "Car.h"
#include "MovingObject.h"

class Street :public MovingObject

{
public:
	Street(const BackBuffer *pBackBuffer);
	virtual ~Street();

	void					Update(float dt);
	void					Draw();

	Sprite*					getSprite() { return m_pSprite; }
};

#endif 