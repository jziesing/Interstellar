#ifndef HELPER_H
#define HELPER_H
#include <string>
#include <sstream>
#include <ctime>
#include <random>
#include "helper.h"

/*
 * Number of sprites found in each directory
 */
const int NUM_OF_PLANETS = 13;
const int NUM_OF_SATELLITES = 15;
const int NUM_OF_STARS = 7;
const int NUM_OF_UFOS = 3;
const int NUM_OF_LASERS = 1;


// Max number of laser can be created
const int MAX_NUM_OF_LASERS = 5;

using namespace std;

float randomFloatBetween(int, int);
int randomInt(int);
int randomIntBetween(int, int);
string intToString(int);
#endif