#include "helper.h"

string intToString(int integer)
{
	ostringstream ss;
	ss << integer;
	return ss.str();
}

int randomInt(int high)
{
	int random = rand() % high;
	return random;
}

int randomIntBetween(int max, int min)
{
	int randNum = rand()%(max-min + 1) + min;
	return randNum;
}

float randomFloatBetween(int low, int high)
{
	int r = rand(); 
	float fraction = ((float) r / RAND_MAX) * (high - low); 
	float random = low + fraction; 
	return random;
}