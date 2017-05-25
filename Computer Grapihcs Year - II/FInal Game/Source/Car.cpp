#include"Car.h"
#include "CGameApp.h"

extern CGameApp	g_App;

Car::Car(const BackBuffer *pBackBuffer)
{
	m_pSprite = new Sprite("data/car.bmp", RGB(0xff, 0x00, 0xff));
	m_pSprite->setBackBuffer(pBackBuffer);
	m_fTimer = 0;
	m_pBackBuffer = pBackBuffer;
}

Car::~Car()
{
	delete m_pSprite;
}
void Car::Draw()
{
	MovingObject::Draw();
}


void Car::Update(float dt)
{
	MovingObject::Update(dt);
	double v = m_pSprite->mVelocity.Magnitude();
	m_fTimer += dt;
	if (m_pSprite->mPosition.x > g_App.m_nViewWidth)
	{
		m_pSprite->mPosition.x = 0;
	}
	if (m_pSprite->mPosition.x<0 )
	{
		m_pSprite->mPosition.x = g_App.m_nViewWidth;
	}
}