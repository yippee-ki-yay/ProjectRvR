#include "Scene.h"
#include "Rocket.h"
#include <iostream>
#include "util.h"

Scene::Scene(int width, int height, std::string title)
{
	window = new sf::RenderWindow(sf::VideoMode(width, height), title);
	event = new sf::Event;

	window->setFramerateLimit(20);  //uvek da je 60fps moze da se promeni kasnije
	window->setKeyRepeatEnabled(false);

	testPath = new RocketPath(0, 600); //ovo je u sustini x vrednost funkcije 0..600

	srand(time(NULL));

	teksture.loadFromFile("rocket3.jpg");

	prvi.setTexture(teksture);
	drugi.setTexture(teksture);

	prvi.setPosition(100, 100);

	drugi.setPosition(400, 100);

	prvi.setRotation(-90);
	drugi.setRotation(-90);

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
					Rocket* r = manager.getRocket(RocketManager::ATTACK);
					float x[3] = {400, 0, -400};
					float y[3] = {-300, -150, -300};

					x[1] = rand()%200 - 100;
					y[1] = rand()%600 - 300;

					interpolation(x, y, r->getFun());

					e.start();

				}
				
			}
		}
  
	}

	window->clear();

	base.checkFirstWall(&manager);
	base.gatherPoints(&manager);

	/** TEST DEO KODA OKO KRETANJA */

	base.draw(window);
	manager.draw(window);  //crta rakete
	manager.checkBounds();

	e.draw(window);

	prvi.setPosition(prvi.getPosition().x+5, prvi.getPosition().y);

		window->draw(prvi);
	window->draw(drugi);

	if(manager.collision(window, prvi, drugi)){
	prvi.setPosition(100, 100);

		prvi.setRotation(rot);
	drugi.setRotation(rot);

	rot += 20;

	drugi.setPosition(400, 100);}

	if(prvi.getPosition().x > 500)
	{
		prvi.setPosition(100, 100);
				prvi.setRotation(rot);
	drugi.setRotation(rot);

	rot += 20;
	}

	window->display();

	sf::Time t = clock.getElapsedTime();
	clock.restart().asSeconds();

}