#include "ExplosionManager.h"

ExplosionManager::ExplosionManager()
{

}

void ExplosionManager::draw(sf::RenderWindow* window)
{
	for(int i = 0; i < MAX_EXPLOSIONS;++i)
	{
		if(explosions[i].getState() == true)
			explosions[i].draw(window);
	}
}

void ExplosionManager::setExplosion(float x, float y)
{
	for(int i = 0; i < MAX_EXPLOSIONS;++i)
	{
		if(explosions[i].getState() == false)
		{
			explosions[i].setPos(x, y);
			explosions[i].setState(true);
			return;
		}
	}
}