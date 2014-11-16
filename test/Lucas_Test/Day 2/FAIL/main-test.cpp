#include "UFO2.h"

int main(int argc, char const *argv[])
{

	RenderWindow window(VideoMode(800,600), "test-app");

	Texture backgroundText;
	backgroundText.loadFromFile("../styles/images/Backgrounds/800 x 600/14.jpg");
	Sprite background;
	background.setTexture(backgroundText);

	/*Texture test;
	test.loadFromFile("../styles/images/Infinity-Icons/PNG/NASA/untitled-41.png");
	Sprite testSprite;
	testSprite.setTexture(test);*/

	UFO* test = new UFO();
	//UFO test2;
	/*UFO* tmp = new UFO[3];

	tmp[0].sp.setPosition(200,200);
	tmp[1].sp.setPosition(400,400);
	tmp[2].sp.setPosition(600,600);*/
	
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
		/*window.draw(test2.sp);
		for (int i = 0; i < 3; ++i)
		{
			window.draw(tmp[i].sp);
		}*/
		//window.draw(testSprite);
		//window.draw(UFOs[0]);
		window.display();
	}
	//delete [] tmp;
	return 0;
}