#include "title.h"

title::title(int center_x, int center_y) {
	center[0] = center_x;
	center[1] = center_y;
}

void title::initFont(string path) {
	font.loadFromFile(path);
}

Text title::createTitle(string text, int fontsz, int style) {
	Text title(text, font);
	title.setCharacterSize(fontsz);
	if (style == 0)
		title.setStyle(Text::Regular);
	if (style == 1)
		title.setStyle(Text::Bold);
	if (style == 2)
		title.setStyle(Text::Italic);
	FloatRect textRect = title.getLocalBounds();
	title.setOrigin(textRect.left + textRect.width/2.0f, textRect.top + textRect.height/2.0f);
	title.setPosition(center[0], center[1]);
	return title;
}