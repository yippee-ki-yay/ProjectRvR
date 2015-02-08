#ifndef _ROCKET_H
#define _ROCKET_H

#include <SFML/Graphics.hpp>

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
		sf::CircleShape shape;
		float fun[3];				//funkcija po kojoj se rakete krecu
		float x, y;				//koordinate rakete
		void setFun(float c1, float c2, float c3);
		struct Point{int x; int y;};
		std::vector<Point> points;

	public:

		Rocket();

		float getX() { return x; }
		float getY() { return y; }

		bool getActive(){return active;}
		void setActive(bool ac){active = ac;}

		void savePoint(int x, int y);
		float getPointX(int i){return points[i].x;}
		float getPointY(int i){return points[i].y;}
		int numPoints(){return points.size();}

		void reset(){x = 400; y = 0; active = false;}

		void move();
		sf::CircleShape getShape();
		void setStatus(bool s);
		void linterpFun(float *x, float* y);
};

#endif