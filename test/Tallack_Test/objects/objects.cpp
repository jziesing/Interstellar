/*
 * This file includes 3 different objects (UFO, cannon, cannon ball) for similation.
 */

#include "objects.h"

void GeneralObject::set_velocity_values (long x_velocity, long y_velocity){
	this->x_velocity = x_velocity;
	this->y_velocity = y_velocity;
}

pair<long, long> GeneralObject::get_velocity_values(){
	return make_pair(x_velocity, y_velocity);
}

/*
 * This function calculate the UFO position after this iteration.
 */
void GeneralObject::calculate_position(){
	this->x = x + x_velocity;
	this->y = y + y_velocity;
}

Sprite* GeneralObject::getSprite() {
	return new Sprite(*(this->textu));
}

/*
 * This function returns a pair with the position information.
 */
pair<long, long> GeneralObject::get_position_values(){
	return make_pair(this->x, this->y);
}

		
// int main () {
//    UFO* ufo1 = new UFO(5,5, 0, 0);
//     for (int i = 0; i < 50; i++){
//         // set the velocity
//         ufo1->set_velocity_values(i,50-i),
// 
//         // calculate the position after this iteration
//         ufo1->calculate_position();
// 
//         // get the position of the UFO
//         pair<long, long> newPos = ufo1->get_position_values();
//         
//         // prints out the position
//         cout << "x: " << newPos.first << ", y: " << newPos.second << endl;
//     }
// 
//     delete ufo1;
//     return 0;
// }




