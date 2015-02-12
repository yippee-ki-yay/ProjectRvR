#include <iostream>
#include "Rocket.h"

Rocket::Rocket()
{
	active = false;			//raketa nije aktivna prilikom stvaranja
	x = 400;				//pocetna tacka(400, 0) kada se translira(800, 300)
	y = 0;
	for(int i = 0; i < 3; i++)
	{
		fun[0] = 0;
	}
	shape.setFillColor(sf::Color::Blue);
	sf::Vector2f v;
	v.x = 20;
	v.y = 10;
	shape.setSize(v);
	shape.setPosition(-100, y);
	type = 0;
	//sprite.setTexture(*txt);
	ugao = 0;
}

void Rocket::move()		//pomeranje x-a i racunanje y-a
{
	//shape.setPosition(x, y);

	if(type == 0)
		x -= 10;							
	else
		x += 10;
	
	y = fun[0]*x*x + fun[1]*x + fun[2];

	rotate();
	shape.setPosition(x + 400, y + 300); //transliranje(centar(0, 0) je gornji levi ugao)
	sprite.setPosition(x + 400, y + 300);

}

void Rocket::setFun(float c1, float c2, float c3)
{
	fun[0] = c1;
	fun[1] = c2;
	fun[2] = c3;
}

sf::RectangleShape Rocket::getShape()
{
	return shape;
}

void Rocket::setStatus(bool s)
{
	active = s;
}

void Rocket::setTexture(sf::Texture* txt)
{
	sprite.setTexture(*txt);
}

void Rocket::rotate()
{
	float alpha;
	alpha = atan(fun[0]*x + fun[1]);					//arctg prvog izvoda funkcije u datoj tacki = ugao tangente
	
	alpha = alpha*180/3.14;

	if(type == 1)
		alpha = 180 + alpha;

	//std::cout << "alfa" << alpha << std::endl;
	ugao = alpha;
	sprite.setRotation(alpha);
	sprite.getTransform();
}

void Rocket::setImage(std::string name)
{
	if (texture.loadFromFile(name))
	{
		sprite.setTexture(texture);
	}
}

void Rocket::setPoint(sf::Vector2f v)
{
	Point p;
	p.x = v.x; p.y = v.y;
	points.push_back(p);
}

void Rocket::reset()
{
	active = false;			//raketa nije aktivna prilikom stvaranja
	x = 400;				//pocetna tacka(400, 0) kada se translira(800, 300)
	y = 0;
	for(int i = 0; i < 3; i++)
	{
		fun[0] = 0;
	}
	sf::Vector2f v;
	v.x = 20;
	v.y = 10;
	shape.setFillColor(sf::Color::Blue);
	shape.setSize(v);
	shape.setPosition(-100, y);
	type = 0;
	points.clear();
}
