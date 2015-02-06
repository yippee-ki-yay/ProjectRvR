#include "RocketManager.h"

RocketManager::RocketManager()
{
	for(int i = 0; i < MAX_ROCKETS; ++i)
	{
		rockets[i].setRadius(20);
		rockets[i].setFillColor(sf::Color::Red);
		rockets[i].setPosition(100+i*10, 100);
	}
}

void RocketManager::draw(sf::RenderWindow* window)
{
	//TODO: test kod za sada crta samo jednu raketu
	//for(int i = 0; i < MAX_ROCKETS; ++i)
	{
		window->draw(rockets[0]);
	}
}

sf::CircleShape* RocketManager::getRocket()
{
	//nadjes prvi koji je neaktivan i vratis ga nazad
	//TODO: test kod za sada vraca samo prvu raketu
	return &(rockets[0]);
}