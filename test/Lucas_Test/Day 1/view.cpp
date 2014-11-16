#include <SFML/Graphics.hpp>
#include <iostream>
#include "title.h"

const int LOW = 500;
const int HIGH = 800;
const int DIMS[2] = {800, 600};
const int CENTER[2] = {DIMS[0]/2, DIMS[1]/2};
const float SPEED = 20.f;

using namespace sf;
using namespace std;

int main(int argc, char const *argv[])
{
	bool simStart = false;
	Clock clock;
	ContextSettings settings;
	settings.antialiasingLevel = 10;
	RenderWindow window(VideoMode(DIMS[0], DIMS[1]), "interstellar-test-env", Style::Default, settings);

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

	
	for (int i = 0; i < num_of_stars; ++i)
	{
		CircleShape shape(3);
		shape.setPosition(CENTER[0], CENTER[1]);
		shape.setOrigin(rand() % DIMS[0], rand() % DIMS[1]);
		shape.setRotation(rand() % 360);
		stars[i] = shape;
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
		if (simStart == false)
		{
			window.draw(title);
			window.draw(subtitle);
			window.draw(start);
			window.draw(border);
			for (int i = 0; i < num_of_stars; ++i)
			{
				//This causes problems, due to inconsistent frame rate
				//stars[i].rotate(0.05);
				stars[i].rotate(SPEED * delta);
				window.draw(stars[i]);
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
		}	
		window.display();
	}
	return 0;
}