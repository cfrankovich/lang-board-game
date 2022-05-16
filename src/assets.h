#ifndef MY_ASSETS_HEADER
#define MY_ASSETS_HEADER

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "definitions.h"

#define MENU_SCREEN_PATH "../assets/menuscreen.png"
#define GRASS_TILE_PATH "../assets/tiles/grass.png"
#define STONE_TILE_PATH "../assets/tiles/stone.png"
#define TOTAL_ASSETS 1 

int load_asset(TileAsset_T *tile);

#endif 
