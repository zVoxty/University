#ifndef _MOVINGOBJECT_H_
#define _MOVINGOBJECT_H_

#include "Vec2.h"
#include "Sprite.h"



class MovingObject
{
public:
	void					Update(float dt);
	void					Draw();
	Vec2&					Position();
	Vec2&					Velocity();
	int Height()			{ return m_pSprite->height(); }
	int Width()				{ return m_pSprite->width(); }
protected:
	Sprite*					m_pSprite;
	const BackBuffer *      m_pBackBuffer;
	float					m_fTimer;
};

#endif