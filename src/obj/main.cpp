#include "../include/main.hpp"

int main() {
	sf::RenderWindow window(sf::VideoMode(W_WIDTH, W_HEIGHT), W_TITLE, sf::Style::Titlebar | sf::Style::Close);
	window.setVerticalSyncEnabled(true);
	window.setFramerateLimit(60);

	while (window.isOpen()) {
		sf::Event event;
		while (window.pollEvent(event)) {
			switch (event.type) {
				case sf::Event::Closed: {
					window.close();
					break;
				}
			}
		}
	}

	return 0;
}