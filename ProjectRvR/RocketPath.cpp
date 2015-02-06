#include "RocketPath.h"

RocketPath::RocketPath(int lower, int upper)
{
	int sum = 0;
	for(int i = lower; i < upper;i++)
	{
		xPositions.push_back(i);
	}

	currX = 0;
	currY = 0;

	xMin = lower;
	xMax = upper;
}

//getX i followPath se pozivaju u petlji pa imaju tu proveru da ne izadju iz opsega
//vektora znaci na svaki refresh ekrana ove 2 fije ce se pozivati

double RocketPath::getX()
{
	if(currX < xMax && currY < xMax)
	  return xPositions.at(currX);

	return 0;
}

void RocketPath::followPath(sf::CircleShape* rocket, double x, double y)
{
	if(currX < xMax && currY < xMax)
		rocket->setPosition((float) x, (float) y);

	currX++;
	currY++;
}