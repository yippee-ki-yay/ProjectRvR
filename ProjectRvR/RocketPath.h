#ifndef _ROCKET_PATH_H
#define _ROCKET_PATH_H

#include <vector>
#include <SFML/Graphics.hpp>

/**
	Klasa koja je zaduzena da pomera raketu po nekoj zadatoj funkciji,
	tek ima samo neke osnovne funkcionalnosti

	Slobodno preradi ovu klasu (ovo je samo kao neki test skelet)
*/

class RocketPath
{
public:
	RocketPath(int lower, int upper); //specifiramo odakle dokle ide x vrednost

	void followPath(sf::CircleShape* rocket, double x, double y); //pomera raketu po putanji

	double getX(); //vraca trenutnu x vrednost

private:
	std::vector<double> xPositions; //pamtimo sve x vrednosti
	int currX, currY;
	int xMax, xMin;
};

#endif