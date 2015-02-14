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

	bool getState(){return m_start;}
	void setState(bool s){m_start = s;}

	void setPos(float x, float y){sprite.setPosition(x, y);};

private:
	sf::Texture t;
	sf::Sprite sprite;
	sf::Clock c;
	int i;
	bool m_start;
	bool active;
};

#endif