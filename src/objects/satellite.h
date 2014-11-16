#ifndef SATELLITE_H
#define SATELLITE_H
#include "spaceobject.h"

class satellite: public spaceobject
{
public:
	satellite();
	satellite(int);
	satellite(int, int);
	satellite(int, int, int);
	void init(string);
	void update(RenderWindow &window, float);
	~satellite() {};
};

#endif