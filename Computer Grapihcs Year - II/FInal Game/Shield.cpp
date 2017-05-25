#include "Shield.h"
#include "CGameApp.h"

extern CGameApp	g_App;

Shield::Shield(const BackBuffer *pBackBuffer)
{
	m_pSprite = new Sprite("data/shield.bmp", RGB(0xff, 0x00, 0xff));
	m_pSprite->setBackBuffer(pBackBuffer);
	m_fTimer = 0;
	m_pBackBuffer = pBackBuffer;
	avaiable = 0;
	spawned = false;
}

Shield::~Shield()
{
	delete m_pSprite;
}
void Shield::Draw()
{
	MovingObject::Draw();
}

void Shield::shieldAvaiable()
{
	if (avaiable != 0) {
		if (!spawned) {
			m_pSprite->mPosition = Vec2(500, 500);
			spawned = true;
		}
		avaiable--;
	}
	else {
		spawned = false;
		m_pSprite->mPosition = Vec2(10000, 10000);
	}
}