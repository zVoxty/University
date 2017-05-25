#ifndef _SHIELD_H_
#define _SHIELD_H_

#include "Main.h"
#include "Sprite.h"
#include "MovingObject.h"

class Shield : public MovingObject
{
public:

	Shield(const BackBuffer *pBackBuffer);
	virtual ~Shield();

	void					Draw();

	Sprite*					getSprite() { return m_pSprite; }

	int avaiable;
	bool spawned;

	void shieldAvaiable();
};


#endif // !_SHIELD_H_

