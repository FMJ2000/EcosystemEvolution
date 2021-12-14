#ifndef _GAME_HPP
#define _GAME_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <vector>
#include <stdio.h>
#include <math.h>

#include "const.hpp"
#include "grass.hpp"

class Game: public sf::Drawable {
	private:
		float time;
		sf::RectangleShape land;
		char infoStr[STR_LEN];
		sf::Text info;
		std::vector<Grass> grass;
		virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

	public:
		sf::Font font;
		Game();
		~Game();
		void update(float dt);
		float getDistance(std::array<float, 2> pos1, std::array<float, 2> pos2);
};

#endif