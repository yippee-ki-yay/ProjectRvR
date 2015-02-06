#include "DefenseBase.h"

DefenseBase::DefenseBase()
{
	zgrada.setSize(sf::Vector2f(150, 70));
	zgrada.setPosition(0, 530);
	zgrada.setFillColor(sf::Color::Red);
}


void DefenseBase::draw(sf::RenderWindow* window)
{
	window->draw(zgrada);
}