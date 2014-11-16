#ifndef UFO2_H
#define UFO2_H
#include <SFML/Graphics.hpp>
#include <iostream>
#include <sstream>
#include <string>

using namespace sf;
using namespace std;

class UFO
{
protected:
	Texture* tex;
	Sprite* sp;
public:
	UFO();
	~UFO(){};
};
#endif