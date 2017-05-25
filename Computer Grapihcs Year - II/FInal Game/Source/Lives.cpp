#include "Lives.h"


Lives::Lives(const BackBuffer* pBackBuffer)
{
	m_pSprite = new Sprite("data/heart.bmp", RGB(0xff, 0x00, 0xff));
	m_pSprite->setBackBuffer(pBackBuffer);
	m_fTimer = 0;
}
void Lives::Draw()
{
	m_pSprite->draw();
}
Lives::~Lives()
{
	delete m_pSprite;
}

void Lives::Update(float dt)
{
	m_pSprite->update(dt);

	m_fTimer += dt;
}
Vec2& Lives::Position()
{
	return m_pSprite->mPosition;
}

