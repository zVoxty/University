#include "MovingObject.h"

void MovingObject::Draw()
{
	
		m_pSprite->draw();
}

Vec2& MovingObject::Position()
{
	return m_pSprite->mPosition;
}

Vec2& MovingObject::Velocity()
{
	return m_pSprite->mVelocity;
}

void MovingObject::Update(float dt)
{
	
	// Update sprite
	m_pSprite->update(dt);


}


