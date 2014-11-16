#include "star.h"

star::star()
	: spaceobject("Stars", 0, 0, randomInt(NUM_OF_STARS)) {
		init("Stars");
		setRotation(0, 0, randomIntBetween(100, 200));
	}

star::star(int idx_sprite_type)
	: spaceobject("Stars", 0, 0, idx_sprite_type) {
		init("Stars");
		setRotation(0, 0, randomIntBetween(100, 3000));
	}

star::star(int x, int y)
	: spaceobject("Stars", x, y, randomInt(NUM_OF_STARS)) {
		init("Stars");
		setRotation(x, y, randomIntBetween(10, 3000));
	}

star::star(int x, int y, int idx_sprite_type)
	: spaceobject("Stars", x, y, idx_sprite_type) {
		init("Stars");
		setRotation(0, 0, randomIntBetween(100, 3000));
	}

void star::init(string type)
{
	sp.setScale(0.3, 0.3);
	speed = 20.0;
	life = 2;
	objectType = type;
}

void star::update(RenderWindow &window, float delta)
{
	sp.rotate(speed * delta);
	window.draw(sp);
}