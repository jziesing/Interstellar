#include "title.h"

title::title(int center_x, int center_y, string text, int fontsz, int style) 
{
	center[0] = center_x;
	center[1] = center_y;
	initFont();
	createTitle(text, fontsz, style);
}

void title::initFont() 
{
	font.loadFromFile("../styles/font/TerminusTTF-4.38.2.ttf");
}

void title::createTitle(string text, int fontsz, int style) 
{
	titleText = Text(text, font);
	titleText.setCharacterSize(fontsz);
	if (style == 0)
		titleText.setStyle(Text::Regular);
	if (style == 1)
		titleText.setStyle(Text::Bold);
	if (style == 2)
		titleText.setStyle(Text::Italic);
	FloatRect textRect = titleText.getLocalBounds();
	titleText.setOrigin(textRect.left + textRect.width/2.0f, textRect.top + textRect.height/2.0f);
	titleText.setPosition(center[0], center[1]);
}

void title::update(RenderWindow& window) 
{
	window.draw(titleText);
}