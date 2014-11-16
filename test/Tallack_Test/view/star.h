#ifndef STAR_H
#define STAR_H
#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <time.h>

using namespace sf;
using namespace std;

class star {
protected:
	int DIMS[2];
	CircleShape starshape;
public:
	star(int xdims, int ydims);
	void generate();
	~stars(){};
};
#endif