#ifndef LASER_H
#define LASER_H
#include "spaceobject.h"
#include <string>
#include <iostream>

class laser: public spaceobject
{
public:
	float xMove;
	float yMove;

	// laser();
	// laser(int);
	laser(int, int, float, float);
	// laser(int, int, int);
	virtual void init(string, float, float);
	virtual void update(RenderWindow &window, float);
	~laser() {};
};
#endif