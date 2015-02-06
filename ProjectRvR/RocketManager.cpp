#include "RocketManager.h"

RocketManager::RocketManager()
{
	for(int i = 0; i < MAX_ROCKETS; ++i)
	{
		rockets[i].getShape().setRadius(20);
		rockets[i].getShape().setFillColor(sf::Color::Red);
		rockets[i].getShape().setPosition(100+i*10, 100);
	}

	outOfRockets = false;
}

void RocketManager::draw(sf::RenderWindow* window)
{
	//TODO: test kod za sada crta samo jednu raketu
	for(int i = 0; i < MAX_ROCKETS; ++i)
	{
		if(rockets[i].getActive() == true)
		{
			window->draw(rockets[i].getShape());
			rockets[i].move();
		}
	}
}

Rocket* RocketManager::getRocket()
{
	//nadjes prvi koji je neaktivan i vratis ga nazad
	//TODO: test kod za sada vraca samo prvu raketu
	for(int i = 0; i < MAX_ROCKETS; ++i)
	{
		if(rockets[i].getActive() == false)
		{
			rockets[i].setActive(true);
			return &(rockets[i]);
		}
	}
	
}

bool RocketManager::hasRockets()
{
	for(int i = 0; i < MAX_ROCKETS; ++i)
	{
		if(rockets[i].getActive() == false)
			return true;
	}

	return false;
}