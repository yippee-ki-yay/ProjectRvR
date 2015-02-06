#include "RocketManager.h"

RocketManager::RocketManager()
{
	for(int i = 0; i < MAX_ROCKETS; ++i)
	{
		rockets[i].setRadius(20);
		rockets[i].setFillColor(sf::Color::Red);
	}
}

void RocketManager::draw(sf::RenderWindow& window)
{
	for(int i = 0; i < MAX_ROCKETS; ++i)
	{
		window.draw(rockets[i]);
	}
}

sf::CircleShape& RocketManager::getRocket()
{
	//nadjes prvi koji je neaktivan i vratis ga nazad
	return rockets[0];
}