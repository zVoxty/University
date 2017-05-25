#include "Coin.h"
#include "CGameApp.h"

extern CGameApp	g_App;

Coin::Coin(const BackBuffer *pBackBuffer)
{
	m_pSprite = new Sprite("data/coins.bmp", RGB(0xff, 0x00, 0xff));
	m_pSprite->setBackBuffer(pBackBuffer);
	m_fTimer = 0;
	m_pBackBuffer = pBackBuffer;
	avaiable = 0;
	spawned = false;
}

Coin::~Coin()
{
	delete m_pSprite;
}
void Coin::Draw()
{
	MovingObject::Draw();
}

void Coin::coinAvaiable()
{
	if (avaiable != 0) {
		if (!spawned) {
			m_pSprite->mPosition = Vec2(800, 500);
			spawned = true;
		}
		avaiable--;
	}
	else {
		spawned = false;
		m_pSprite->mPosition = Vec2(10000, 10000);
	}
}