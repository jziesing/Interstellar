#include "../../../src/objects/spaceobject.h"
#include "../../../src/objects/planet.h"
#include "../../../src/objects/satellite.h"
#include "../../../src/objects/star.h"
#include "../../../src/view/title.h"
#include "../../../src/view/background.h"
#include "../../../src/objects/ufo.h"
#include "../../../src/objects/laser.h"
#include <string.h>
#include <iostream>
#include <math.h>
//#i//nclude <SFML/Window.hpp>
//#include <X11/Xlib.h>
//using namespace System;


const float DIMS[2] = {1920, 1080};
const float CENTER[2] = {DIMS[0]/2, DIMS[1]/2};
const float SPEED = 20.f;

int main(int argc, char const *argv[])
{
	//XInitThreads();
	srand(time(NULL));
	Clock clock;
	ContextSettings settings;
	settings.antialiasingLevel = 10;
	RenderWindow window(VideoMode(DIMS[0], DIMS[1]), "interstellar-test-env", Style::Default, settings);
	window.setFramerateLimit(60);

	
	//Background -----------------------------------------
	background bg(DIMS[0], DIMS[1]);
	title banner(CENTER[0], CENTER[1]-60, "Interstellar", 80, 1);
	title start(CENTER[0], CENTER[1]+60, "Click Anywhere to Start", 50, 1);

	spaceobject spaceship("Spaceships");
	spaceship.setType(11);
	spaceship.sp.setPosition(500,500);
	
	spaceobject spaceship2("Spaceships");

	//spaceship.setRotation(pt, 2);

	//planet testPlanet("Planets", 500, 500);
	planet test2(800,800);
	planet test3(300,300, 6);
	FloatRect bounds = spaceship.sp.getGlobalBounds();
	Vector2f pt = spaceship.sp.getPosition();

	planet* t = new planet(1500, 700);
	t->setSattelites();
	// An array of pointers is written as a pointer of pointers:
	planet** tmp = new planet*[4];
	satellite** tmp2 = new satellite*[4];

	//setup ships
	int numberOfUfos = 0;
	numberOfUfos = atoi(argv[1]);
	//doesn't work yet
	if (numberOfUfos < 1 || !numberOfUfos || &numberOfUfos == NULL) {
		cout << "add params with number of ufos" << endl;
		return 0;
	}

	int laserNum = 0;
	laser** laserArray = (laser**) calloc(numberOfUfos, sizeof(laser*));
	ufo** ufoAr = new ufo*[numberOfUfos];

	for (int i=0; i<numberOfUfos; i++) {
		
		ufoAr[i] = new ufo(randomIntBetween(1630, 70), randomIntBetween(860, 45));
	}
	//planet* tmp = new planet[4];
	for (int i = 0; i < 4; ++i)
	{
		tmp[i] = new planet(randomInt(DIMS[0]), randomInt(DIMS[1]));
		tmp2[i] = new satellite(randomInt(DIMS[0]), randomInt(DIMS[1]));
	}
	star st(1920,1080);
	star st2(1920,1080);
	bool sim = false;
	// ------------------------------------
	while (window.isOpen())
	{
		//events
		Event event;
		float delta = clock.restart().asSeconds();
		while (window.pollEvent(event))
		{
			if (event.type == Event::Closed)
			{
				window.close();
			}
			if(event.type == Event::MouseButtonPressed){
				window.clear();
				sim = true;
			}
		}
		//intro screen
		if (!sim) {
			bg.update(window);
			spaceship.update(window, delta);
			spaceship2.update(window, delta);
			st.update(window, delta);
			st2.update(window, delta);		
			t->update(window, delta);
			banner.update(window);
			start.update(window);
			window.display();
		//simulation
		} else {
			/*
			 * First: shoot closest ship one by one
			 * Second: move ship away from nearest object (ship or laser)
			 * Third: check for collision, update accordingly
			 */
			bg.update(window);
			//----------------SHOOT-----------------------------
			if (numberOfUfos > 1) {
				for (int i=0; i<numberOfUfos; i++) {
					// if (ufoAlive[i]) {
						// check whether there is laser, shoots first shot
						if (!laserArray[i]){
							// find where to shoot at
							Vector2f curPos = ufoAr[i]->sp.getPosition();
							ufo* closestUFO;
							float mindist = 99999;
							Vector2f shootAngle = Vector2f(0.0, 0.0);
							for (int j=0; j<numberOfUfos; j++) {
								if (i != j) {
									Vector2f otherPos = ufoAr[j]->sp.getPosition();
									float distance = sqrt(pow ((curPos.x - otherPos.x), 2.0) + pow ((curPos.y - otherPos.y), 2.0)); 
									if (distance < mindist){
										shootAngle.x = (otherPos.x - curPos.x) / sqrt(pow ((curPos.x - otherPos.x), 2.0) + pow ((curPos.y - otherPos.y), 2.0));
										shootAngle.y = (otherPos.y - curPos.y) / sqrt(pow ((curPos.x - otherPos.x), 2.0) + pow ((curPos.y - otherPos.y), 2.0));
										mindist = distance;
										closestUFO = ufoAr[j];
									}
								}
							}
							laserArray[i] = ufoAr[i]->shoot(shootAngle.x, shootAngle.y);
						} else {
							//shoot second and others
							if (!laserArray[i]->inWindow()) {
								//deallocate laser
								delete laserArray[i];
								Vector2f curPos = ufoAr[i]->sp.getPosition();
								ufo* closestUFO;
								float mindist = 99999;
								Vector2f shootAngle = Vector2f(0.0, 0.0);
								for (int j=0; j<numberOfUfos; j++) {
									if (i != j) { 
										Vector2f otherPos = ufoAr[j]->sp.getPosition();
										float distance = sqrt(pow ((curPos.x - otherPos.x), 2.0) + pow ((curPos.y - otherPos.y), 2.0)); 
										if (distance < mindist){
											shootAngle.x = (otherPos.x - curPos.x) / sqrt(pow ((curPos.x - otherPos.x), 2.0) + pow ((curPos.y - otherPos.y), 2.0));
											shootAngle.y = (otherPos.y - curPos.y) / sqrt(pow ((curPos.x - otherPos.x), 2.0) + pow ((curPos.y - otherPos.y), 2.0));
											mindist = distance;
											closestUFO = ufoAr[j];
										} 
									}
								}
								laserArray[i] = ufoAr[i]->shoot(shootAngle.x, shootAngle.y);

							}
						}
					// }
				}
				// ----------------MOVE---------
				// move all ships one by one
				//parallelized this for
				for (int i=0; i<numberOfUfos; i++) {
					// check to make sure it hasn't colided
					// if (ufoAlive[i]) {  
						Vector2f curPos = ufoAr[i]->sp.getPosition();
						float mindist = 99999;
						Vector2f shootAngle = Vector2f(0.0, 0.0);
						for(int j=0; j<numberOfUfos; j++) {
								if (i != j){
									Vector2f otherPos = ufoAr[j]->sp.getPosition();
									float distance = sqrt(pow ((curPos.x - otherPos.x), 2.0) + pow ((curPos.y - otherPos.y), 2.0)); 
									if (distance < mindist){
										shootAngle.x = (otherPos.x - curPos.x) / sqrt(pow ((curPos.x - otherPos.x), 2.0) + pow ((curPos.y - otherPos.y), 2.0));
										shootAngle.y = (otherPos.y - curPos.y) / sqrt(pow ((curPos.x - otherPos.x), 2.0) + pow ((curPos.y - otherPos.y), 2.0));
										mindist = distance;
									} 
									otherPos = laserArray[j]->sp.getPosition();
									distance = sqrt(pow ((curPos.x - otherPos.x), 2.0) + pow ((curPos.y - otherPos.y), 2.0)); 
									if (distance < mindist){
										shootAngle.x = (otherPos.x - curPos.x) / sqrt(pow ((curPos.x - otherPos.x), 2.0) + pow ((curPos.y - otherPos.y), 2.0));
										shootAngle.y = (otherPos.y - curPos.y) / sqrt(pow ((curPos.x - otherPos.x), 2.0) + pow ((curPos.y - otherPos.y), 2.0));
										mindist = distance;
									} 
								}
						}	
						
						// checking boundary
						if (curPos.x - 70 < mindist) {
							shootAngle.x = -1;
							shootAngle.y = 0;
							mindist = curPos.x - 70;
						}	
						if (curPos.y - 45 < mindist) {
							shootAngle.x = 0;
							shootAngle.y = -1;
							mindist = curPos.y - 45;
						}
						if (1630 - curPos.x < mindist) {
							shootAngle.x = 1;
							shootAngle.y = 0;
							mindist = 1630 - curPos.x;
						}
						if (860 - curPos.y < mindist) {
							shootAngle.x = 0;
							shootAngle.y = 1;
							mindist = 860 - curPos.y;
						}	
						if (shootAngle.x > shootAngle.y) {
							// if y negative up
							if (shootAngle.y <0){
								ufoAr[i]->move(window, 3, delta);
							}else{
								ufoAr[i]->move(window, 1, delta);
							}
						} else {
							// neg left
							if (shootAngle.x <0){
								ufoAr[i]->move(window, 2, delta);
							}else{
								ufoAr[i]->move(window, 0, delta);
							}
						}
					// }
				}
				//can't parallelize
				for (int ii=0; ii<numberOfUfos; ii++) {
					ufoAr[ii]->update(window, delta);
				}

				//check collusion here
				bool ufoAlive[numberOfUfos] ;
				bool laserAlive[numberOfUfos];
				for (int n=0; n< numberOfUfos; n++) {
					ufoAlive[n] = true;
					laserAlive[n] = true;
				}

				// for each UFO
				for (int i=0; i<numberOfUfos; i++) {
					//collision with ufos
					

					for(int j=0; j<numberOfUfos; j++) {
						if (i != j) { 
							if(ufoAr[i]->collision(ufoAr[j]->sp)) {
								ufoAlive[j] = false;
							}
						}
					}
					

					//collision with lasers
					
					for(int j=0; j<numberOfUfos; j++) {
						if (i != j) { 
							if(ufoAr[i]->collision(laserArray[j]->sp)) {
								laserAlive[j] = false;
							}
						}
					}
				}

				int updateUFONumber = 0;

				for (int i=0; i<numberOfUfos; i++) {
					if (ufoAlive[i]){
						updateUFONumber++;
					}
				}

				int arrayIndex = 0;
				ufo** newUFOArray = (ufo**) calloc(updateUFONumber, sizeof(ufo*));
				laser** newLaserArray = (laser**) calloc(updateUFONumber, sizeof(laser*));

				for (int i=0; i<numberOfUfos; i++) {
					if (ufoAlive[i]){
						newUFOArray[arrayIndex] = ufoAr[i];
						if (laserAlive[i]){
							newLaserArray[arrayIndex] = laserArray[i];
						}else{
							newLaserArray[arrayIndex] = NULL;
						}
						arrayIndex++;
					}
				}

				numberOfUfos = updateUFONumber;
				delete [] ufoAr;
				delete [] laserArray;
				ufoAr = newUFOArray;
				laserArray = newLaserArray;

				//display lasers
				for (int i=0; i<numberOfUfos; i++) {
					if (laserArray[i])
						laserArray[i]->update(window, delta);
				}
			// battle settled
			}else {
				if(numberOfUfos == 1) {
					window.clear();
					bg.update(window);
					title banner(CENTER[0], CENTER[1]-60, "Winner", 80, 1);
					banner.update(window);
					ufoAr[0]->sp.setPosition(775, 475);
					ufoAr[0]->update(window, delta);	
				} else {
					window.clear();
					bg.update(window);
					title banner(CENTER[0], CENTER[1]-60, "No Winners", 80, 1);
					banner.update(window);
				}
			}


			window.display();
		}
		
	}
	delete [] tmp;
	delete [] tmp2;
	return 0;
}
	
	
	
	
	
