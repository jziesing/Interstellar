#ifndef SPACEOBJECT_H
#define SPACEOBJECT_H
#include <SFML/Graphics.hpp>
#include <sstream>
#include <string>

using namespace sf;
using namespace std;

class spaceobject
{
protected:
	float tmpSpeed;
public:
	float speed;
	Texture tex;
	Sprite sp;
	spaceobject();
	~spaceobject() {};
};
#endif