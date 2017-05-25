#ifndef _TRAIN_H
#define _TRAIN_H
#include "Main.h"
#include "Sprite.h"
#include "MovingObject.h"

class Train :public MovingObject
{
public:
	Train(const BackBuffer *pBackBuffer);
	virtual ~Train();

	void					Update(float dt);
	void					Draw();

	Sprite*					getSprite() { return m_pSprite; }

};

#endif 