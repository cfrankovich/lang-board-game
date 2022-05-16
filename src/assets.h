#ifndef MY_ASSETS_HEADER
#define MY_ASSETS_HEADER

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#define MENU_SCREEN_PATH "../assets/menuscreen.png"
#define GRASS_TILE_PATH "../assets/tiles/grass.png"
#define STONE_TILE_PATH "../assets/tiles/stone.png"
#define TOTAL_ASSETS 1 

typedef struct 
{
	unsigned short id;
	SDL_Texture *texture;
} TileAsset_T; 

int load_asset(TileAsset_T *tile);

#endif 
