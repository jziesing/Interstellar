#ifndef BACKGROUND_H
#define BACKGROUND_H
#include <SFML/Graphics.hpp>
#include <sstream>
#include <string>

using namespace sf;
using namespace std;

class background
{
public:
	int fore_idx;
	int back_idx;
	int xdims;
	int ydims;
	string filedir;
	Texture texforeground;
	Texture texbackground;
	Sprite spforeground;
	Sprite spbackground;
	bool change;
	float transparency;
	background(int, int);
	void setType(int, int);
	void update(RenderWindow &window);
	string intToString(int);
	~background() {};
};
#endif