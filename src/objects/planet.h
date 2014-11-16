#ifndef PLANET_H
#define PLANET_H
#include "spaceobject.h"
#include "satellite.h"

class planet: public spaceobject
{
public:
	satellite* orbit;
	planet();
	planet(int);
	planet(int, int);
	planet(int, int, int);
	virtual void init(string);
	void setSattelites();
	virtual void update(RenderWindow &window, float);
	~planet() {};
};
#endif