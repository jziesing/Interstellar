#include "star.h"

star::star(int xdims, int ydims) {
	DIMS[0] = xdims;
	DIMS[1] = ydims;
}

star::generate() {
	int xrand = rand() % DIMS[0];
	int yrand = rand() % DIMS[1];
	starshape.setRadius(2);
	starshape.setPosition(xrand, yrand);
}