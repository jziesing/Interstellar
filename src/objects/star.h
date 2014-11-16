#ifndef STAR_H
#define STAR_H
#include "spaceobject.h"

class star: public spaceobject
{
public:
	star();
	star(int);
	star(int, int);
	star(int, int, int);
	virtual void init(string);
	virtual void update(RenderWindow &window, float delta);
	~star() {};
};
#endif