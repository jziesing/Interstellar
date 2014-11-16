#include <SFML/Graphics.hpp>
#include <cilk/cilk.h>
#include <ctime>
#include "../../../src/objects/spaceobject.h"
#include "../../../src/objects/star.h"

using namespace sf;

int main(int argc, char const *argv[])
{
	srand(time(NULL));
	ContextSettings settings;
	settings.antialiasingLevel = 10;
	RenderWindow window(VideoMode(800, 800), "interstellar-parallel-test-env", Style::Default, settings);
	window.setFramerateLimit(60);

	star *st[10];
	cilk_for (int i = 0; i < 10; ++i)
	{
		st[i] = new star();
		st[i]->sp.setPosition(400, 400);
	}

	CircleShape shape(10);
    shape.setFillColor(Color::Green);

    while (window.isOpen())
    {
        Event event;
        while (window.pollEvent(event))
        {
            if (event.type == Event::Closed)
                window.close();
        }

        window.clear();
        window.setActive(false);
        window.draw(shape);
        for (int i = 0; i < 10; ++i)
        {
            window.setActive(true);
        	window.draw(st[i]->sp);
            window.setActive(false);
        }
        window.display();
    }
	return 0;
}
