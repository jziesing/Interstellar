#ifndef UFO_H
#define UFO_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <string>

using namespace sf;
using namespace std;

class UFO
{
public:
	Texture tex;
	Sprite sp;
	UFO();
	~UFO(){};
};
#endif