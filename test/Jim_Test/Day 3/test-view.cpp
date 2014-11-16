#include "../../../src/objects/spaceobject.h"
#include "../../../src/objects/planet.h"
#include "../../../src/objects/satellite.h"
#include "../../../src/objects/ufo.h"
#include "../../../src/objects/laser.h"
#include "../../../src/view/title.h"
#include "../../../src/view/background.h"
#include <iostream>

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

	background bg(DIMS[0], DIMS[1]);
	title banner(CENTER[0], CENTER[1]-60, "INTERSTELLAR", 80, 1);
	//title subtitle(CENTER[0], CENTER[1], "An Intergalactic Missle Defense System", 30, 0);
	title start(CENTER[0], CENTER[1]+60, "Click Anywhere to Start", 50, 1);

	spaceobject spaceship("Spaceships");
	spaceship.setType(11);
	Vector2f pt(500, 500);
	//spaceship.setRotation(pt, 2);

	//planet testPlanet("Planets", 500, 500);
	planet test2(800,800);
	planet test3(300,300, 6);
	cout << test3.life << endl;
	cout << randomFloatBetween(1.0, 10.0) << endl;

	planet* t = new planet(1500, 700);
	t->setSattelites();
	// An array of pointers is written as a pointer of pointers:
	planet** tmp = new planet*[4];
	satellite** tmp2 = new satellite*[4];
/* JIM */
	int laserNum = 0;
	laser** laserArray = (laser**) malloc(5*sizeof(laser*));
	ufo* ufoObject = new ufo(300, 300);
/* END-JIM */

	//planet* tmp = new planet[4];
	for (int i = 0; i < 4; ++i)
	{
		tmp[i] = new planet(randomInt(DIMS[0]), randomInt(DIMS[1]));
		tmp2[i] = new satellite(randomInt(DIMS[0]), randomInt(DIMS[1]));
		//tmp[i].sp.setPosition(randomInt(DIMS[0]), randomInt(DIMS[1]));
	}

	//planet.sp.setPosition(500, 500);

/* JIM */
	int ctr = 0;
/* END-JIM */

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
		
		bg.update(window);
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

/* JIM */
		// moving right
		if (ctr < 250){
			ufoObject->move(window, 2, delta);
			// check ammo capacity
			if (laserNum < MAX_NUM_OF_LASERS && ctr == 125){
				laserArray[laserNum] = ufoObject->shoot();
				laserNum++;
			}

		// moving down
		}else if (ctr < 500){
			ufoObject->move(window, 3, delta);
			// check ammo capacity
			if (laserNum < MAX_NUM_OF_LASERS && ctr == 375){
				laserArray[laserNum] = ufoObject->shoot();
				laserNum++;
			}

		// moving left
		}else if (ctr < 750){
			ufoObject->move(window, 0, delta);
			// check ammo capacity
			if (laserNum < MAX_NUM_OF_LASERS && ctr == 625){
				laserArray[laserNum] = ufoObject->shoot();
				laserNum++;
			}

		// moving up
		}else{
			ufoObject->move(window, 1, delta);
			// check ammo capacity
			if (laserNum < MAX_NUM_OF_LASERS && ctr == 875){
				laserArray[laserNum] = ufoObject->shoot();
				laserNum++;
			}
		}
		cout << ctr << endl;
		ctr = (ctr+1)%1000;

		for (int i = 0; i < laserNum; i++){
			laserArray[i]->update(window, delta);
		}
/* END-JIM */

		banner.update(window);
		//subtitle.update(window);
		start.update(window);
		window.display();
	}
	delete [] tmp;
	delete [] tmp2;
	return 0;
}
	
	
	
	
	
