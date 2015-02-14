#include "Explosion.h"

Explosion::Explosion()
{
	t.loadFromFile("explosion.jpg");
	sprite.setTexture(t);
	sprite.setTextureRect(sf::IntRect(0, 0, 64, 64));
	sprite.setPosition(300, 300);
	i = 0;
	m_start = false;
}

void Explosion::draw(sf::RenderWindow* window)
{
	if(m_start == true)
	{
	sf::Time t = c.getElapsedTime();
	if(i < 576)
		if(t.asMilliseconds() > 50)
	{
		sprite.setTextureRect(sf::IntRect(i, 0, 64, 64));
		i += 64;
		c.restart();
	}

	if(i < 576)
		window->draw(sprite);
	else
	{
		m_start = false;
		Explosion::reset();
	}
	}
}

void Explosion::start()
{
	m_start = true;
}

void Explosion::reset()
{
	i = 0;
	m_start = false;
}