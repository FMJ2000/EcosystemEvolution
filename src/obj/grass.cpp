#include "../include/grass.hpp"

// genes = { growRate, seedRate, maxAge }
Grass::Grass(std::array<float, 2> pos, std::array<float, GRASS_NUM_GENES> genes):
	pos(pos), time(0), growth(0), seed(0), shape(GRASS_MAX_SIZE, 3) {
	
	// gene variation
	for (int i = 0; i < GRASS_NUM_GENES; i++) this->genes[i] = genes[i] - GRASS_VAR + (float)rand() / RAND_MAX * 2 * GRASS_VAR;
	for (int i = 0; i < GRASS_NUM_FLAGS; i++) this->flag[i] = 0;

	// shape
	this->shape.setFillColor(sf::Color(GRASS_COL));
	this->shape.setOutlineThickness(2);
	this->shape.setOutlineColor(sf::Color::Black);
	this->shape.setPosition(sf::Vector2f(pos[0], pos[1]));
	this->shape.setOrigin(sf::Vector2f(GRASS_MAX_SIZE, 1.5*GRASS_MAX_SIZE));
}

Grass::~Grass() {

}

void Grass::draw(sf::RenderTarget &target, sf::RenderStates states) const {
	target.draw(this->shape);
}

void Grass::update(float dt) {
	this->time += dt;
	if (this->time > this->genes[GRASS_GENE_AGE]) {
		this->flag[GRASS_FLAG_DEAD] = 1;
		return;
	}

	if (this->growth < GROW_MAX) {
		this->growth += this->genes[GRASS_GENE_GROW] * dt;
		if (this->growth > GROW_MAX) this->growth = GROW_MAX;
		this->shape.setScale(sf::Vector2f(this->growth, this->growth));
	} else {
		this->seed += dt;
		if (this->seed >= this->genes[GRASS_GENE_SEED]) {
			this->flag[GRASS_FLAG_NEW] = 1;
			for (int i = 0; i < 2; i++) {
				this->childPos[i] = this->pos[i] - this->genes[GRASS_GENE_SPREAD] + (float)rand() / RAND_MAX * 2 * this->genes[GRASS_GENE_SPREAD];
				if (this->childPos[i] < LAND_OFFSET) this->childPos[i] = 2*LAND_OFFSET;
				if (this->childPos[i] >= LAND_OFFSET + LAND_SIZE) this->childPos[i] = LAND_SIZE;
			}
			this->seed = 0;
		}
	}
}