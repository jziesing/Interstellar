#ifndef UFO_H
#define UFO_H
#include "spaceobject.h"

class UFO : public spaceobject
{
public:
	UFO();
	void setType(int);
	~UFO(){};
};
#endif