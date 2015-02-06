#include "Scene.h"

Scene::Scene(int width, int height, std::string title)
{
	window = new sf::RenderWindow(sf::VideoMode(width, height), title);
	event = new sf::Event;

	window->setFramerateLimit(60);
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
	window->display();
}