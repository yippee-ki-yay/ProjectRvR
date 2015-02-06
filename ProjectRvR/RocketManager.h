#ifndef _ROCKET_MANAGER_H
#define _ROCKET_MANAGER_H

#include <SFML/Graphics.hpp>

/**
	Klasa koja napravi X broj raketa, koje se trenutno nalaze na ekranu
	i reciklira te raketa, ima jednu instancu u Scene.h i preko getRocket()
	dobijemo pokazivac na prvu slobodnu raketu
*/

class RocketManager
{
public:
	RocketManager();

	sf::CircleShape* getRocket();
	void draw(sf::RenderWindow*);
private:
	static const int MAX_ROCKETS = 20;  //max number of rockets on screen
	sf::CircleShape rockets[20]; //TODO: switch to Rocket class later
};


#endif