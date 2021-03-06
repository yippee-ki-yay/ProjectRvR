#include "Scene.h"
#include "Rocket.h"
#include <iostream>
#include "util.h"

Scene::Scene(int width, int height, std::string title)
{
	window = new sf::RenderWindow(sf::VideoMode(width, height), title);
	event = new sf::Event;

	window->setFramerateLimit(30);  //uvek da je 30fps moze da se promeni kasnije
	window->setKeyRepeatEnabled(false);

	//testPath = new RocketPath(0, 600); //ovo je u sustini x vrednost funkcije 0..600

	srand(time(NULL));

	rot = 0;

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
					sf::Time t = fireClock.getElapsedTime();

					std::cout<<t.asMilliseconds()<<std::endl;

					if(t.asMilliseconds() >= 500)
					{
					std::cout << "DODAO NAPAD" << std::endl;
					Rocket* r = manager.getRocket(RocketManager::ATTACK);
					float x[3] = {400, 0, -400};
					float y[3] = {-300, -150, -300};

					x[1] = rand()%200 - 100;
					y[1] = rand()%500 - 250;

					interpolation(x, y, r->getFun());

					fireClock.restart();
					}

				}
				
			}
		}
  
	}

	window->clear();

	base.checkFirstWall(&manager);
	base.gatherPoints(&defManager);
	/** TEST DEO KODA OKO KRETANJA */

	explosions.draw(window);

	base.draw(window);

	manager.checkCollision(window, &explosions, &defManager);
	manager.draw(window);  //crta rakete
	defManager.draw(window);
	manager.checkBounds();
	//manager.printActive();

	window->display();

	sf::Time t = clock.getElapsedTime();
	clock.restart().asSeconds();

}