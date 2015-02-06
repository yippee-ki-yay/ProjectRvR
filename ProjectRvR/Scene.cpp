#include "Scene.h"

Scene::Scene(int width, int height, std::string title)
{
	window = new sf::RenderWindow(sf::VideoMode(width, height), title);
	event = new sf::Event;

	window->setFramerateLimit(60);  //uvek da je 60fps moze da se promeni kasnije

	testPath = new RocketPath(0, 600); //ovo je u sustini x vrednost funkcije 0..600
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
	}

	window->clear();

	/** TEST DEO KODA OKO KRETANJA */

	sf::CircleShape* rocket = manager.getRocket();  //uzmemo prvu slobodnu raketu

	double x = testPath->getX(); //trenutna x vrednost putanje

	//obicno linearno kretanje, mogu i druge fije samo moram da izvalim kako pravilno da ih skaliram
	double y = x; 

	testPath->followPath(rocket, x, y); //nakacis raketu i x, y putanju koju ce ona pratiti

	manager.draw(window);  //crta rakete

	window->display();
}