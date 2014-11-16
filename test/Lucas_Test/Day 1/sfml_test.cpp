#include <SFML/Graphics.hpp>
using namespace sf;

int main(int argc, char const *argv[])
{
	RenderWindow window(VideoMode(800,600), "SFML works!");
	/*CircleShape triangle(80,3);
	CircleShape square(80,4);
	CircleShape octogon(80, 8);
	triangle.setFillColor(Color::Green);
	square.setFillColor(Color::Red);
	octogon.setFillColor(Color::Yellow);
	triangle.setPosition(10,10);
	square.setPosition(200,10);
	octogon.setPosition(400,10);*/
	CircleShape circle(3);
	CircleShape origin(3);
	circle.setPosition(300,300);
	origin.setPosition(400, 300);
	circle.setOrigin(400,300);
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
		/*window.draw(triangle);
		window.draw(square);
		window.draw(octogon);
		triangle.move(10, 0);*/
		window.draw(circle);
		window.draw(origin);
		//circle.setOrigin(400,300);
		circle.rotate(1);
		window.display();

	}

	return 0;
}