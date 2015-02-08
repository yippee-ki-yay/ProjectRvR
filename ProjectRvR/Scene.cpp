#include "Scene.h"
#include "Rocket.h"
#include <iostream>


Scene::Scene(int width, int height, std::string title)
{
	window = new sf::RenderWindow(sf::VideoMode(width, height), title);
	event = new sf::Event;

	window->setFramerateLimit(60);  //uvek da je 60fps moze da se promeni kasnije

	testPath = new RocketPath(0, 600); //ovo je u sustini x vrednost funkcije 0..600

	srand(time(NULL));

	pressed = false;
}

Scene::~Scene()
{
	delete window;
	delete event;
}

bool Scene::isActive()
{
	return window->isOpen();
}

void Scene::update()
{
	while(window->pollEvent(*event))
	{
		if(event->type == sf::Event::Closed)
			window->close();

		if (event->type == sf::Event::KeyPressed)
		{
			if(event->key.code == sf::Keyboard::Space)
			{
				if(manager.hasRockets())
				{
					Rocket* r = manager.getRocket();
					float x[3] = {400, 0, -400};
					float y[3] = {300, -150, -300};

					x[1] = rand()%200 - 100;
					y[1] = rand()%200 - 100;

					r->linterpFun(x, y);
					pressed = true;
				}
				
			}
		}
  
	}

	base.checkFirstWall(manager);
	base.gatherPoints(manager);

	window->clear();

	/** TEST DEO KODA OKO KRETANJA */

	base.draw(window);
	manager.draw(window);  //crta rakete
	manager.checkBounds();


	//window->draw(r1.getShape());

	window->display();
}