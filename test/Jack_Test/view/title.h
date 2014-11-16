#ifndef TITLE_H
#define TITLE_H
#include <SFML/Graphics.hpp>
#include <string>

using namespace sf;
using namespace std;

class title {
protected:
	int center[2];
	Font font;
public:
	title(int center_x, int center_y);
	void initFont(string filePath);
	Text createTitle(string txt, int fontsz, int style);
	//RectangleShape createBorder(4);
	~title() {};	
};
#endif