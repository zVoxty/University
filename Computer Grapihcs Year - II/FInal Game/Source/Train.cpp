#include"Train.h"
Train::Train(const BackBuffer *pBackBuffer)
{
	m_pSprite = new Sprite("data/train.bmp", RGB(0xff, 0x00, 0xff));
	m_pSprite->setBackBuffer(pBackBuffer);
	m_fTimer = 0;
	m_pBackBuffer = pBackBuffer;
}
Train::~Train()
{
	delete m_pSprite;
}
void Train::Draw()
{
	MovingObject::Draw();
}


void Train::Update(float dt)
{
	MovingObject::Update(dt);
	double v = m_pSprite->mVelocity.Magnitude();
	m_fTimer += dt;
	if (m_pSprite->mPosition.x >1700)
	{
		m_pSprite->mPosition.x = 0;
	}
	if (m_pSprite->mPosition.x<0)
	{
		m_pSprite->mPosition.x = 1500;
	}
}