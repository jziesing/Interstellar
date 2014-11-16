#include "ufo.h"

ufo::ufo()
	: spaceobject("UFOs", 0, 0, randomInt(NUM_OF_UFOS)) {
		init("UFOs");
	}

ufo::ufo(int idx_sprite_type)
	: spaceobject("UFOs", 0, 0, idx_sprite_type) {
		init("UFOs");
	}

ufo::ufo(int x, int y)
	: spaceobject("UFOs", x, y, randomInt(NUM_OF_UFOS)) {
		init("UFOs");
	}

ufo::ufo(int x, int y, int idx_sprite_type)
	: spaceobject("UFOs", x, y, idx_sprite_type) {
		init("UFOs");
	}

void ufo::init(string type)
{
	speed = 150;
	life = 10;
	objectType = type;
	sp.setScale(0.2, 0.2);
}

laser* ufo::shoot(float xMove, float yMove){
	Vector2f position = sp.getPosition();
	laser* tempLaser = new laser(position.x, position.y, xMove, yMove);
	return tempLaser;
}

void ufo::move(RenderWindow &window, int input, float delta){
	switch ( input ) {
	case 0:
	  sp.move(-speed*delta, 0.f);
	  break;
	case 1:
	  sp.move(0.f, -speed*delta);
	  break;
	case 2:
	  sp.move(speed*delta, 0.f);
	  break;
	case 3:
	  sp.move(0.f, speed*delta);
	  break;
	}
}


