#include "Rocket.h"
#include <iostream>

Rocket::Rocket()
{
	active = false;			//raketa nije aktivna prilikom stvaranja
	x = 300;				//pocetna tacka(300, 0) kada se translira(600, 300)
	y = 0;
	for(int i = 0; i < 3; i++)
	{
		fun[0] = 0;
	}
	shape.setFillColor(sf::Color::Blue);
	shape.setRadius(15);
	shape.setPosition(x, y);
}

void Rocket::move()		//pomeranje x-a i racunanje y-a
{
	x -= 1;							
	y = fun[0]*x*x + fun[1]*x + fun[2];

	//y = x*x/1000;

	shape.setPosition(x + 300, y + 300); //transliranje(centar(0, 0) je gornji levi ugao)

	//std::cout << y << "\n";

}

void Rocket::setFun(float c1, float c2, float c3)
{
	fun[0] = c1;
	fun[1] = c2;
	fun[2] = c3;
}

sf::CircleShape Rocket::getShape()
{
	return shape;
}

void Rocket::setStatus(bool s)
{
	active = s;
}







