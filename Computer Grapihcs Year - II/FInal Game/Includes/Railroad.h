#ifndef _Railroad_H
#define _Railroad_H
#include "Main.h"
#include "Sprite.h"
#include "MovingObject.h"

class Railroad :public MovingObject
{
public:

	enum ESpeedStates
	{
		SPEED_START,
		SPEED_STOP
	};

	Railroad(const BackBuffer *pBackBuffer);
	virtual ~Railroad();

	void					Update(float dt);
	void					Draw();

	Sprite*					getSprite() { return m_pSprite; }

private:
	ESpeedStates			m_eSpeedState;
};

#endif 