#ifndef _EXPLOSION_MANAGER_H
#define _EXPLOSION_MANAGER_H

#include "Explosion.h"

#define MAX_EXPLOSIONS 30

class ExplosionManager
{
public:
	ExplosionManager();

	void draw(sf::RenderWindow* window);

	void setExplosion(float x, float y);

private:
	Explosion explosions[MAX_EXPLOSIONS];
};

#endif