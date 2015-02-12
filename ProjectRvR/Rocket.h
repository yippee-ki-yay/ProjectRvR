#ifndef _ROCKET_H
#define _ROCKET_H

#include <SFML/Graphics.hpp>
#include "util.h"
#include "math.h"
/**
	Napravi ovu klasu dodaj da ima te podatke,
	mogucnost da menja izgled u zavisnosti koj tip rakete je,
	i napravi mi da ima neko polje bool active da znam da li je
	jos uvek na ekranu

	U klasama RocketPath i RocketManager sam koristo sf::CircleShape
	umesto toga kad napravis ubacis Rocket klasu i trebalo bi da radi

*/

class Rocket 
{

	private:
	
		bool active;
		sf::RectangleShape shape;
		float fun[3];				//funkcija po kojoj se rakete krecu
		float x, y;				//koordinate rakete
		int type;				//0 napad, 1 odbrana
		sf::Sprite sprite;
		sf::Texture texture;
		struct Point{int x; int y;};

	public:

		double ugao;

		Rocket();

		float getX() { return x; }		
		float getY() { return y; }
		void setX(float xx) { x = xx; }
		void setY(float yy) { y = yy; }

		float* getFun() { return fun; }
		void setFun(float c1, float c2, float c3);

		bool getActive(){return active;}
		void setActive(bool ac){active = ac;}

		int getType() { return type; }
		void setType(int t) { type = t; }

		sf::RectangleShape getShape();

		void setImage(std::string name);

		std::vector<Point> points;
		void setPoint(sf::Vector2f v);
		int getCount(){return points.size();}

		void move();
		void rotate();
		void reset();

		void setStatus(bool s);

		sf::Sprite getSprite() { return sprite; }

		void setTexture(sf::Texture*);

};

#endif