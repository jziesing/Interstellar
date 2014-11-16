#include "UFO.h"
#include <iostream>

const int DIMS[2] = {800, 600};

int main(int argc, char const *argv[])
{

	ContextSettings settings;
	settings.antialiasingLevel = 10;
	RenderWindow window(VideoMode(DIMS[0], DIMS[1]), "interstellar-test-env", Style::Default, settings);

	Texture backgroundText;
	backgroundText.loadFromFile("../../../../styles/images/Backgrounds/800 x 600/14.jpg");
	Sprite background;
	background.setTexture(backgroundText);

	UFO* test = new UFO();
	cout << test->speed << endl;

	test->sp.setPosition(100,400);

	UFO test2;
	test2.setType(5);
	test2.sp.setScale(.5,.5);

	UFO* tmp = new UFO[3];
	for (int i = 0; i < 3; ++i)
	{
		tmp[i].setType(i);	
	}
	tmp[0].sp.setPosition(200,200);
	tmp[1].sp.setPosition(400,400);
	tmp[2].sp.setPosition(300,300);
	
	while (window.isOpen())
	{
		Event event;
		while (window.pollEvent(event))
		{

			if (event.type == Event::Closed)
			{
				window.close();
			}
		}
		window.clear();
		window.draw(background);
		window.draw(test->sp);
		window.draw(test2.sp);

		for (int i = 0; i < 3; ++i)
		{
			window.draw(tmp[i].sp);
		}
		window.display();
	}
	//delete [] tmp;
	return 0;
}