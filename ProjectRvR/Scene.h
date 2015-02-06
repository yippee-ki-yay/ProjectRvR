#ifndef _SCENE_H
#define _SCENE_H

#include <string>
#include <SFML/Window.hpp>

#include "RocketManager.h"

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

};


#endif