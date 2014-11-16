#include "satellite.h"

satellite::satellite()
	: spaceobject("Satellites", 0, 0, randomInt(NUM_OF_SATELLITES)) {
		init("Satellites");
	}

satellite::satellite(int idx_sprite_type)
	: spaceobject("Satellites", 0, 0, idx_sprite_type) {
		init("Satellites");
	}

satellite::satellite(int x, int y)
	: spaceobject("Satellites", x, y, randomInt(NUM_OF_SATELLITES)) {
		init("Satellites");
	}

satellite::satellite(int x, int y, int idx_sprite_type)
	: spaceobject("Satellites", x, y, idx_sprite_type) {
		init("Satellites");
	}

void satellite::init(string type)
{
	sp.setScale(0.3, 0.3);
	speed = randomFloatBetween(1, 10);
	life = 1;
	objectType = type;
}

void satellite::update(RenderWindow& window, float delta)
{
	sp.rotate(speed*delta);
	window.draw(sp);
}