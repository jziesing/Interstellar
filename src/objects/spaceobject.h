#ifndef SPACEOBJECT_H
#define SPACEOBJECT_H
#include <SFML/Graphics.hpp>
#include "helper.h"
#include <string>
#include <iostream>

using namespace sf;
using namespace std;

/* spaceobject class.
 *
 * A base class for all game objects containing a texture and sprite for image to be drawn.
 * It allows for a structured OOP design when it comes to drawing all game objects for the 
 * game. SFML sprites already contain coordinates so spaceobject keeps track of speed, life and type of object it is.
 */
class spaceobject
{
public:
	// Speed use for drawing animations.
	float speed;

	// Life meter, number of collisions allowed.
	int life;

	// Represents number of ammo a spaceship of ufo has
	int ammo;

	// The string representation of type of spaceobject.
	string objectType;

	// The texture used for sprites.
	Texture tex;

	// The sprite used for animations by the window.
	Sprite sp;

	// Default constructor. Sets speed to 1.0 and life to 3.
	spaceobject();

	/* Constructor that sets objectType 
	 * @type string representation of type of spaceobject.
	 */
	spaceobject(string type);

	/* Constructor that sets objectType and position. 
	 * @type string representation of type of spaceobject.
	 * @x x integer coordinate of game window.
	 * @y y integer coordinate of game window.
	 */
	spaceobject(string, int x, int y);

	/* Constructor that sets objectType, position and sprite. 
	 * @type string representation of type of spaceobject.
	 * @x x integer coordinate of game window.
	 * @y y integer coordinate of game window.
	 * @idx the index of a sprite in the file structure, sprites zero indexed
	 */
	spaceobject(string, int x, int y, int idx);

	/* Virtual delegation initializer.
	 * @type string representation of type of spaceobject.
	 * 
	 * Initializes speed to 1.0, life to 3, and objectType. This will be overridden by 
	 * certain subclasses.
	 */
	virtual void init(string type);

	/* Updates the window by redrawing sprite.
	 * @window the current window displaying sprite animations.
	 * @delta the difference in time from last frame, frame rates aren't dedicated using 
	 * delta makes animations smoother and less choppy.
	 *
	 * Currently just draws the sprite, this will be overridden later with other game
	 * physics and logic.
	 */
	virtual void update(RenderWindow &window, float delta);

	/* Sets the type of spaceobject, loads texture, and creates sprite.
	 * @idx the index of a sprite in the file structure, sprites zero indexed
	 *
	 * Reads in directory of sprites, loads texture, sets to smooth. And then sets the
	 * sprite to the texture.
	 */
	void setType(int idx);

	/* Sets origin to center
	 *
	 */
	void setOriginToCenter();
	void setRotation(int x, int y, int radius);
 	bool inWindow();
	bool collision(Sprite othersprite);
	// Default destructor.
	~spaceobject() {};
};
#endif