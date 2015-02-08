#ifndef _DEFENSE_BASE_H
#define _DEFENSE_BASE_H

/**
	Klasa koja kontrolise odbranu, ispaljuje rakete koje presrecu,
	racuna putanje i te kolizije i gluposti
*/

#include <SFML/Graphics.hpp>
#include "RocketManager.h"
#include "DetectedRocket.h"
#include <iostream>
#include <vector>

class DefenseBase
{
public:
	DefenseBase();

	void draw(sf::RenderWindow* winodw);

	void checkFirstWall(RocketManager rockets);	

	void gatherPoints(RocketManager rockets);


private:
	sf::RectangleShape zgrada;
	//Line su rectangle shape da bi mogli da imaju i width ako treba
	sf::RectangleShape detectionLine;
	sf::RectangleShape collisionLine;
	std::vector<Rocket*> det_rockets;
	int count;
	struct Point{int x; int y;};
	std::vector<Point> points;

	void setPoint(sf::Vector2f v);
};


#endif