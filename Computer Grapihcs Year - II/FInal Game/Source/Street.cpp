#include"Street.h"
#include <stdlib.h> 

Street::Street(const BackBuffer *pBackBuffer)
{
	m_pSprite = new Sprite("data/street1.bmp", RGB(0xff, 0x00, 0xff));
	m_pSprite->setBackBuffer(pBackBuffer);
	m_fTimer = 0;
	m_pBackBuffer = pBackBuffer;

}
Street::~Street()
{
	delete m_pSprite;
}
void Street::	Update(float dt)
{
	MovingObject::Update(dt);
	double v = m_pSprite->mVelocity.Magnitude();
	m_fTimer += dt;
	if (m_pSprite->mPosition.y >750)
	{
		m_pSprite->mPosition.y = 12;
	}
}
void Street::Draw()
{
	MovingObject::Draw();

}
