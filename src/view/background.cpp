#include "background.h"

background::background(int x_dims, int y_dims)
{
	xdims = x_dims;
	ydims = y_dims;
	filedir = "../styles/images/Backgrounds/" + intToString(xdims) + " x " + intToString(ydims) + "/";
	setType(0,15);
	setType(1,14);
	change = false;
	transparency = 256;
}

void background::setType(int foreOrBack, int idx)
{
	// 0 => background
	// 1 => foreground
	string file = intToString(idx) + ".jpg";
	string filePath = filedir + file;

	if (foreOrBack == 0)
	{
		back_idx = idx;
		texbackground.loadFromFile(filePath);
		texbackground.setSmooth(true);
		spbackground.setTexture(texbackground, true);
	}

	if (foreOrBack == 1)
	{
		fore_idx = idx;
		texforeground.loadFromFile(filePath);
		texforeground.setSmooth(true);
		spforeground.setTexture(texforeground, true);
	}	
}

void background::update(RenderWindow &window)
{
	if (change == false)
	{
		transparency -= 0.5;
		spbackground.setColor(Color(255, 255, 255, transparency));
		window.draw(spforeground);
		window.draw(spbackground);
		if(transparency < 0) {
			change = true;
			if (fore_idx-1 >= 0) {
				setType(0, fore_idx-1);
			} else {
				fore_idx = 15;
				setType(0, fore_idx);
			}
		}
	} else {
		transparency += 0.5;
		spbackground.setColor(Color(255, 255, 255, transparency));
		window.draw(spforeground);
		window.draw(spbackground);
		if (transparency > 255) {
			change = false;
			if (back_idx-1 >= 0) {
				setType(1, back_idx-1);
			} else {
				back_idx = 14;
				setType(1, 14);
			}
		}
	}
}

string background::intToString(int integer)
{
	ostringstream ss;
	ss << integer;
	return ss.str();
}