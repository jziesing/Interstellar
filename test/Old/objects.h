/*
 * This file includes 3 different objects (UFO, cannon, cannon ball) for similation.
 */

#include <utility>
#include <iostream>
#include <SFML/Graphics.hpp>

using namespace std;
using namespace sf;

class GeneralObject {
    protected:
        long x, y;                 // the (x, y) coordinate
        long x_velocity, y_velocity;
        Texture* textu;

    public:
        GeneralObject (){};
	
		//Different types to use when constructing: UFO, CANNON, BALL
        GeneralObject (long x, long y, long x_velocity, long y_velocity, string type){
            this->x = x;
            this->y = y;
            this->x_velocity = x_velocity;
            this->y_velocity = y_velocity;
            this->textu = new Texture();
            
            if(type=="UFO"){ 
            	if (this->textu->loadFromFile("Still3.png"))
				{}
			}
			if(type=="CANNON"){ //Different types to use UFO, CANNON, BALL
            	if (this->textu->loadFromFile("cannon.png"))
				{}
			}
        }
        
        Sprite* getSprite();
    
    	void set_velocity_values(long x_velocity, long y_velocity);
    	void set_position_values (long x, long y);
    	
		pair<long, long> get_velocity_values();
		void calculate_position(); 
		pair<long, long> get_position_values(); 
		 
        ~GeneralObject() {}
};

class UFO: public GeneralObject{
    public:
        UFO(long x, long y, long x_velocity, long y_velocity){
            this->x = x;
            this->y = y;
            this->x_velocity = x_velocity;
            this->y_velocity = y_velocity;
            //this->textu = new Texture();

        }

        ~UFO() {}
};

class Cannon_ball: private GeneralObject{
    public:
        Cannon_ball(long x, long y, long x_velocity, long y_velocity){
            this->x = x;
            this->y = y;
            this->x_velocity = x_velocity;
            this->y_velocity = y_velocity;
        }

        ~Cannon_ball() {}
};

class Cannon: private GeneralObject{
    public:
        Cannon(long x, long y, long x_velocity, long y_velocity){
            this->x = x;
            this->y = y;
            this->x_velocity = x_velocity;
            this->y_velocity = y_velocity;
        }

        ~Cannon() {}
};

/*
    Creates a random field by drawing from a bunch of vector points
 */
class field{
    public:
        field();
        ~field();
    
};



