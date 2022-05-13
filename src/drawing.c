#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "drawing.h"
#include "assets.h"
#include "definitions.h" 

void draw_tile(TileAsset_T *tile, int x, int y, int z, SDL_Renderer *r)
{
	unsigned short scale; 
	scale = 2;

	SDL_Rect rect;
	rect.w = 40 * scale;
	rect.h = 48 * scale;
	rect.x = (x * 21 * scale) + (y * 21 * scale);
	rect.y = (x * 12 * scale) + (y * -12 * scale) + (z * -20 * scale);

	SDL_RenderCopy(r, tile->texture, NULL, &rect);
}

void draw_map(SDL_Renderer *r, char *mappath)
{
	TileAsset_T *asset_array[TOTAL_ASSETS];

	int i;
	for (i = 0; i < TOTAL_ASSETS; ++i)
	{
		TileAsset_T *sampletile; 
		sampletile = malloc(sizeof(TileAsset_T));
		sampletile->id = i;
		load_asset(sampletile, r);
		asset_array[i] = sampletile;
	}

	/*
	FILE *mapfile;
	mapfile = fopen(mappath, "r");

	char buff[255];
	fgets(buff, 255, mapfile);

	printf("%s\n", buff);

	fclose(mapfile);
	*/

}

