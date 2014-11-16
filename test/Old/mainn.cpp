#include "title.h"
#include <iostream>
#include <time.h>
#include "../objects/objects.cpp"

const int LOW = 100;
const int HIGH = 300;
const int DIMS[2] = {800, 600};
const int CENTER[2] = {DIMS[0]/2, DIMS[1]/2};

<<<<<<< HEAD
=======
using namespace sf;
using namespace std;

class Simulator {
    public:
    	int num_UFO;
    	GeneralObject** UFO_arr;

    public:
        Simulator (int nUFO, int nTime){
        	this->num_UFO = nUFO;
        
        	// create UFOs
        	this->UFO_arr = (GeneralObject**) malloc ( nUFO * sizeof(GeneralObject*));
        	for (int i = 0; i < nUFO; i++){
        		this->UFO_arr[i] = new GeneralObject(0, 0, 1, 0);
        	}
        };
		 
        ~Simulator() {
        	for (int i = 0; i < num_UFO; i++){
        		free(UFO_arr[i]);
        	}
        	free(UFO_arr);
        }
};





>>>>>>> 7ba24a2eddf692b74d7a26e70cd5434504750421
int main(int argc, char const *argv[])
{
	/*
	
	 */
	ContextSettings settings;
	settings.antialiasingLevel = 8;
	RenderWindow window(VideoMode(DIMS[0], DIMS[1]), "Interstellar", Style::Default, settings);

	title banner(CENTER[0], CENTER[1]);
	banner.initFont("../styles/font/TerminusTTF-4.38.2.ttf");

	Text title = banner.createTitle("INTERSTELLAR", 80, 1);
	Text subtitle = banner.createTitle("An Intergalactic Missle Defense System", 30, 0);
	Text start = banner.createTitle("Simulate", 30, 0);

	subtitle.setPosition(CENTER[0], CENTER[1] + 60);
	start.setPosition(CENTER[0], CENTER[1] + 110);

	time_t seconds;
	time(&seconds);
	srand((unsigned int) seconds);
	int num_of_stars = rand() % (HIGH - LOW + 1) + LOW;
	CircleShape* stars = new CircleShape[num_of_stars];

	Transform t;
	t.rotate(10, CENTER[0]/2, CENTER[1]/2);

	for (int i = 0; i < num_of_stars; ++i)
	{
		CircleShape shape(3);
		int xrand = rand() % DIMS[0];
		int yrand = rand() % DIMS[1];
		shape.setRadius(3);
		shape.setPosition(xrand, yrand);
		stars[i] = shape;
	}
	
<<<<<<< HEAD
	float ct = 1.0;
=======
	bool simulationStarted = false;

>>>>>>> 7ba24a2eddf692b74d7a26e70cd5434504750421
	while (window.isOpen())
	{
		Event event;
		
		while (window.pollEvent(event))
		{
			if(event.type == Event::MouseButtonPressed){
				simulationStarted = true;
				window.clear();
				window.display();
			}
			if (event.type == Event::Closed)
			{
				window.close();
			}

		}
		window.clear();
		
<<<<<<< HEAD
		for (int i = 0; i < num_of_stars; ++i)
		{
			Transform tr = stars[i].getTransform();
			Vector2f pst = stars[i].getPosition();
			tr.rotate(ct, CENTER[0]/2, CENTER[1]/2).translate(pst.x, pst.y);
			window.draw(stars[i], tr);
			//stars[i].rotate(10);
			//stars[i].setOrigin(CENTER[0]/2,CENTER[1]/2);
			//stars[i].rotate(.01);
			/*stars[i].move(0.5,0.5);
			Vector2f pt = stars[i].getPosition();
			float tmpx = CENTER[0] - pt.x;
			float tmpy = CENTER[1] - pt.y;
			float slope = tmpx/tmpy;
			cout<<slope<<endl;*/
		}
		ct = ct + .01;
		window.draw(title);
		window.draw(subtitle);
		window.draw(start);
		window.display();
=======
		// shows start screen if simulation hasnt been started
		if(!simulationStarted){
			for (int i = 0; i < stars.size(); ++i)
			{
				window.draw(stars[i]);
			}
			window.draw(title);
			window.draw(subtitle);
			window.draw(textContainer);
			window.draw(start);
			window.draw(startTextContainer);
			window.draw(border);
			window.display();
		}
		
		//start simulation
		if(simulationStarted){
			Simulator simulator = Simulator(4, 60);
			
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
				
				// draw UFOs
				Sprite * sprite = (simulator.UFO_arr[0])->getSprite();
				window.draw(*sprite);
				//sprite.move(10, 0);
				window.draw(*sprite);
				window.display();
			}
		}
		
		
		

>>>>>>> 7ba24a2eddf692b74d7a26e70cd5434504750421
	}
	return 0;
	delete [] stars;

}