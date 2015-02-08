#ifndef _SCENE_H
#define _SCENE_H

#include <string>
#include <SFML/Window.hpp>

#include "RocketManager.h"
#include "RocketPath.h"
#include "Rocket.h"
#include "DefenseBase.h"

class Scene
{
public:
	Scene(int width, int height, std::string title);

	~Scene();
	
	bool isActive();

	void update();

private:
	sf::RenderWindow* window;
	sf::Event* event;
	RocketManager manager;
	DefenseBase base;
	RocketPath* testPath;
	Rocket* r1;

	sf::Clock clock;
	sf::Text text;

	bool pressed;
};


#endif