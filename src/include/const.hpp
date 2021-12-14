#ifndef _CONST_HPP
#define _CONST_HPP

// files
#define FONT_FILE "textures/arial.ttf"

// layout
#define FRAME_RATE 30
#define W_WIDTH 1600
#define W_HEIGHT 900
#define W_TITLE "yeomann"
#define LAND_OFFSET 50
#define LAND_SIZE 800
#define LAND_BORDER 20
#define INFO_LEFT 1000
#define INFO_TOP 50

// const
#define STR_LEN 200
enum Specie { GRASS, RABBIT, DEER, FOX, LION, EAGLE };
const char predator[6][6] = {
	{0, 0, 0, 0, 0, 0},
	{1, 0, 0, 0, 0, 0},
	{1, 0, 0, 0, 0, 0},
	{0, 1, 0, 0, 0, 0},
	{0, 0, 1, 1, 0, 0},
	{0, 1, 0, 1, 0, 0}
};
#define GROW_MAX 1.0
#define SEED_MAX 1.0

// grass
#define GRASS_MAX_SIZE 20
#define GRASS_GROW_L 0.2
#define GRASS_GROW_H 0.4
#define GRASS_SEED_L 2.0
#define GRASS_SEED_H 4.0
#define GRASS_AGE_L 20.0
#define GRASS_AGE_H 40.0
#define GRASS_SPREAD_L 50.0
#define GRASS_SPREAD_H 150.0
#define GRASS_VAR 0.05
#define GRASS_NUM_GENES 4
#define GRASS_GENE_GROW 0
#define GRASS_GENE_SEED 1
#define GRASS_GENE_AGE 2
#define GRASS_GENE_SPREAD 3
#define GRASS_FLAG_DEAD 0
#define GRASS_FLAG_NEW 1
#define GRASS_NUM_FLAGS 2

// colors
#define BACKGROUND_COL 0x000000ff
#define LAND_COL 0x603909ff
#define BORDER_COL 0xf3bc7aff
#define GRASS_COL 0x7cfc00ff

#endif