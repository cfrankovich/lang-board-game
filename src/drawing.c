#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "drawing.h"
#include "assets.h"
#include "definitions.h" 

void draw_tile(TileAsset_T *tile, int x, int y, int z)
{
	SDL_Rect rect;
	rect.w = 40 * SCALE;
	rect.h = 48 * SCALE;
	rect.x = (x * 21 * SCALE) + (y * 21 * SCALE) + WIDTH/2 - 35; 
	rect.y = (x * 12 * SCALE) + (y * -12 * SCALE) + (z * -24 * SCALE) + HEIGHT/2 - 24;

	rect.x -= CAMERA.x;
	rect.y -= CAMERA.y;

	if (rect.x + rect.w < 0) { return; }
	else if (rect.y + rect.h < 0) { return; } 
	else if (rect.x > WIDTH) { return; }
	else if (rect.y > HEIGHT) { return; }

	SDL_RenderCopy(RENDERER, tile->texture, NULL, &rect);
}

