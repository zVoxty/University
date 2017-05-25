
#include "CPlayer.h"
#include "CGameApp.h"

extern int score;

//-----------------------------------------------------------------------------
// Name : CPlayer () (Constructor)
// Desc : CPlayer Class Constructor
//-----------------------------------------------------------------------------
CPlayer::CPlayer(const BackBuffer *pBackBuffer, const char * imagePath, int offset)
{
	//m_pSprite = new Sprite("data/planeimg.bmp", "data/planemask.bmp");
	m_pSprite = new Sprite(imagePath, RGB(0xff,0x00, 0xff));
	m_pSprite->setBackBuffer( pBackBuffer );
	m_eSpeedState = SPEED_STOP;
	m_fTimer = 0;
	
	m_pBackBuffer = pBackBuffer;
	m_eSpeedState = SPEED_STOP;
	m_fTimer = 0;
	m_isExploding = false;
	// Animation frame crop rectangle
	RECT r;
	r.left = 0;
	r.top = 0;
	r.right = 128;
	r.bottom = 128;

	m_pExplosionSprite = new AnimatedSprite("data/explosion.bmp", "data/explosionmask.bmp", r, 16);
	m_pExplosionSprite->setBackBuffer(pBackBuffer);
	m_bExplosion = false;
	m_iExplosionFrame = 0;

	for (int i = 0; i < NUMBER_OF_LIVES; i++) 
	{
		m_pPlayerLives.push_front(new Lives(pBackBuffer));
		m_pPlayerLives[0]->Position() = Vec2((i + 1) * 50, 25 + offset);
	}
}

//-----------------------------------------------------------------------------
// Name : ~CPlayer () (Destructor)
// Desc : CPlayer Class Destructor
//-----------------------------------------------------------------------------
CPlayer::~CPlayer()
{
	delete m_pSprite;
	if (m_pPlayerLives.size() != 0)
	{
		for (int i = 0; i < m_pPlayerLives.size(); i++)
		{
			delete m_pPlayerLives[i];
		}
	}

}

void CPlayer::Update(float dt)
{
	//if (m_pSprite->mPosition.x - m_pSprite->width() / 2 + m_pSprite->mVelocity.x * dt <= 0)
	//{
	//	m_pSprite->mPosition.x = m_pBackBuffer->width() - m_pSprite->width() / 2;
	//}

	////if (m_pSprite->mPosition.x + m_pSprite->width() / 2 + m_pSprite->mVelocity.x * dt >= m_pBackBuffer->width() )
	////{
	////	m_pSprite->mPosition.x = m_pSprite->width() / 2;
	////}

	//if (m_pSprite->mPosition.y - m_pSprite->height() / 2 + m_pSprite->mVelocity.y * dt <= 0)
	//{
	//	m_pSprite->mPosition.y = m_pBackBuffer->height()  - m_pSprite->height() / 2;
	//}

	//if (m_pSprite->mPosition.y + m_pSprite->height() / 2 + m_pSprite->mVelocity.y * dt >= m_pBackBuffer->height())
	//{
	//	m_pSprite->mPosition.y = m_pSprite->height() / 2;
	//}
	MovingObject::Update(dt);
	double v = m_pSprite->mVelocity.Magnitude();
	m_fTimer += dt;
	if (m_pPlayerLives.size() != 0)
	{
		for (int i = 0; i < m_pPlayerLives.size(); i++)
		{
			m_pPlayerLives[i]->Update(dt);
		}
	}
}

void CPlayer::Draw()
{
		MovingObject::Draw();

		if (!m_bExplosion)
		{
			m_pSprite->draw();
			if (m_pPlayerLives.size() != 0)
			{
				for (int i = 0; i < m_pPlayerLives.size(); i++)
				{
					m_pPlayerLives[i]->Draw();
				}
			}
		}
		else
		{
			m_pExplosionSprite->draw();
			if (m_pPlayerLives.size() != 0)
			{
				for (int i = 0; i < m_pPlayerLives.size(); i++)
				{
					m_pPlayerLives[i]->Draw();
				}
			}
		}
}
void CPlayer::Move(ULONG ulDirection)
{
	USHORT			Width = (int)GetSystemMetrics(SM_CXSCREEN);
	USHORT			Height = (int)GetSystemMetrics(SM_CYSCREEN);

	if (ulDirection & CPlayer::DIR_LEFT)
		m_pSprite->mVelocity.x -= 7;
	if (ulDirection & CPlayer::DIR_RIGHT)
		m_pSprite->mVelocity.x += 7;

	if (ulDirection & CPlayer::DIR_FORWARD) {
		m_pSprite->mVelocity.y -= 7;
	}
	if (ulDirection & CPlayer::DIR_BACKWARD)
		m_pSprite->mVelocity.y += 7;

}
void CPlayer::Explode()
{
	if (m_pPlayerLives.size() != 0)
	{
		m_pPlayerLives.pop_front();
	}
	Velocity() = Vec2(0, 0);
	m_pExplosionSprite->mPosition = m_pSprite->mPosition;
	//m_pExplosionSprite->SetFrame(0);
	PlaySound("data/explosion.wav", NULL, SND_FILENAME | SND_ASYNC);
	//m_bExplosion = true;
	//m_isExploding = true;

}

bool CPlayer::AdvanceExplosion()
{
	if (m_bExplosion)
	{
		m_pExplosionSprite->SetFrame(m_iExplosionFrame++);
		if (m_iExplosionFrame == m_pExplosionSprite->GetFrameCount())
		{
			m_bExplosion = false;
			m_isExploding = false;
			m_iExplosionFrame = 0;
			m_pSprite->mVelocity = Vec2(0, 0);
			m_eSpeedState = SPEED_STOP;
			return false;
		}
	}

	return true;
}