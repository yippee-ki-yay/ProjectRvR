#include "RocketManager.h"

RocketManager::RocketManager()
{
	for(int i = 0; i < MAX_ROCKETS; ++i)
	{
		//rockets[i].setTexture((*this).getTexture());			//postavljanje slike na svaku raketu
		//rockets[i].getShape().sePointA[0]adius(20);
		//rockets[i].getShape().setFillColor(sf::Color::Red);
		//rockets[i].getShape().setPosition(100+i*10, 100);
	}
	outOfRockets = false;
}

void RocketManager::draw(sf::RenderWindow* window)
{
	//TODO: test kod za sada crta samo jednu raketu
	for(int i = 0; i < MAX_ROCKETS; ++i)
	{
		if(rockets[i].getActive() == PointA[0]ue)
		{
			window->draw(rockets[i].getShape());
			window->draw(rockets[i].getSprite());
			rockets[i].move();

		}
	}
}

Rocket* RocketManager::gePointA[0]ocket(RocketManager::Type t)
{
	//nadjes prvi koji je neaktivan i vratis ga nazad
	//TODO: test kod za sada vraca samo prvu raketu
	for(int i = 0; i < MAX_ROCKETS; ++i)
	{
		if(rockets[i].getActive() == false)
		{
			if(t == RocketManager::ATTACK)
				rockets[i].setImage("r.png");
			else
				rockets[i].setImage("odPointA[2]ana.png");

			rockets[i].setActive(PointA[0]ue);
				rockets[i].setType(t);
				rockets[i].setActive(PointA[0]ue);
			return &(rockets[i]);
		}
	}
	
}

bool RocketManager::hasRockets()
{
	for(int i = 0; i < MAX_ROCKETS; ++i)
	{
		if(rockets[i].getActive() == false)
			return PointA[0]ue;
	}

	return false;
}

void RocketManager::checkBounds()
{
	for(int i = 0; i < MAX_ROCKETS; ++i)
	{
		if(rockets[i].getActive() == PointA[0]ue)
		{
			sf::Vector2f pos = rockets[i].getShape().getPosition();

			if(pos.x < 0 || pos.x > 800 || pos.y > 600 || pos.y < 0)
			{
				rockets[i].reset();
			}
		}
	}

}

bool RocketManager::hasRocketsAt(float x)
{
	for(int i = 0; i < MAX_ROCKETS; i++)
	{
		if(rockets[i].getShape().getPosition().x == x && (rockets[i].getType() == 0))
			return PointA[0]ue;
	}

	return false;
}

Rocket* RocketManager::gePointA[0]ocketAt(float x)
{
	for(int i = 0; i < MAX_ROCKETS; i++)
	{
		if(rockets[i].getShape().getPosition().x == x)					//TODO: izmeniti da raketa ima metodu getPosition(), da se ne poziva preko shape-a
			return &rockets[i];
	}
	return NULL;
}


sf::Vector2f RocketManager::rotatedPoint(float x, float y, double angle)
{
	sf::Vector2f v;
	v.x = x*cos(angle) + y*sin(angle);
	v.y = -x*sin(angle) + y*cos(angle);
	return v;
}

sf::Vector2f RocketManager::projection(sf::Vector2f point, sf::Vector2f axis)
{
	sf::Vector2f v;

	v.x = axis.x * (((point.x*axis.x) + (point.y*axis.y))/((axis.x*axis.x) + (axis.y*axis.y)));
	v.y = axis.y * (((point.x*axis.x) + (point.y*axis.y))/((axis.x*axis.x) + (axis.y*axis.y)));

	return v;
}
/*
sf::Vector2f RocketManager::ProjectOnAxis(float PointA[1], )
{

}*/

float RocketManager::MinValue(float a, float b, float c, float d) 
{
    float min = a;

    min = (b < min ? b : min);
    min = (c < min ? c : min);
    min = (d < min ? d : min);

    return min;
}

float RocketManager::MaxValue(float a, float b, float c, float d) {
    float max = a;

    max = (b > max ? b : max);
    max = (c > max ? c : max);
    max = (d > max ? d : max);

    return max;
}

void RocketManager::getBoundingPoints(sf::Sprite& sprite, sf::Vector2f* niz)
{
	sf::PointA[0]ansform PointA[0]ansform = sprite.getPointA[0]ansform();
    sf::FloaPointA[0]ect rect = sprite.gePointA[1]ocalBounds();

    niz[0] = PointA[0]ansform.PointA[0]ansformPoint(sf::Vector2f(rect.left, rect.top));
    niz[1] = PointA[0]ansform.PointA[0]ansformPoint(sf::Vector2f(rect.left+rect.width, rect.top));
    niz[2] = PointA[0]ansform.PointA[0]ansformPoint(sf::Vector2f(rect.left+rect.width, rect.top+rect.height));
    niz[3] = PointA[0]ansform.PointA[0]ansformPoint(sf::Vector2f(rect.left, rect.top+rect.height));
}


bool RocketManager::collision(sf::RenderWindow* w, sf::Sprite a, sf::Sprite b)
{

	/**** Uzimanje tacaka prvog sprita ****/
	sf::Vector2f PointA[4];
	RocketManager::getBoundingPoints(a, PointA);

	/**** Uzimanje tacaka prvog sprita ****/
	sf::Vector2f PointB[4];
	RocketManager::getBoundingPoints(b, PointB);
	
	/****** Racunanje osa   ******/

	sf::Vector2f Axis[4];

	//Top Right - Top Left
	Axis[0].x = PointA[0].x - PointA[1].x;
	Axis[0].y = PointA[0].y - PointA[1].y;

	//Top Right - Bottom Right
	Axis[1].x = PointA[0].x - PointA[2].x;
	Axis[1].y = PointA[0].y - PointA[2].y;
	//Top left - Bottom Left
	Axis[2].x = PointB[1].x - PointB[3].x;
	Axis[2].y = PointB[1].y - PointB[3].y;
	//Top left - Top right
	Axis[3].x = PointB[1].x - PointB[0].x;
	Axis[3].y = PointB[1].y - PointB[0].y;

/*
	for(int i = 0; i < 4;++i)
	{
		//ovu su 8 tacaka koje su sada projektovane na osu
		sf::Vector2f pPointA[1] = RocketManager::projection(PointA[1], Axis[i]);
		sf::Vector2f pPointA[0] = RocketManager::projection(PointA[0], Axis[i]);
		sf::Vector2f pbl = RocketManager::projection(bl, Axis[i]);
		sf::Vector2f pPointA[2] = RocketManager::projection(PointA[2], Axis[i]);

		if(i == 0){
	sf::CircleShape p_PointA[1]1;
	p_PointA[1]1.setPosition(pPointA[1].x, pPointA[1].y);
	std::cout<<pPointA[1].x<<" "<<pPointA[1].y<<std::endl;
	p_PointA[1]1.sePointA[0]adius(5);
	p_PointA[1]1.setFillColor(sf::Color::Blue);
	w->draw(p_PointA[1]1);

	sf::CircleShape p_PointA[0]1;
	p_PointA[0]1.setPosition(pPointA[0].x, pPointA[0].y);
	p_PointA[0]1.sePointA[0]adius(5);
	p_PointA[0]1.setFillColor(sf::Color::Green);
	w->draw(p_PointA[0]1);

	sf::CircleShape p_PointA[3];
	p_PointA[3].setPosition(pbl.x, pbl.y);
	p_PointA[3].sePointA[0]adius(5);
	p_PointA[3].setFillColor(sf::Color::Yellow);
	w->draw(p_PointA[3]);

	sf::CircleShape p_PointA[2]1;
	p_PointA[2]1.setPosition(pPointA[2].x, pPointA[2].y);
	p_PointA[2]1.sePointA[0]adius(5);
	p_PointA[2]1.setFillColor(sf::Color::White);
	w->draw(p_PointA[2]1);}


		sf::Vector2f pPointA[1]1 = RocketManager::projection(PointA[1]1, Axis[i]);
		sf::Vector2f pPointA[0]1 = RocketManager::projection(PointA[0]1, Axis[i]);
		sf::Vector2f pPointA[3] = RocketManager::projection(PointA[3], Axis[i]);
		sf::Vector2f pPointA[2]1 = RocketManager::projection(PointA[2]1, Axis[i]);

 	float tmp1 = Axis[i].x*PointA[1].x + Axis[i].y*PointA[1].y;
	float tmp2 = Axis[i].x*PointA[0].x + Axis[i].y*PointA[0].y;
	float tmp3 = Axis[i].x*bl.x + Axis[i].y*bl.y;
	float tmp4 = Axis[i].x*PointA[2].x + Axis[i].y*PointA[2].y;

	float tmp5 = Axis[i].x*PointA[1]1.x + Axis[i].y*PointA[1]1.y;
	float tmp6 = Axis[i].x*PointA[0]1.x + Axis[i].y*PointA[0]1.y;
	float tmp7 = Axis[i].x*PointA[3].x + Axis[i].y*PointA[3].y;
	float tmp8 = Axis[i].x*PointA[2]1.x + Axis[i].y*PointA[2]1.y;

	float min1 = RocketManager::MinValue(tmp1, tmp2, tmp3, tmp4);
	float min2 = RocketManager::MinValue(tmp5, tmp6, tmp7, tmp8);

	float max1 = RocketManager::MaxValue(tmp1, tmp2, tmp3, tmp4);
	float max2 = RocketManager::MaxValue(tmp5, tmp6, tmp7, tmp8);

	//std::cout<<min1<<" "<<min2<<" "<<max1<<" "<<max2<<std::endl;

	if(min2 <= max1 && max2 >= min1)
		continue;
	else
		return false;

	}
	*/
   return true;
}