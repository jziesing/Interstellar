#include "spaceobject.h"

spaceobject::spaceobject()
{
	speed = 1.0;
	life = 3;
}

spaceobject::spaceobject(string type)
{
	init(type);
	setType(0);
}

spaceobject::spaceobject(string type, int x, int y)
{
	init(type);
	setType(0);
	sp.setPosition(x, y);
}

spaceobject::spaceobject(string type, int x, int y, int idx_sprite_type)
{
	init(type);
	setType(idx_sprite_type);
	sp.setPosition(x, y);
}

void spaceobject::init(string type)
{
	speed = 1.0;
	life = 3;
	objectType = type;
}

void spaceobject::update(RenderWindow& window, float delta)
{
	window.draw(sp);
}

void spaceobject::setType(int idx)
{
	string dir = "../styles/images/Infinity-Icons/PNG/" + objectType + "/";
	string file = intToString(idx) + ".png";
	string filePath = dir + file;
	tex.loadFromFile(filePath);
	tex.setSmooth(true);
	sp.setTexture(tex, true);
	setOriginToCenter();
}

void spaceobject::setOriginToCenter()
{
	FloatRect spriteRectBounds = sp.getLocalBounds();
	sp.setOrigin(spriteRectBounds.left + spriteRectBounds.width/2.0f, spriteRectBounds.top + spriteRectBounds.height/2.0f);
}

void spaceobject::setRotation(int x, int y, int radius)
{
	sp.setPosition(x, y);
	sp.setOrigin(radius, radius);
	sp.setRotation(rand()%361);
}

bool spaceobject::inWindow()
{
	FloatRect bounds = sp.getGlobalBounds();
	// checking left bound
	if (bounds.left + bounds.width < 70 || bounds.left - bounds.width > 1630)
	{
		return false;
	}
	if ( ((bounds.top + bounds.height)  < 45) || ((bounds.top - bounds.height) > 860 ) ) 
	{
		// cout<< bounds.top + bounds.height << endl;
		// cout<< bounds.top - bounds.height << endl;
		return false;
	}
	return true;
}

bool spaceobject::collision(Sprite othersprite){
	FloatRect bounds = sp.getGlobalBounds();
	FloatRect otherbounds = othersprite.getGlobalBounds();
	return bounds.intersects(otherbounds);
}

