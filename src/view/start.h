#ifndef START_H
#define START_H
#include "../objects/spaceobject.h"

class start
{
public:
	spaceobject* gameobjects;
	start();
	start(int num_of_objects);
	void update(RenderWindow &window, float delta);
	~start() {};
};
#endif