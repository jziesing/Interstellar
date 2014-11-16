#include "../../../src/objects/spaceobject.h"
#include "../../../src/objects/planet.h"
#include "../../../src/objects/satellite.h"
#include "../../../src/objects/star.h"
#include "../../../src/view/title.h"
#include "../../../src/view/background.h"
#include "../../../src/view/start.h"
#include <iostream>
#include <cilk/cilk.h>

const int DIMS[2] = {1920, 1080};
const float CENTER[2] = {DIMS[0]/2, DIMS[1]/2};
const float SPEED = 20.f;

int main(int argc, char const *argv[])
{
	srand(time(NULL));
	Clock clock;
	ContextSettings settings;
	settings.antialiasingLevel = 10;
	RenderWindow window(VideoMode(DIMS[0], DIMS[1]), "interstellar-test-env", Style::Default, settings);
	window.setFramerateLimit(60);


	background bg(DIMS[0], DIMS[1]);
	title banner(CENTER[0], CENTER[1]-60, "INTERSTELLAR", 80, 1);
	title startbanner(CENTER[0], CENTER[1]+60, "Click Anywhere to Start", 50, 1);

	spaceobject spaceship("Spaceships");
	spaceship.setType(11);
	spaceship.sp.setPosition(500,500);
	
	spaceobject spaceship2("Spaceships");

	start temp(2);

	//spaceship.setRotation(pt, 2);

	//planet testPlanet("Planets", 500, 500);
	planet test2(800,800);
	planet test3(300,300, 6);
	cout << test3.life << endl;
	cout << randomFloatBetween(1.0, 10.0) << endl;
	cout << "------------------" << endl;
	FloatRect bounds = spaceship.sp.getGlobalBounds();
	cout << bounds.left << endl;
	cout << bounds.top << endl;
	cout << "height: " << bounds.height << endl;
	cout << "width: " << bounds.width << endl;
	cout << "------------------" << endl;

	cout << spaceship.inWindow(DIMS[0], DIMS[1]) << endl;
	cout << spaceship2.inWindow(DIMS[0], DIMS[1]) << endl;

	cout << "------------------" << endl;
	Vector2f pt = spaceship.sp.getPosition();
	cout << pt.x << endl;
	cout << pt.y << endl;

	cilk_for(int i = 0; i < 10; i++)
	{
		cout << i << endl;
	}

	planet* t = new planet(1500, 700);
	t->setSattelites();
	// An array of pointers is written as a pointer of pointers:
	planet** tmp = new planet*[4];
	satellite** tmp2 = new satellite*[4];
	//planet* tmp = new planet[4];
	for (int i = 0; i < 4; ++i)
	{
		tmp[i] = new planet(randomInt(DIMS[0]), randomInt(DIMS[1]));
		tmp2[i] = new satellite(randomInt(DIMS[0]), randomInt(DIMS[1]));
		//tmp[i].sp.setPosition(randomInt(DIMS[0]), randomInt(DIMS[1]));
	}
	//planet.sp.setPosition(500, 500);

	star st(1920,1080);
	star st2(1920,1080);

	//star** stars =  new star*[20];
	star *stars[20];
	cilk_for (int i = 0; i < 20; ++i)
	{
		stars[i] = new star(1920,1080);
	}

	while (window.isOpen())
	{
		Event event;
		float delta = clock.restart().asSeconds();
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}

		}
		window.clear();
		//bg.update(window);
		spaceship.update(window, delta);
		spaceship2.update(window, delta);
		//st.update(window, delta);
		//st2.update(window, delta);
		cilk_for (int i = 0; i < 20; ++i)
		{
			stars[i]->update(window, delta);
		}
		//spaceship.sp.rotate(SPEED * delta);
		//window.draw(spaceship.sp);
		//test2.update(window, delta);
		//test3.update(window, delta); 
		t->update(window, delta);
		/*for (int i = 0; i < 4; ++i)
		{
			tmp[i]->update(window, delta);
			tmp2[i]->update(window, delta);
		}*/

		banner.update(window);
		//subtitle.update(window);
		startbanner.update(window);
		window.display();
	}
	delete [] tmp;
	delete [] tmp2;
	return 0;
}
	
	
	
	
	
