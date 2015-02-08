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

	count = 0;
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
		det_rockets.push_back(r);
		std::cout << "Detected rocket" << std::endl;
	}
}

void DefenseBase::gatherPoints(RocketManager rockets)
{
	for(unsigned int i = 0; i < det_rockets.size(); i++)
	{
	    //Zbog trenutne interpolacije koja radi sa tri tacke uzimamo x,y poz na 3 mesta

		//pozicija tacaka je izabrana nasumicno, cisto da ima dovoljno udaljene tacke
		//da precizno opise funkciju

		//GRESKA: raketa mi ne vraca dobro svoje pozicije zasto?

		if(det_rockets[i]->getShape().getPosition().x == 500)
		{
			setPoint(det_rockets[i]->getShape().getPosition());
			std::cout<<"Dodao\n";
		}

		if(det_rockets[i]->getShape().getPosition().x == 400)
		{
			setPoint(det_rockets[i]->getShape().getPosition());
			std::cout<<"Dodao\n";
		}
			

		if(det_rockets[i]->getShape().getPosition().x == 300)
		{
			setPoint(det_rockets[i]->getShape().getPosition());
			std::cout<<"Dodao\n";
		}

		if(count == 3)
		{

			//treba nam niz tacaka za onaj algo. interpolacije pa to ovde popunjavamo
			float x[3], y[3];
			for(int j = 0; j < 3; ++j)
			{
				x[j] = points[j].x;
				y[j] = points[j].y;
				std::cout<<x[j]<<" "<<y[j]<<std::endl;
			}

			//na osnovu ovih tacaka treba da se uradi interpolacija
			//i da se dobije funkcija, pa mozemo da nadjemo gde se sece sa pravom
			det_rockets.pop_back();
			points.clear();
			
			count = 0;
		}

	}
}

void DefenseBase::setPoint(sf::Vector2f v)
{
	Point p;
	p.x = v.x; p.y = v.y;
	points.push_back(p);
	count++;
}