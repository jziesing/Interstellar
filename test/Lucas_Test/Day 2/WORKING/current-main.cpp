#include "UFO.h"

int main(int argc, char const *argv[])
{

	RenderWindow window(VideoMode(800,600), "test-app");

	Texture backgroundText;
	backgroundText.loadFromFile("../../../styles/images/Backgrounds/800 x 600/14.jpg");
	Sprite background;
	background.setTexture(backgroundText);


	UFO* test = new UFO();
	test->sp.setPosition(100,400);

	UFO test2;

	UFO* tmp = new UFO[3];
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
	delete [] tmp;
	return 0;
}