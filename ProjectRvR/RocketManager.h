#ifndef _ROCKET_MANAGER_H
#define _ROCKET_MANAGER_H

#include <iostream>
#include <SFML/Graphics.hpp>
#include "Rocket.h"

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

	Rocket* getRocketAt(float x);				//vraca raketu u tacki

	bool hasRocketsAt(float x);				//da li ima raketu u tacki

	Rocket* getRockets() { return rockets; }

	void checkCollision(sf::RenderWindow* w);

	void getBoundingPoints(sf::Sprite& sprite, sf::Vector2f* niz);

	void ProjectOnAxis(sf::Vector2f* points, sf::Vector2f axis, float& min, float& max);



private:
	static const int MAX_ROCKETS = 60;  //max number of rockets on screen
	Rocket rockets[MAX_ROCKETS]; 
	bool outOfRockets;
	//sf::Texture img;
};


#endif