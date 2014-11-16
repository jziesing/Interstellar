#ifndef TITLE_H
#define TITLE_H
#include <SFML/Graphics.hpp>
#include <string>

using namespace sf;
using namespace std;

class title {
public:
	Font font;
	int center[2];
	Text titleText;
	title(int, int, string, int, int);
	void initFont();
	void createTitle(string txt, int fontsz, int style);
	void createBorder();
	void update(RenderWindow &window);
	~title() {};	
};
#endif