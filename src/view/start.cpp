#include "start.h"

start::start()
{
	gameobjects = new spaceobject[5];
}

start::start(int num_of_objects)
{
	gameobjects = new spaceobject[num_of_objects];
}