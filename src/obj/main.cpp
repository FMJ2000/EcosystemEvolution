#include "../include/main.hpp"

int main() {
	srand(time(0));

	Game game;

	sf::RenderWindow window(sf::VideoMode(W_WIDTH, W_HEIGHT), W_TITLE, sf::Style::Titlebar | sf::Style::Close);
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(FRAME_RATE);
	sf::Clock clock;

	while (window.isOpen()) {
		float dt = clock.restart().asSeconds();
		sf::Event event;
		while (window.pollEvent(event)) {
			switch (event.type) {
				case sf::Event::Closed: {
					window.close();
					break;
				}

				case sf::Event::KeyPressed: {
					if (event.key.code == sf::Keyboard::Q) window.close();
					break;
				}
			}
		}

		game.update(dt);
		window.clear(sf::Color(BACKGROUND_COL));
		window.draw(game);
		window.display();
	}

	return 0;
}