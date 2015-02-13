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

	v.x = axis.x * (((point.x*axis.x) + (point.y*axis.y))/((axis.x*axis.x) + (axis.y*axis.y)));
	v.y = axis.y * (((point.x*axis.x) + (point.y*axis.y))/((axis.x*axis.x) + (axis.y*axis.y)));

	return v;
}
/*
sf::Vector2f RocketManager::ProjectOnAxis(float tl, )
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

}


bool RocketManager::collision(sf::RenderWindow* w, sf::Sprite a, sf::Sprite b)
{

	/**** Uzimanje tacaka prvog sprita ****/
	sf::Vector2f tl, tr, bl, br;

	sf::Transform transform = a.getTransform();
    sf::FloatRect rect = a.getLocalBounds();

    tl = transform.transformPoint(sf::Vector2f(rect.left, rect.top));
    tr = transform.transformPoint(sf::Vector2f(rect.left+rect.width, rect.top));
    bl = transform.transformPoint(sf::Vector2f(rect.left+rect.width, rect.top+rect.height));
    br = transform.transformPoint(sf::Vector2f(rect.left, rect.top+rect.height));

	/**** Ispis tacaka   *****/
	sf::CircleShape dot_tl;
	dot_tl.setPosition(tl.x, tl.y);
	dot_tl.setRadius(5);
	dot_tl.setFillColor(sf::Color::Red);
	w->draw(dot_tl);

	sf::CircleShape dot_tr;
	dot_tr.setPosition(tr.x, tr.y);
	dot_tr.setRadius(5);
	dot_tr.setFillColor(sf::Color::Red);
	w->draw(dot_tr);

	sf::CircleShape dot_bl;
	dot_bl.setPosition(bl.x, bl.y);
	dot_bl.setRadius(5);
	dot_bl.setFillColor(sf::Color::Red);
	w->draw(dot_bl);

	sf::CircleShape dot_br;
	dot_br.setPosition(br.x, br.y);
	dot_br.setRadius(5);
	dot_br.setFillColor(sf::Color::Red);
	w->draw(dot_br);


	/**** Uzimanje tacaka prvog sprita ****/
	sf::Vector2f tl1, tr1, bl1, br1;
	sf::Transform transform1 = b.getTransform();
    sf::FloatRect rect1 = b.getLocalBounds();

    tl1 = transform1.transformPoint(sf::Vector2f(rect1.left, rect1.top));
    tr1 = transform1.transformPoint(sf::Vector2f(rect1.left+rect1.width, rect1.top));
    bl1 = transform1.transformPoint(sf::Vector2f(rect1.left+rect1.width, rect1.top+rect1.height));
    br1 = transform1.transformPoint(sf::Vector2f(rect1.left, rect1.top+rect1.height));

	
	/****** Ispis tacaka     *****/
	sf::CircleShape dot_tl1;
	dot_tl1.setPosition(tl1.x, tl1.y);
	dot_tl1.setRadius(5);
	dot_tl1.setFillColor(sf::Color::Red);
	w->draw(dot_tl1);

	sf::CircleShape dot_tr1;
	dot_tr1.setPosition(tr1.x, tr1.y);
	dot_tr1.setRadius(5);
	dot_tr1.setFillColor(sf::Color::Red);
	w->draw(dot_tr1);

	sf::CircleShape dot_bl1;
	dot_bl1.setPosition(bl1.x, bl1.y);
	dot_bl1.setRadius(5);
	dot_bl1.setFillColor(sf::Color::Red);
	w->draw(dot_bl1);

	sf::CircleShape dot_br1;
	dot_br1.setPosition(br1.x, br1.y);
	dot_br1.setRadius(5);
	dot_br1.setFillColor(sf::Color::Red);
	w->draw(dot_br1);


	/****** Racunanje osa   ******/

	sf::Vector2f Axis[4];

	//Top Right - Top Left
	Axis[0].x = tr.x - tl.x;
	Axis[0].y = tr.y - tl.y;

		sf::CircleShape axis_shape;
	axis_shape.setPosition(Axis[0].x, Axis[0].y);
	axis_shape.setRadius(5);
	axis_shape.setFillColor(sf::Color::Green);
	w->draw(axis_shape);

	//Top Right - Bottom Right
	Axis[1].x = tr.x - br.x;
	Axis[1].y = tr.y - br.y;
	//Top left - Bottom Left
	Axis[2].x = tl1.x - bl1.x;
	Axis[2].y = tl1.y - bl1.y;
	//Top left - Top right
	Axis[3].x = tl1.x - tr1.x;
	Axis[3].y = tl1.y - tr1.y;


	for(int i = 0; i < 4;++i)
	{
		//ovu su 8 tacaka koje su sada projektovane na osu
		sf::Vector2f ptl = RocketManager::projection(tl, Axis[i]);
		sf::Vector2f ptr = RocketManager::projection(tr, Axis[i]);
		sf::Vector2f pbl = RocketManager::projection(bl, Axis[i]);
		sf::Vector2f pbr = RocketManager::projection(br, Axis[i]);

		if(i == 0){
	sf::CircleShape p_tl1;
	p_tl1.setPosition(ptl.x, ptl.y);
	std::cout<<ptl.x<<" "<<ptl.y<<std::endl;
	p_tl1.setRadius(5);
	p_tl1.setFillColor(sf::Color::Blue);
	w->draw(p_tl1);

	sf::CircleShape p_tr1;
	p_tr1.setPosition(ptr.x, ptr.y);
	p_tr1.setRadius(5);
	p_tr1.setFillColor(sf::Color::Green);
	w->draw(p_tr1);

	sf::CircleShape p_bl1;
	p_bl1.setPosition(pbl.x, pbl.y);
	p_bl1.setRadius(5);
	p_bl1.setFillColor(sf::Color::Yellow);
	w->draw(p_bl1);

	sf::CircleShape p_br1;
	p_br1.setPosition(pbr.x, pbr.y);
	p_br1.setRadius(5);
	p_br1.setFillColor(sf::Color::White);
	w->draw(p_br1);}


		sf::Vector2f ptl1 = RocketManager::projection(tl1, Axis[i]);
		sf::Vector2f ptr1 = RocketManager::projection(tr1, Axis[i]);
		sf::Vector2f pbl1 = RocketManager::projection(bl1, Axis[i]);
		sf::Vector2f pbr1 = RocketManager::projection(br1, Axis[i]);

 	float tmp1 = Axis[i].x*tl.x + Axis[i].y*tl.y;
	float tmp2 = Axis[i].x*tr.x + Axis[i].y*tr.y;
	float tmp3 = Axis[i].x*bl.x + Axis[i].y*bl.y;
	float tmp4 = Axis[i].x*br.x + Axis[i].y*br.y;

	float tmp5 = Axis[i].x*tl1.x + Axis[i].y*tl1.y;
	float tmp6 = Axis[i].x*tr1.x + Axis[i].y*tr1.y;
	float tmp7 = Axis[i].x*bl1.x + Axis[i].y*bl1.y;
	float tmp8 = Axis[i].x*br1.x + Axis[i].y*br1.y;

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

	return true;
}