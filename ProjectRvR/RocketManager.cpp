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


void RocketManager::checkCollision(sf::RenderWindow* w)
{
	for(int i = 0; i < MAX_ROCKETS; i++)
	{
		//trenutne napadacke rakete
		if(rockets[i].getActive() == true && rockets[i].getType() == 0)
		{
			for(int j = 0; j < MAX_ROCKETS;++j)
			{
				if(rockets[j].getActive() == true && rockets[j].getType() != 0)
				{
					if(collision(w, rockets[i].getSprite(), rockets[j].getSprite()))
					{
						rockets[i].reset();
						rockets[j].reset();
					}
				}
		
			}
		}
	}
}



void RocketManager::ProjectOnAxis(sf::Vector2f* points, sf::Vector2f axis, float& min, float& max)
{
   min = (points[0].x*axis.x+points[0].y*axis.y);
   max =  min;

  for (int j = 1; j<4; j++)
  {
     float dot_p = (points[j].x*axis.x+points[j].y*axis.y);

	 if(dot_p <min)
		 min = dot_p;

	 if(dot_p > max)
		 max = dot_p;
            
  }
}

void RocketManager::getBoundingPoints(sf::Sprite& sprite, sf::Vector2f* niz)
{
	sf::Transform transform = sprite.getTransform();
    sf::FloatRect rect = sprite.getLocalBounds();

    niz[0] = transform.transformPoint(sf::Vector2f(rect.left, rect.top));  //tl
    niz[1] = transform.transformPoint(sf::Vector2f(rect.left+rect.width, rect.top)); //tr
    niz[2] = transform.transformPoint(sf::Vector2f(rect.left, rect.top+rect.height));  //bl
    niz[3] = transform.transformPoint(sf::Vector2f(rect.left+rect.width, rect.top+rect.height)); //br
}


bool RocketManager::collision(sf::RenderWindow* w, sf::Sprite& a, sf::Sprite& b)
{

	/**** Uzimanje tacaka prvog sprita ****/
	sf::Vector2f pointsA[4];
	RocketManager::getBoundingPoints(a, pointsA);

	/**** Uzimanje tacaka prvog sprita ****/
	sf::Vector2f pointsB[4];
	RocketManager::getBoundingPoints(b, pointsB);
	
	
	/****** Racunanje osa   ******/

	sf::Vector2f Axis[4];

	//0 - tl, 1 - tr, 2 - bl, 3 - br

	//Top Right - Top Left
	Axis[0].x = pointsA[1].x - pointsA[0].x;
	Axis[0].y = pointsA[1].y - pointsA[0].y;
	//Top Right - Bottom Right
	Axis[1].x = pointsA[1].x - pointsA[3].x;
	Axis[1].y = pointsA[1].y - pointsA[3].y;
	//Top left - Bottom Left
	Axis[2].x = pointsB[0].x - pointsB[2].x;
	Axis[2].y = pointsB[0].y - pointsB[2].y;
	//Top left - Top right
	Axis[3].x = pointsB[0].x - pointsB[1].x;
	Axis[3].y = pointsB[0].y - pointsB[1].y;

	//idemo po svakoj osi
	for(int i = 0; i < 4;++i)
	{
		float minA, maxA, minB, maxB;

		RocketManager::ProjectOnAxis(pointsA, Axis[i], minA, maxA);
		RocketManager::ProjectOnAxis(pointsB, Axis[i], minB, maxB);

		if(((minB <= maxA) && (maxB >= minA)))
			continue;
		else
			return false;
	}

	return true;
}