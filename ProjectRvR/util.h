#ifndef _UTIL_H
#define _UTIL_H

#include <iostream>
#include "Rocket.h"
#include "math.h"

void interpolation(float* x, float* y, float* fun);

void linearFunc(float x1, float x2, float y1, float y2, float* fun);

//void checkColl(RocketManager* defR, RocketManager* ofR, sf::RenderWindow* window, ExplosionManager* exp);


#endif