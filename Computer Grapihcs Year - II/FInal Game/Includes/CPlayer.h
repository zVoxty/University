
#ifndef _CPLAYER_H_
#define _CPLAYER_H_
#include "Main.h"
#include "Sprite.h"
#include "MovingObject.h"
#include <deque>
#include "Lives.h"

#define NUMBER_OF_LIVES 3


class CPlayer:public MovingObject
{
public:
		enum DIRECTION 
	{ 
		DIR_FORWARD	 = 1, 
		DIR_BACKWARD	= 2, 
		DIR_LEFT		= 4, 
		DIR_RIGHT	   = 8, 
	};

	enum ESpeedStates
	{
		SPEED_START,
		SPEED_STOP
	};
	CPlayer(const BackBuffer *pBackBuffer, const char * Path, int offset);
	virtual ~CPlayer();
	void					Move(ULONG ulDirection);
	
	void					Update(float dt);

	void                    Explode();
	bool					AdvanceExplosion();
	void					Draw();
	Sprite*					getSprite() { return m_pSprite; }
	Sprite*					setSprite(Sprite * sprite) { m_pSprite = sprite; }
	std::deque<Lives*>      getLives() { return m_pPlayerLives; }
private:
	ESpeedStates			m_eSpeedState;

	bool					m_bExplosion;
	bool					m_isExploding;
	AnimatedSprite*			m_pExplosionSprite;
	int						m_iExplosionFrame;
	std::deque<Lives*>		m_pPlayerLives;
};

#endif 