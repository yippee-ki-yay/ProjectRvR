#ifndef _SCENE_H
#define _SCENE_H

#include <string>
#include <SFML/Window.hpp>

class Scene
{
public:
	Scene(int width, int height, std::string title);

	~Scene();
	
	bool isActive();

	void update();

private:
	sf::Window* window;
	sf::Event* event;

};


#endif