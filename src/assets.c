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

		case 6:
			tile->texture = IMG_LoadTexture(RENDERER, SCHOOL_FLOOR_ONE);
			break;

		case 7:
			tile->texture = IMG_LoadTexture(RENDERER, SCHOOL_FLOOR_TWO);
			break;

		case 8:
			tile->texture = IMG_LoadTexture(RENDERER, DARK_GRASS_TILE_PATH);
			break;

		case 9:
			tile->texture = IMG_LoadTexture(RENDERER, TRIVIA_SPACE_TILE);
			break;

		case 10:
			tile->texture = IMG_LoadTexture(RENDERER, RED_PATH_TILE);
			break;

		case 11:
			tile->texture = IMG_LoadTexture(RENDERER, ORANGE_PATH_TILE);
			break;

		case 12:
			tile->texture = IMG_LoadTexture(RENDERER, YELLOW_PATH_TILE);
			break;

		case 13:
			tile->texture = IMG_LoadTexture(RENDERER, GREEN_PATH_TILE);
			break;

		case 14:
			tile->texture = IMG_LoadTexture(RENDERER, BLUE_PATH_TILE);
			break;

		case 15:
			tile->texture = IMG_LoadTexture(RENDERER, PURPLE_PATH_TILE);
			break;

		case 16:
			tile->texture = IMG_LoadTexture(RENDERER, PINK_PATH_TILE);
			break;

		case 99:
			tile->texture = IMG_LoadTexture(RENDERER, TEMPLATE_TILE_PATH);
			return 0;
			
	}

	return 1;
}

