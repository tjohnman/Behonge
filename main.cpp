#include "includes.h"
#include "Root.h"
#include "Audio.h"
#include "Graphics.h"

int main()
{
	// Create the window.
	sf::RenderWindow window(sf::VideoMode(800, 600), "Behonge", sf::Style::Close);
	sf::Event event;

	// Clock to calculate delta.
	sf::Clock clock;
	double delta;

	// I'll manage this, thanks.
	window.setFramerateLimit(0);

	// Our controller class.
	Root * root = Root::Instance();

	while(window.isOpen())
	{
		// By default clicking the close button will close the program.
		// Otherwise the controller gets the events.
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

		// Update game logic.
		delta = clock.getElapsedTime().asSeconds();
		clock.restart();
		root->update(delta);

		// Draw.
		window.clear();
		root->draw(&window);
		window.display();
	}

	// Unload assets
	Audio::Cleanup();
	Graphics::Cleanup();

	return 0;
}
