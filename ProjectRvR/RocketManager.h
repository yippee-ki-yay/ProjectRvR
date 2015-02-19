#ifndef _ROCKET_MANAGER_H
#define _ROCKET_MANAGER_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Rocket.h"
#include "ExplosionManager.h"

/**
	Klasa koja napravi X broj raketa, koje se trenutno nalaze na ekranu
	i reciklira te raketa, ima jednu instancu u Scene.h i preko getRocket()
	dobijemo pokazivac na prvu slobodnu raketu
*/

class RocketManager
{
public:
	RocketManager();

	enum Type{ATTACK, DEFENSE};

	Rocket* getRocket(RocketManager::Type t);
	void draw(sf::RenderWindow*);

	bool hasRockets();

	void checkBounds();

	bool collision(sf::RenderWindow* window, sf::Sprite& a, sf::Sprite& b);

	Rocket* getRocketAt(int x);				//vraca raketu u tacki

	bool hasRocketsAt(int x);				//da li ima raketu u tacki

	void detectRocket(int x, std::vector<Rocket*>* vec);

	Rocket* getRockets() { return rockets; }

	void checkCollision(sf::RenderWindow* w, ExplosionManager* manager, RocketManager* defrockets);

	void getBoundingPoints(sf::Sprite& sprite, sf::Vector2f* niz, sf::RenderWindow* w);

	void ProjectOnAxis(sf::Vector2f* points, sf::Vector2f axis, float& min, float& max);

	void printActive() 
	{
		int tmp = 0;
		for(int i = 0; i < MAX_ROCKETS; i++)
			if(rockets[i].getActive() == true)
				tmp++;
		std::cout << tmp << std::endl;

	}
	
private:
	static const int MAX_ROCKETS = 10;  //max number of rockets on screen
	Rocket rockets[MAX_ROCKETS]; 
	bool outOfRockets;
	//sf::Texture img;
};


#endif