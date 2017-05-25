#ifndef __LIVE_H__
#define __LIVE_H__

#include "Main.h"
#include "Sprite.h"
#include "MovingObject.h"

class Lives
{
public:
	Lives(const BackBuffer*);
	virtual ~Lives();
	void					Update(float dt);
	void					Draw();
	Vec2&					Position();
	Vec2&					Velocity();
	Sprite*					getSprite() { return m_pSprite; }

private:

	Sprite*					m_pSprite;
	float					m_fTimer;
};
#endif