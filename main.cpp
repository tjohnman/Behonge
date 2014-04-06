#include "includes.h"
#include "Root.h"

int main()
{
	sf::RenderWindow window(sf::VideoMode(800, 600), "Behonge", sf::Style::Close);
	sf::Event event;

	sf::Clock clock;
	float delta;

	window.setFramerateLimit(0);

	Root * root = Root::Instance();

	while(window.isOpen())
	{
		while(window.pollEvent(event))
		{
			if(event.type == sf::Event::Closed)
			{
				window.close();
				break;
			}
			else
			{
				root->onEvent(event);
			}
		}

		delta = clock.getElapsedTime().asSeconds();
		clock.restart();
		root->update(delta);


		window.clear();
		root->draw(&window);
		window.display();
	}

	return 0;
}
