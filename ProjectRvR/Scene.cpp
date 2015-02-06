#include "Scene.h"
#include "Rocket.h"
#include <iostream>

Scene::Scene(int width, int height, std::string title)
{
	window = new sf::RenderWindow(sf::VideoMode(width, height), title);
	event = new sf::Event;

	window->setFramerateLimit(60);  //uvek da je 60fps moze da se promeni kasnije

	testPath = new RocketPath(0, 600); //ovo je u sustini x vrednost funkcije 0..600

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
					r->setFun(0.001, 0, 0);
					pressed = true;
				}
				
			}
		}
  
	}

	window->clear();

	/** TEST DEO KODA OKO KRETANJA */


	manager.draw(window);  //crta rakete
	base.draw(window);


	//window->draw(r1.getShape());

	window->display();
}