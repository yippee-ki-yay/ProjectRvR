#include "RocketManager.h"

RocketManager::RocketManager()
{
	for(int i = 0; i < MAX_ROCKETS; ++i)
	{
		//rockets[i].setTexture((*this).getTexture());			//postavljanje slike na svaku raketu
		//rockets[i].getShape().setRadius(20);
		//rockets[i].getShape().setFillColor(sf::Color::Red);
		//rockets[i].getShape().setPosition(100+i*10, 100);
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
			window->draw(rockets[i].getSprite());
			rockets[i].move();

		}
	}
}

Rocket* RocketManager::getRocket(RocketManager::Type t)
{
	//nadjes prvi koji je neaktivan i vratis ga nazad
	//TODO: test kod za sada vraca samo prvu raketu
	for(int i = 0; i < MAX_ROCKETS; ++i)
	{
		if(rockets[i].getActive() == false)
		{
			//if(t == RocketManager::ATTACK)
				//rockets[i].setImage("rocket.png");
			//else
				rockets[i].setImage("rocket.png");
				rockets[i].setType(t);
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

void RocketManager::checkBounds()
{
	for(int i = 0; i < MAX_ROCKETS; ++i)
	{
		if(rockets[i].getActive() == true)
		{
			sf::Vector2f pos = rockets[i].getShape().getPosition();

			if(pos.x < 0 || pos.x > 800 || pos.y > 600 || pos.y < 0)
			{
				rockets[i].reset();
			}
		}
	}

}

bool RocketManager::hasRocketsAt(float x)
{
	for(int i = 0; i < MAX_ROCKETS; i++)
	{
		if(rockets[i].getShape().getPosition().x == x && (rockets[i].getType() == 0))
			return true;
	}

	return false;
}

Rocket* RocketManager::getRocketAt(float x)
{
	for(int i = 0; i < MAX_ROCKETS; i++)
	{
		if(rockets[i].getShape().getPosition().x == x)					//TODO: izmeniti da raketa ima metodu getPosition(), da se ne poziva preko shape-a
			return &rockets[i];
	}
	return NULL;
}
