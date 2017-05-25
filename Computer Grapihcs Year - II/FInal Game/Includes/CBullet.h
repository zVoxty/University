
#ifndef _CBULLET_H_
#define _CBULLET_H_

#include "Main.h"
#include "Sprite.h"
#include "MovingObject.h"

class CBullet:public MovingObject
{
public:
		CBullet(const BackBuffer *pBackBuffer);
	virtual ~CBullet();

	float get_Damage() const { return damage;}

	// Public functions
private:
	float damage;

};



#endif