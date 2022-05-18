#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "assets.h"
#include "definitions.h"

int load_asset(TileAsset_T *tile)
{
	switch (tile->id)
	{
		case 0:
			tile->texture = IMG_LoadTexture(RENDERER, GRASS_TILE_PATH);
			return 0;

		case 1:
			tile->texture = IMG_LoadTexture(RENDERER, STONE_TILE_PATH);
			return 0;

		case 2:
			tile->texture = IMG_LoadTexture(RENDERER, PLAYER_TOP_TILE_PATH);
			return 0;

		case 3:
			tile->texture = IMG_LoadTexture(RENDERER, PLAYER_BOTTOM_TILE_PATH);
			return 0;

		case 4:
			tile->texture = IMG_LoadTexture(RENDERER, DARK_STONE_TILE_PATH);
			return 0;

		case 5:
			tile->texture = IMG_LoadTexture(RENDERER, VOID_TILE_PATH);
			return 0;

		case 99:
			tile->texture = IMG_LoadTexture(RENDERER, TEMPLATE_TILE_PATH);
			return 0;
			
	}

	return 1;
}

