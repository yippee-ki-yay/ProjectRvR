#ifndef _DEFENSE_BASE_H
#define _DEFENSE_BASE_H

/**
	Klasa koja kontrolise odbranu, ispaljuje rakete koje presrecu,
	racuna putanje i te kolizije i gluposti
*/

#include <SFML/Graphics.hpp>
#include "RocketManager.h"
#include "DetectedRocket.h"
#include "util.h"
#include <iostream>
#include <vector>

class DefenseBase
{
public:
	DefenseBase();

	void draw(sf::RenderWindow* winodw);

	void checkFirstWall(RocketManager* rockets);	

	void gatherPoints(RocketManager* rockets);


private:
	sf::RectangleShape zgrada;
	sf::RectangleShape detectionLine;
	sf::RectangleShape collisionLine;
	std::vector<Rocket*> det_rockets;
	int k;

	sf::Clock clock;

	void setTarget(RocketManager* rockets, int i);
};


#endif