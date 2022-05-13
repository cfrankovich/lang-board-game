#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "assets.h"

int load_asset(TileAsset_T *tile, SDL_Renderer *r)
{
	switch (tile->id)
	{
		case 0:
			tile->texture = IMG_LoadTexture(r, GRASS_TILE_PATH);
			return 0;

		case 1:
			tile->texture = IMG_LoadTexture(r, STONE_TILE_PATH);
			return 0;
	}

	return 1;
}

