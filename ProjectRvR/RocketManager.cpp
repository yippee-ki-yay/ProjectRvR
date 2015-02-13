#include "RocketManager.h"

RocketManager::RocketManager()
{
	for(int i = 0; i < MAX_ROCKETS; ++i)
	{
		//rockets[i].setTexture((*this).getTexture());			//postavljanje slike na svaku raketu
		//rockets[i].getShape().setRadius(20);
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
		if(rockets[i].getActive() == true)
		{
			window->draw(rockets[i].getShape());
			window->draw(rockets[i].getSprite());
			rockets[i].move();

		}
	}
}

Rocket* RocketManager::getRocket(RocketManager::Type t)
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
				rockets[i].setImage("odbrana.png");

			rockets[i].setActive(true);
				rockets[i].setType(t);
				rockets[i].setActive(true);
			return &(rockets[i]);
		}
	}
	
}

bool RocketManager::hasRockets()
{
	for(int i = 0; i < MAX_ROCKETS; ++i)
	{
		if(rockets[i].getActive() == false)
			return true;
	}

	return false;
}

void RocketManager::checkBounds()
{
	for(int i = 0; i < MAX_ROCKETS; ++i)
	{
		if(rockets[i].getActive() == true)
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
			return true;
	}

	return false;
}

Rocket* RocketManager::getRocketAt(float x)
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

	v.x = axis.x * ((point.x*axis.x + point.y*axis.y)/axis.x*axis.x + axis.y*axis.y);
	v.y = axis.y * ((point.x*axis.x + point.y*axis.y)/axis.x*axis.x + axis.y*axis.y);

	return v;
}

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

bool RocketManager::collision(sf::Sprite a, sf::Sprite b)
{
	sf::Vector2f tl, tr, bl, br;
	double angle;
	angle = a.getRotation();
	
	float width = a.getGlobalBounds().width;
	float height = a.getGlobalBounds().height;
	float posX = a.getPosition().x;
	float posY = a.getPosition().y;

    tl = a.getTransform().transformPoint(sf::Vector2f(0,0));
	tr = a.getTransform().transformPoint(sf::Vector2f(width,0));
	bl = a.getTransform().transformPoint(sf::Vector2f(0,height));
	br = a.getTransform().transformPoint(sf::Vector2f(width,height));

	sf::Vector2f tl1, tr1, bl1, br1;
	double angle1;
	angle1 = b.getRotation();

	float width1 = b.getGlobalBounds().width;
	float height1 = b.getGlobalBounds().height;
	float posX1 = b.getPosition().x;
	float posY1 = b.getPosition().y;

    tl1 = b.getTransform().transformPoint(sf::Vector2f(0,0));
	tr1 = b.getTransform().transformPoint(sf::Vector2f(width1,0));
	bl1 = b.getTransform().transformPoint(sf::Vector2f(0,height1));
	br1 = b.getTransform().transformPoint(sf::Vector2f(width1,height1));

	sf::Vector2f Axis[4];

	Axis[0].x = tr.x - tl.x;
	Axis[0].y = tr.y - tl.y;
	Axis[1].x = tr.x - br.x;
	Axis[1].y = tr.y - br.y;
	Axis[2].x = tr1.x - tl1.x;
	Axis[2].y = tr1.y - tl1.y;
	Axis[3].x = tr1.x - br1.x;
	Axis[3].y = tr1.y - br1.y;


	for(int i = 0; i < 4;++i)
	{
		tl = RocketManager::projection(tl, Axis[i]);
		tr = RocketManager::projection(tr, Axis[i]);
		bl = RocketManager::projection(bl, Axis[i]);
		br = RocketManager::projection(br, Axis[i]);

		tl1 = RocketManager::projection(tl1, Axis[i]);
		tr1 = RocketManager::projection(tr1, Axis[i]);
		bl1 = RocketManager::projection(bl1, Axis[i]);
		br1 = RocketManager::projection(br1, Axis[i]);

	float tmp1 = sqrt(tl.x*tl.x+ tl.y*tl.y);
	float tmp2 = sqrt(tr.x*tr.x+ tr.y*tr.y);
	float tmp3 = sqrt(bl.x*bl.x+ bl.y*bl.y);
	float tmp4 = sqrt(br.x*br.x+ br.y*br.y);

	float tmp5 = sqrt(tl1.x*tl1.x+ tl1.y*tl1.y);
	float tmp6 = sqrt(tr1.x*tr1.x+ tr1.y*tr1.y);
	float tmp7 = sqrt(bl1.x*bl1.x+ bl1.y*bl1.y);
	float tmp8 = sqrt(br1.x*br1.x+ br1.y*br1.y);

	float min1 = RocketManager::MinValue(tmp1, tmp2, tmp3, tmp4);
	float min2 = RocketManager::MinValue(tmp5, tmp6, tmp7, tmp8);

	float max1 = RocketManager::MaxValue(tmp1, tmp2, tmp3, tmp4);
	float max2 = RocketManager::MaxValue(tmp5, tmp6, tmp7, tmp8);

	if(min2 <= min1 && max2 >= min1)
		continue;
	else
		return false;

	}

	return true;
}

void RocketManager::checkCollision()
{
	for(int i = 0; i < MAX_ROCKETS; i++)
	{
		if(rockets[i].getType() == 1)
		{
			for(int j = 0; j < MAX_ROCKETS; j++)
			{
				if(rockets[j].getType() == 0)
				{
					if(RocketManager::collision(rockets[i].getSprite(), rockets[j].getSprite()))
					{
						//rockets[i].reset();
						//rockets[j].reset();
						std::cout << "COLLISION";
					}
				}
			}
		}

	}


}