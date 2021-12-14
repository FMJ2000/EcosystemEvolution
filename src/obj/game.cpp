#include "../include/game.hpp"

Game::Game() {
	// setup 
	this->time = 0l;

	// land
	this->land.setFillColor(sf::Color(LAND_COL));
	this->land.setPosition(sf::Vector2f(LAND_OFFSET, LAND_OFFSET));
	this->land.setSize(sf::Vector2f(LAND_SIZE, LAND_SIZE));
	this->land.setOutlineThickness(LAND_BORDER);
	this->land.setOutlineColor(sf::Color(BORDER_COL));

	// info
	this->font.loadFromFile(FONT_FILE);
	this->info.setFont(this->font);
	this->info.setPosition(sf::Vector2f(INFO_LEFT, INFO_TOP));
	this->info.setString("Time: 0s");

	// initial grass
	std::array<float, GRASS_NUM_GENES> genes = {
		GRASS_GROW_L + (float)rand() / RAND_MAX * (GRASS_GROW_H - GRASS_GROW_L),
		GRASS_SEED_L + (float)rand() / RAND_MAX * (GRASS_SEED_H - GRASS_SEED_L),
		GRASS_AGE_L + (float)rand() / RAND_MAX * (GRASS_AGE_H - GRASS_AGE_L),
		GRASS_SPREAD_L + (float)rand() / RAND_MAX * (GRASS_SPREAD_H - GRASS_SPREAD_L)
	};
	this->grass.push_back(Grass({500, 500}, genes));
}

Game::~Game() {

}

void Game::draw(sf::RenderTarget &target, sf::RenderStates states) const {
	target.draw(this->land);
	target.draw(this->info);

	for (int i = 0; i < this->grass.size(); i++) target.draw(this->grass[i]);
}

void Game::update(float dt) {
	this->time += dt;

	// organisms
	for (int i = 0; i < this->grass.size(); i++) {
		this->grass[i].update(dt);
		if (this->grass[i].flag[GRASS_FLAG_NEW]) {
			char valid = 1;
			for (int j = 0; j < this->grass.size() && valid; j++) {
				if (getDistance(this->grass[i].childPos, this->grass[j].pos) < GRASS_MAX_SIZE) valid = 0;				
			}
			
			if (valid) this->grass.push_back(Grass(this->grass[i].childPos, this->grass[i].genes));
			this->grass[i].flag[GRASS_FLAG_NEW] = 0;
		}
		if (this->grass[i].flag[GRASS_FLAG_DEAD]) this->grass.erase(this->grass.begin() + i);
	}

	// info
	snprintf(this->infoStr, STR_LEN, "Time: %.2f", this->time);
	this->info.setString(this->infoStr);
}

float Game::getDistance(std::array<float, 2> pos1, std::array<float, 2> pos2) {
	return sqrt(powf(pos1[0] - pos2[0], 2) + powf(pos1[1] - pos2[1], 2));
}