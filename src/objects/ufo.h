#ifndef UFO_H
#define UFO_H
#include "spaceobject.h"
#include "laser.h"
#include <string>
#include <iostream>

class ufo: public spaceobject
{
public:
	ufo();
	ufo(int);
	ufo(int, int);
	ufo(int, int, int);
	virtual void init(string);

	// shoot
	laser* shoot(float, float);

	// 0: left; 1: up; 2: right; 3: down;
	void move(RenderWindow &window, int, float);
	~ufo() {};
};
#endif