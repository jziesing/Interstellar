#include "planet.h"

planet::planet()
	: spaceobject("Planets", 0, 0, randomInt(NUM_OF_PLANETS)) {
		init("Planets");
	}

planet::planet(int idx_sprite_type)
	: spaceobject("Planets", 0, 0, idx_sprite_type) {
		init("Planets");
	}

planet::planet(int x, int y)
	: spaceobject("Planets", x, y, randomInt(NUM_OF_PLANETS)) {
		init("Planets");
	}

planet::planet(int x, int y, int idx_sprite_type)
	: spaceobject("Planets", x, y, idx_sprite_type) {
		init("Planets");
	}

void planet::init(string type)
{
	speed = 0;
	life = 10000;
	objectType = type;
}

void planet::setSattelites()
{
	Vector2f position = sp.getPosition();
	FloatRect bounds = sp.getGlobalBounds();
	orbit = new satellite(position.x, position.y);
	if (bounds.width > bounds.height)
		orbit->sp.setOrigin(2*bounds.width, 2*bounds.width);
	else
		orbit->sp.setOrigin(2*bounds.height, 2*bounds.height);
}

void planet::update(RenderWindow &window, float delta)
{
	sp.rotate(.01);
	orbit->update(window, delta);
	window.draw(sp);
}