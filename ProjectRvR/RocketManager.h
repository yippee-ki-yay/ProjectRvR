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

	bool collision(sf::Sprite a, sf::Sprite b);

	sf::Vector2f rotatedPoint(float x, float y, double angle);

	Rocket* getRocketAt(float x);				//vraca raketu u tacki

	bool hasRocketsAt(float x);				//da li ima raketu u tacki

	Rocket* getRockets() { return rockets; }

	sf::Vector2f projection(sf::Vector2f point, sf::Vector2f axis);

	float MinValue(float a, float b, float c, float d);

	float MaxValue(float a, float b, float c, float d);

	void checkCollision();

	//sf::Texture* getTexture() { return &img; }


private:
	static const int MAX_ROCKETS = 60;  //max number of rockets on screen
	Rocket rockets[MAX_ROCKETS]; 
	bool outOfRockets;
	//sf::Texture img;
};


#endif