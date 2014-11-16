#include <SFML/Graphics.hpp>
#include <stdlib.h>
#include <iostream>
#include <time.h>

const int LOW = 100;
const int HIGH = 300;
const int DIMS[2] = {800, 600};
const int CENTER[2] = {DIMS[0]/2, DIMS[1]/2};

using namespace sf;
using namespace std;

int main(int argc, char const *argv[])
{
	/*
	
	 */
	ContextSettings settings;
	settings.antialiasingLevel = 8;
	RenderWindow window(VideoMode(DIMS[0], DIMS[1]), "Interstellar", Style::Default, settings);
	
	/*
	
	 */
	Font font;
	font.loadFromFile("../styles/font/TerminusTTF-4.38.2.ttf");

	/*
	
	 */
	Text title("INTERSTELLAR", font);
	title.setCharacterSize(80);
	title.setStyle(Text::Italic);
	FloatRect textRect = title.getLocalBounds();
	title.setOrigin(textRect.left + textRect.width/2.0f, textRect.top + textRect.height/2.0f);
	title.setPosition(CENTER[0], CENTER[1]);
	
	/*
	
	 */
	RectangleShape textContainer;
	textContainer.setFillColor(Color::Transparent);
	textContainer.setOutlineColor(Color::White);
	textContainer.setOutlineThickness(3);
	textContainer.setSize(Vector2f(textRect.width, textRect.height));
	textRect = textContainer.getLocalBounds();
	textContainer.setOrigin(textRect.left + textRect.width/2.0f, textRect.top + textRect.height/2.0f);
	textContainer.setPosition(CENTER[0] + 9, CENTER[1]);

	/*
	
	 */
	Text subtitle("An Intergalactic Missile Defense System", font);
	subtitle.setCharacterSize(30);
	textRect = subtitle.getLocalBounds();
	subtitle.setOrigin(textRect.left + textRect.width/2.0f, textRect.top + textRect.height/2.0f);
	subtitle.setPosition(CENTER[0], CENTER[1] + 60);

	/*
	
	 */
	Text start("Simulate", font);
	start.setCharacterSize(30);
	textRect = start.getLocalBounds();
	start.setOrigin(textRect.left + textRect.width/2.0f, textRect.top + textRect.height/2.0f);
	start.setPosition(CENTER[0], CENTER[1] + 110);

	/*
	
	 */
	RectangleShape border;
	border.setFillColor(Color::Transparent);
	border.setOutlineColor(Color::White);
	border.setOutlineThickness(3);
	border.setSize(Vector2f(600, 300));
	textRect = border.getLocalBounds();
	border.setOrigin(textRect.left + textRect.width/2.0f, textRect.top + textRect.height/2.0f);
	border.setPosition(CENTER[0], CENTER[1] + 40);

	/*
	
	 */
	time_t seconds;
	time(&seconds);
	srand((unsigned int) seconds);
	int num_of_stars = rand() % (HIGH - LOW + 1) + LOW;
	CircleShape* stars = new CircleShape[num_of_stars];

	for (int i = 0; i < num_of_stars; ++i)
	{
		CircleShape shape(3);
		int xrand = rand() % DIMS[0];
		int yrand = rand() % DIMS[1];
		shape.setRadius(3);
		shape.setPosition(xrand, yrand);
		stars[i] = shape;
	}

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
		window.clear();
		for (int i = 0; i < num_of_stars; ++i)
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
	delete [] stars;
	return 0;
}