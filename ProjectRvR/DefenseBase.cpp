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
	collisionLine.setPosition(150, 0);
	collisionLine.setRotation(90);
	collisionLine.setFillColor(sf::Color::White);

}


void DefenseBase::draw(sf::RenderWindow* window)
{
	window->draw(zgrada);
	window->draw(detectionLine);
	window->draw(collisionLine);
}

void DefenseBase::checkFirstWall(RocketManager* rockets)
{
	if(rockets->hasRocketsAt(detectionLine.getPosition().x))
	{
		Rocket* r = rockets->getRocketAt((detectionLine.getPosition().x));
		det_rockets.push_back(r);
	//	std::cout << "Detected rocket" << std::endl;
	}
}

void DefenseBase::gatherPoints(RocketManager* rockets)
{
	//GRESKA je sto kad izbacimo iz vektora smanji se velicina
	for(unsigned int i = 0; i < det_rockets.size(); i++)
	{
	    //Zbog trenutne interpolacije koja radi sa tri tacke uzimamo x,y poz na 3 mesta

		//pozicija tacaka je izabrana nasumicno, cisto da ima dovoljno udaljene tacke
		//da precizno opise funkciju

		if(det_rockets[i]->getType() == 0)
		{
			if(det_rockets[i]->getShape().getPosition().x == 500)
			{
				det_rockets[i]->setPoint(det_rockets[i]->getShape().getPosition());
			}

			if(det_rockets[i]->getShape().getPosition().x == 400)
			{
				det_rockets[i]->setPoint(det_rockets[i]->getShape().getPosition());
				//std::cout<<"Dodao\n";
			}
			

			if(det_rockets[i]->getShape().getPosition().x == 300)  
			{
				det_rockets[i]->setPoint(det_rockets[i]->getShape().getPosition());
				//std::cout<<"Dodao\n";
			}

			if(det_rockets[i]->getCount() == 3)
			{
				/*
				Rocket *r = rockets->getRocket(RocketManager::DEFENSE);
				float tmp[3];		//funkcija napadacke rakete

				//treba nam niz tacaka za onaj algo. interpolacije pa to ovde popunjavamo
				float x[3], y[3];
				for(int j = 0; j < 3; ++j)
				{
					x[j] = det_rockets[i]->points[j].x - 400;	//transliramo u nas koordinatni sistem za racunanje pozicije
					y[j] = det_rockets[i]->points[j].y - 300;	//PONETI PAPIR SA KOORDINATNIM SISTEMOM
				}

				interpolation(x, y, tmp);		//sacuvamo putanju detektovane rakete u tmp

				float startX = -400;			//raketa krece iz tacke(-400, -300)
				float startY = -300;
				float targetX = -400 + collisionLine.getPosition().x;	//pozicija prave na kojoj gadjamo
				float targetY = tmp[0]*targetX*targetX + tmp[1]*targetX + tmp[2];//vrednost putanje detektovane rakete u toj tacki
				float midX = (startX + targetX)/2;	//damo tacku izmedju, da se krece po linearnoj funkciji
				float midY = (startY + targetY)/2;

				float x1[3];
				float y1[3];

				x1[0] = startX; x1[1] = midX; x1[2] = targetX;	//postavimo vrednosti za interpolaciju
				y1[0] = startY; y1[1] = midY; y1[2] = targetY;	

				interpolation(x1, y1, r->getFun());	//izracunamo linearnu funkciju po kojoj se krece, i ubacimo u odbrambenu raketu
				//r->setType(1);

				r->setX(-400);	//postavljanje zbog crtanja, krece iz baze
				r->setY(-300);
				*/

				setTarget(rockets, i);
			
				//izbacimo detektovanu raketu iz liste
				det_rockets.erase(det_rockets.begin()+i);
			}
		}

	}
	
	
}

void DefenseBase::setTarget(RocketManager* rockets, int i)
{
	//uzmi odgavarajuci niz tacaka
	//uradi interpolaciju
	//dobijemo funkciju
	//izracunamo funkciju u tacki 
	//posaljemo raketu u toj tacki

		Rocket *r = rockets->getRocket(RocketManager::DEFENSE);
		float tmp[3];		//funkcija napadacke rakete

		//treba nam niz tacaka za onaj algo. interpolacije pa to ovde popunjavamo
		float x[3], y[3];
		for(int j = 0; j < 3; ++j)
		{
			x[j] = det_rockets[i]->points[j].x - 400;	//transliramo u nas koordinatni sistem za racunanje pozicije
			y[j] = det_rockets[i]->points[j].y - 300;	//PONETI PAPIR SA KOORDINATNIM SISTEMOM
		}

		interpolation(x, y, tmp);		//sacuvamo putanju detektovane rakete u tmp

		float startX = -400;			//raketa krece iz tacke(-400, -300)
		float startY = -300;
		float targetX = -400 + collisionLine.getPosition().x;	//pozicija prave na kojoj gadjamo
		float targetY = tmp[0]*targetX*targetX + tmp[1]*targetX + tmp[2];//vrednost putanje detektovane rakete u toj tacki
		float midX = (startX + targetX)/2;	//damo tacku izmedju, da se krece po linearnoj funkciji
		float midY = (startY + targetY)/2;

		float x1[3];
		float y1[3];

		x1[0] = startX; x1[1] = midX; x1[2] = targetX;	//postavimo vrednosti za interpolaciju
		y1[0] = startY; y1[1] = midY; y1[2] = targetY;	

		interpolation(x1, y1, r->getFun());	//izracunamo linearnu funkciju po kojoj se krece, i ubacimo u odbrambenu raketu
		//r->setType(1);

		r->setX(-400);	//postavljanje zbog crtanja, krece iz baze
		r->setY(-300);

}