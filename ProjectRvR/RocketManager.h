#ifndef _ROCKET_MANAGER_H
#define _ROCKET_MANAGER_H

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

	Rocket* getRocket();
	void draw(sf::RenderWindow*);

	bool hasRockets();

	void checkBounds();

	Rocket* getRocketAt(float x);				//vraca raketu u tacki

	bool hasRocketsAt(float x);				//da li ima raketu u tacki

	Rocket* getRockets() { return rockets; }

private:
	static const int MAX_ROCKETS = 60;  //max number of rockets on screen
	Rocket rockets[MAX_ROCKETS]; 
	bool outOfRockets;
};


#endif