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

	void checkFirstWall(RocketManager rockets)								//TODO:			prebaciti u .cpp
	{
		if(rockets.hasRocketsAt(detectionLine.getPosition().x))
		{
			Rocket* r = rockets.getRocketAt((detectionLine.getPosition().x));
			DetectedRocket dr(r);
			det_rockets.push_back(dr);
			std::cout << "Detected rocket" << std::endl;
		}
	}

	void gatherPoints()
	{

		for(int i = 0; i < det_rockets.size(); i++)								//za svaku raketu, uzimamo sledecu tacku
		{

			int x = (*det_rockets[i].getRocket()).getShape().getPosition().x;			//uzmemo raketu i poziciju(x)
			int y = (*det_rockets[i].getRocket()).getShape().getPosition().y;			//uzmemo raketu i poziciju(y)
			det_rockets[i].setPoint(x, y, det_rockets[i].getCurrent());					//postavimo poziciju
			det_rockets[i].moveToNextPoint();											//pomerimo pokazivac 

			if(det_rockets[i].getCurrent() == 3)
			{
				//imamo tri tacke, treba da izbacimo tu raketu iz vektora i racunamo putanju odbrambene rakete
			}

		}

	}



private:
	sf::RectangleShape zgrada;
	//Line su rectangle shape da bi mogli da imaju i width ako treba
	sf::RectangleShape detectionLine;
	sf::RectangleShape collisionLine;
	std::vector<DetectedRocket> det_rockets;
};


#endif