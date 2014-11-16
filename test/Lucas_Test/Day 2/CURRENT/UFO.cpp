#include "UFO.h"

UFO::UFO()
{
	tex.loadFromFile("../../../../styles/images/Infinity-Icons/PNG/UFOs/0.png");
	tex.setSmooth(true);
	sp.setTexture(tex, true);
}

void UFO::setType(int idx)
{
	ostringstream ss;
	ss << idx;
	string dir = "../../../../styles/images/Infinity-Icons/PNG/UFOs/";
	string file = ss.str() + ".png";
	string filePath = dir + file;
	tex.loadFromFile(filePath);
	tex.setSmooth(true);
	sp.setTexture(tex, true);
}