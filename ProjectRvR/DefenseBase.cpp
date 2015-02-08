#include "DefenseBase.h"

DefenseBase::DefenseBase()
{
	zgrada.setSize(sf::Vector2f(150, 70));
	zgrada.setPosition(0, 530);
	zgrada.setFillColor(sf::Color::Red);

	detectionLine.setSize(sf::Vector2f(800, 2));
	detectionLine.setPosition(600, 0);
	detectionLine.setRotation(90);
	detectionLine.setFillColor(sf::Color::Green);

	collisionLine.setSize(sf::Vector2f(800, 2));
	collisionLine.setPosition(200, 0);
	collisionLine.setRotation(90);
	collisionLine.setFillColor(sf::Color::White);
}


void DefenseBase::draw(sf::RenderWindow* window)
{
	window->draw(zgrada);
	window->draw(detectionLine);
	window->draw(collisionLine);
}

void DefenseBase::checkFirstWall(RocketManager rockets)
{
	if(rockets.hasRocketsAt(detectionLine.getPosition().x))
	{
		Rocket* r = rockets.getRocketAt((detectionLine.getPosition().x));
		DetectedRocket dr(r);
		det_rockets.push_back(dr);
		std::cout << "Detected rocket" << std::endl;
	}
}

void DefenseBase::gatherPoints(RocketManager rockets)
{
	for(unsigned int i = 0; i < det_rockets.size(); i++)		//za svaku raketu, uzimamo sledecu tacku
		{

			float x = (*det_rockets[i].getRocket()).getShape().getPosition().x;	//uzmemo raketu i poziciju(x)
			float y = (*det_rockets[i].getRocket()).getShape().getPosition().y;	//uzmemo raketu i poziciju(y)
			det_rockets[i].setPoint(x, y, det_rockets[i].getCurrent());			//postavimo poziciju
			det_rockets[i].moveToNextPoint();			//pomerimo pokazivac 

			if(det_rockets[i].getCurrent() == 3)
			{
				//imamo tri tacke, treba da izbacimo tu raketu iz vektora i racunamo putanju odbrambene rakete
				Rocket* r = rockets.getRocket();
				float* x = det_rockets[i].getX();
				float* y = det_rockets[i].getY();

				for(int i = 0; i < 3; ++i)
				{
					std::cout<<x[i]<<" ";
					std::cout<<y[i]<<std::endl;
				}

				r->linterpFun(x, y);

				det_rockets.pop_back();
			}

		}
}