#include "UFO2.h"

UFO::UFO()
{
	tex = new Texture();
	tex->loadFromFile("../styles/images/Infinity-Icons/PNG/UFOs/0.png");
	sp = new Sprite();
	sp-> setTexture(tex);
}