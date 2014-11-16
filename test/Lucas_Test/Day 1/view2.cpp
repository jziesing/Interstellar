#include <SFML/Graphics.hpp>
#include <iostream>
#include "title.h"

const int LOW = 100;
const int HIGH = 300;
const int DIMS[2] = {800, 600};
const int CENTER[2] = {DIMS[0]/2, DIMS[1]/2};
const float SPEED = 20.f;

using namespace sf;
using namespace std;

int main(int argc, char const *argv[])
{
	
	Clock clock;
	bool simStart = false;
	ContextSettings settings;
	settings.antialiasingLevel = 10;
	RenderWindow window(VideoMode(DIMS[0], DIMS[1]), "interstellar-test-env", Style::Default, settings);

	 

	Texture testText;
	testText.loadFromFile("../../styles/images/Infinity-Icons/PNG/NASA/untitled-41.png");

	Sprite testSprite;
	testSprite.setTexture(testText);
	
	Texture meteorText;
	meteorText.loadFromFile("../../styles/images/SpaceShooterRedux/PNG/Meteors/meteorBrown_small1.png");
	Texture meteorText1;
	meteorText1.loadFromFile("../../styles/images/SpaceShooterRedux/PNG/Meteors/meteorBrown_small2.png");
	Texture meteorText2;
	meteorText2.loadFromFile("../../styles/images/SpaceShooterRedux/PNG/Meteors/meteorBrown_tiny1.png");
	Texture meteorText3;
	meteorText3.loadFromFile("../../styles/images/SpaceShooterRedux/PNG/Meteors/meteorBrown_tiny2.png");

	Texture ufoText;
	ufoText.loadFromFile("../../styles/images/SpaceShooterRedux/PNG/ufoBlue.png");
	Texture ufoText1;
	ufoText1.loadFromFile("../../styles/images/SpaceShooterRedux/PNG/ufoGreen.png");
	Texture ufoText2; 
	ufoText2.loadFromFile("../../styles/images/SpaceShooterRedux/PNG/ufoRed.png");
	Texture ufoText3;
	ufoText3.loadFromFile("../../styles/images/SpaceShooterRedux/PNG/ufoYellow.png");


	title banner(CENTER[0], CENTER[1]);
	banner.initFont("../../styles/font/TerminusTTF-4.38.2.ttf");
	Text title = banner.createTitle("INTERSTELLAR", 80, 1);
	Text subtitle = banner.createTitle("An Intergalactic Missle Defense System", 30, 0);
	subtitle.setStyle(Text::Italic);
	Text start = banner.createTitle("Simulate", 30, 0);

	title.setPosition(CENTER[0], CENTER[1] - 60);
	start.setPosition(CENTER[0], CENTER[1] + 60);

	RectangleShape border;
	border.setFillColor(Color::Transparent);
	border.setOutlineColor(Color::White);
	border.setOutlineThickness(3);
	border.setSize(Vector2f(150, 50));
	FloatRect textRect = border.getLocalBounds();
	border.setOrigin(textRect.left + textRect.width/2.0f, textRect.top + textRect.height/2.0f);
	border.setPosition(CENTER[0], CENTER[1] + 60);

	//Make an array of stars	
	time_t seconds;
	time(&seconds);
	srand((unsigned int) seconds);
	int num_of_stars = rand() % (HIGH - LOW + 1) + LOW;
	CircleShape* stars = new CircleShape[num_of_stars];

	//Make an array of meteors	
	int num_of_meteors = 20;
	Sprite* meteors = new Sprite[num_of_meteors];

	//Make an array of ufos	
	int num_of_ufos = 3;
	Sprite* ufos = new Sprite[num_of_ufos];


	for (int i = 0; i < num_of_stars; ++i)
	{
		CircleShape shape(3);
		shape.setPosition(CENTER[0], CENTER[1]);
		shape.setOrigin(rand() % DIMS[0], rand() % DIMS[1]);
		shape.setRotation(rand() % 360);
		stars[i] = shape;
	}

	for (int i = 0; i < num_of_meteors; ++i)
	{
		Sprite meteor;
		int choice = rand() % 4;
		if (choice == 0)
			meteor.setTexture(meteorText);
		if (choice == 1)
			meteor.setTexture(meteorText1);
		if (choice == 2)
			meteor.setTexture(meteorText2);
		if (choice == 3)
			meteor.setTexture(meteorText3);
		meteor.setPosition(CENTER[0], CENTER[1]);
		meteor.setOrigin(rand() % DIMS[0], rand() % DIMS[1]);
		meteor.setRotation(rand() % 360);
		meteors[i] = meteor;
	}

	for (int i = 0; i < num_of_ufos; ++i)
	{
		Sprite ufo;
		int choice = rand() % 4;
		if (choice == 0)
			ufo.setTexture(ufoText);
		if (choice == 1)
			ufo.setTexture(ufoText1);
		if (choice == 2)
			ufo.setTexture(ufoText2);
		if (choice == 3)
			ufo.setTexture(ufoText3);
		ufo.setPosition(CENTER[0], CENTER[1]);
		ufo.setOrigin(rand() % DIMS[0], rand() % DIMS[1]);
		ufo.setRotation(rand() % 360);
		ufo.setScale(0.7,0.7);
		ufos[i] = ufo;
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

			if (event.type == Event::MouseButtonPressed)
			{
				simStart = true;
			}
		}

		window.clear();
		window.draw(background);
		window.draw(testSprite);
		if (simStart == false)
		{
			window.draw(title);
			window.draw(subtitle);
			window.draw(start);
			window.draw(border);
			for (int i = 0; i < num_of_stars; ++i)
			{
				stars[i].rotate(SPEED * delta);
				window.draw(stars[i]);
			}
			for (int i = 0; i < num_of_meteors; ++i)
			{
				meteors[i].rotate(SPEED * delta);
				window.draw(meteors[i]);
			}
			for (int i = 0; i < num_of_ufos; ++i)
			{
				ufos[i].rotate(SPEED * delta);
				window.draw(ufos[i]);
			}
		}	
		if (simStart == true) 
		{
			for (int i = 0; i < num_of_stars; ++i)
			{
				Vector2f position = stars[i].getOrigin();
				stars[i].setOrigin(position.x+1, position.y);
				window.draw(stars[i]);
			}
			for (int i = 0; i < num_of_stars; ++i)
			{
				Vector2f position = stars[i].getOrigin();
				stars[i].setOrigin(position.x, position.y-1);
				window.draw(stars[i]);
			}

			for (int i = 0; i < num_of_meteors; ++i)
			{
				Vector2f position = meteors[i].getOrigin();
				meteors[i].setOrigin(position.x+1, position.y);
				window.draw(meteors[i]);
			}
			for (int i = 0; i < num_of_meteors; ++i)
			{
				Vector2f position = meteors[i].getOrigin();
				meteors[i].setOrigin(position.x, position.y-1);
				window.draw(meteors[i]);
			}

			for (int i = 0; i < num_of_ufos; ++i)
			{
				Vector2f position = ufos[i].getOrigin();
				ufos[i].setOrigin(position.x+1, position.y);
				window.draw(ufos[i]);
			}
			for (int i = 0; i < num_of_ufos; ++i)
			{
				Vector2f position = ufos[i].getOrigin();
				ufos[i].setOrigin(position.x, position.y-1);
				window.draw(ufos[i]);
			}
		}	
		window.display();
	}
	return 0;
}