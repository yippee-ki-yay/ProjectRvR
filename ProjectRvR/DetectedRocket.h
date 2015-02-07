#ifndef _DETECTED_ROCKET_H
#define	_DETECTED_ROCKET_H

#include "Rocket.h"


class DetectedRocket
{

	private:

		Rocket *rocket;										//raketa koja je detektovana
		float point_x[3];									//njena pozicija, 3 tacke dovolje za kvadratnu funkciju
		float point_y[3];									//promeniti mozda u niz Point-ova, kao niz objekata te klase
		int current;

	public:

		DetectedRocket(Rocket *r) { rocket = r; current = 0; }

		void moveToNextPoint() { current++; }				//pokazuje nam koja je to tacka po redu koju smo zapamtili

		Rocket* getRocket() { return rocket; }

		float* getX() { return point_x; }					//bice nam potrebno za racunanje kasnije
		float* getY() { return point_y; }		

		int getCurrent() { return current; }

		void setPoint(float x, float y, int cnt)
		{
			point_x[cnt] = x;
			point_y[cnt] = y;
		}

};




#endif