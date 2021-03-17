#include <SFML/Graphics.hpp>
#include <iostream>
#include <deque>
#include <thread>>
#include <time.h>
#include "Gradient.h"

using namespace sf;
int Width = 1200, Height = 800;	//window size

RenderWindow window;

int main()
{
	Color cr = Color(240,240,240);
	std::cout << (int)Uint8(cr.g);

	window.create(VideoMode(Width, Height), "SNAKE");
	window.clear(cr);

	window.setFramerateLimit(60);

	Gradient grad = Gradient(Color::Red, 512, 255);
	grad.Display(window, 100, 100);
	
	Event event;

	window.display();

	while (window.isOpen())
	{

		while (window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed) window.close();
		}
		
		// Выполняем необходимые действия по отрисовке
	}

	return 0;
}