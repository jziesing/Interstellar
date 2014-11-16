#include "laser.h"

// laser::laser(int xMove, int yMove)
// 	: spaceobject("Lasers", 0, 0, randomInt(NUM_OF_LASERS)) {
// 		init("Lasers", xMove, yMove);
// 	}

// laser::laser(int idx_sprite_type)
// 	: spaceobject("Lasers", 0, 0, idx_sprite_type) {
// 		init("Lasers");
// 	}

laser::laser(int x, int y, float xMove, float yMove)
	: spaceobject("Lasers", x, y, randomInt(NUM_OF_LASERS)) {
		init("Lasers", xMove, yMove);
	}

// laser::laser(int x, int y, int idx_sprite_type)
// 	: spaceobject("Lasers", x, y, idx_sprite_type) {
// 		init("Lasers");
// 	}

void laser::init(string type, float xMove, float yMove)
{
	speed = 200;
	life = 10;
	objectType = type;
	
	sp.setColor(Color(0, 0, 0));
	sp.setScale(.4, .4);
	this->xMove = xMove;
	this->yMove = yMove;
}

void laser::update(RenderWindow &window, float delta){
	if (inWindow()){
		sp.move(speed*xMove*delta, speed*yMove*delta);		
	}
	window.draw(sp);
}