#include "title.h"
#include <iostream>
#include <time.h>
#include "../objects/objects.cpp"

const int LOW = 300;
const int HIGH = 500;
const int DIMS[2] = {800, 600};
const int CENTER[2] = {DIMS[0]/2, DIMS[1]/2};

using namespace sf;
using namespace std;


/*
*This simulates UFOs flying and getting shot down
*
*/
class Simulator {
    public:
    	int num_UFO;
    	GeneralObject** UFO_arr;
    	GeneralObject** CANNON_arr;

    public:
        Simulator (int nUFO, int nTime){
        	this->num_UFO = nUFO;
        
        	// create UFOs
        	this->UFO_arr = (GeneralObject**) malloc ( nUFO * sizeof(GeneralObject*));
        	for (int i = 0; i < nUFO; i++){
        		this->UFO_arr[i] = new GeneralObject(0, 0, 1, 0, "UFO");
        	}
        	//create cannons--to be randomized eventaully (location and number)
        	this->CANNON_arr = (GeneralObject**) malloc (3*sizeof(GeneralObject*));//make 3 cannons
        	for (int i = 0; i < 3; i++){
        		this->CANNON_arr[i] = new GeneralObject(0, 0, 1, 0, "CANNON");
        	}
        };
		 
        ~Simulator() {
        	for (int i = 0; i < num_UFO; i++){
        		free(UFO_arr[i]);
        	}
        	free(UFO_arr);
        }
};




int main(int argc, char const *argv[])
{
	/*
	*Make the window look pretty
	 */
	 //_____________________________________________________________________________
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
  
	
	//Make an array of stars
	time_t seconds;
	time(&seconds);
	srand((unsigned int) seconds);
	int num_of_stars = rand() % (HIGH - LOW + 1) + LOW;
	CircleShape* stars = new CircleShape[num_of_stars];

	for (int i = 0; i < num_of_stars; ++i)
	{
		CircleShape shape(3);
		int xrand = rand() % (DIMS[0]);
		int yrand = rand() % (DIMS[1]);
		shape.setRadius(3);
		shape.setPosition(xrand, yrand);
		stars[i] = shape;
	}
	//_____________________________________________________________________________

	

	bool simulationStarted = false;
	float ct = 1.0;
	
	
	
	/*
	* enters main while loop.. if simulation hasnt started keep displaying home screen
	* if the simulation has been started go into the next while loop
	*/
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
		
		
		/*
		* if the simulation hasnt started, keep rotating the stars
		*/
		//____________________________________________________________________________
		if(!simulationStarted){
			window.clear();
			for (int i = 0; i < num_of_stars; i++)
			{
				window.draw(stars[i]);			
			}
			for (int i = 0; i < num_of_stars; i++)
			{
				Transform tr = stars[i].getTransform();
				Vector2f pst = stars[i].getPosition();
				tr.rotate(ct, CENTER[0], CENTER[1]).translate(pst.x, pst.y);
				window.draw(stars[i], tr);			
			}
			ct = ct + .009;
			window.draw(title);
			window.draw(subtitle);
			window.draw(start);
			window.display();
		}
		//____________________________________________________________________________
		
		
		/*
		* if the simulation has started, go into this while loop and being the simulation
		*create random number of UFOS
		*/
		//____________________________________________________________________________
		if(simulationStarted){
			Simulator simulator = Simulator(rand() % (HIGH - LOW + 1) + LOW, 60);
			
			while (window.isOpen())
			{
				Event event;
				while (window.pollEvent(event))
				{
					if (event.type == Event::Closed)
					{
						window.close();
					}
					if (event.type == Event::KeyPressed) {
						if (event.key.code == Keyboard::Up) {
							cout << "uhhh ohhh";

						}

					}
		
				}
				window.clear();
				/*draw UFOs
				*
				*a random number of UFOs fly across the screen (# determined above the sim. constructor)
				*current you cant exit the window once the simulation has started
				*
				*Do this part in parallel so every UFO is on a different thread?
				*/
				for(int j=0; j<simulator.num_UFO; j++){
					
					
					//for now, the number bounding i should be 800 divided by the number incrementing 
					//the UFO position: (800/UFO_pos.first)=(800/1)=800
					for(int i=0; i<800; i++){
						window.clear();
						
						
						/*
						*this block controls the UFOS
						*/
						Sprite * UFO_sprite = (simulator.UFO_arr[j])->getSprite();
						//pair<long, long> UFO_pos=(simulator.UFO_arr[j])->get_position_values();
						//move along the X-axis every iteration
						//(simulator.UFO_arr[j])->set_position_values(UFO_pos.first+1, UFO_pos.second );
						//UFO_sprite->setPosition(UFO_pos.first, 0);
						window.draw(*UFO_sprite);
						
						window.display();
					}
				}
			}
		}

	}
	return 0;
	delete [] stars;

}