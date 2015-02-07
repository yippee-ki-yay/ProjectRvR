#ifndef _DEFENSE_BASE_H
#define _DEFENSE_BASE_H

/**
	Klasa koja kontrolise odbranu, ispaljuje rakete koje presrecu,
	racuna putanje i te kolizije i gluposti
*/

#include <SFML/Graphics.hpp>

class DefenseBase
{
public:
	DefenseBase();

	void draw(sf::RenderWindow* winodw);

private:
	sf::RectangleShape zgrada;
	//Line su rectangle shape da bi mogli da imaju i width ako treba
	sf::RectangleShape detectionLine;
	sf::RectangleShape collisionLine;
};


#endif