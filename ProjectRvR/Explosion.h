#ifndef _EXPLOSION_H
#define _EXPLOSION_H

#include <iostream>
#include <SFML/Graphics.hpp>

class Explosion 
{
public:
	Explosion();

	void draw(sf::RenderWindow* window);

	void start();

	void reset();

private:
	sf::Texture t;
	sf::Sprite sprite;
	sf::Clock c;
	int i;
	bool m_start;
};

#endif