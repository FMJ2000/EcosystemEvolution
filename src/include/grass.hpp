#ifndef _GRASS_HPP
#define _GRASS_HPP

#include <SFML/Graphics.hpp>
#include <iostream>
#include <array>
#include <random>

#include "const.hpp"

class Game;

class Grass: public sf::Drawable {
	private:
		Game * parent;
		float time;					// time alive
		
		// status
		float growth;
		float seed;

		sf::CircleShape shape;
		virtual void draw(sf::RenderTarget &target, sf::RenderStates states) const;

	public:
		// genetic variables (%/s)
		std::array<float, GRASS_NUM_GENES> genes; // growRate, seedRate, maxAge
		std::array<char, 2> flag;		// dead, new
		std::array<float, 2> pos;
		std::array<float, 2> childPos;

		Grass(std::array<float, 2> pos, std::array<float, GRASS_NUM_GENES> rates);
		~Grass();
		void update(float dt);
};

#endif