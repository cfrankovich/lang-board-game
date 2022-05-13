#ifndef MY_DRAWING_HEADER
#define MY_DRAWING_HEADER

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "assets.h"

/* Draws specific tile at coordinate (x, y, z) */
void draw_tile(TileAsset_T *tile, int x, int y, int z, SDL_Renderer *r);

/* Draws map from the path specified */
/* Map file in plain text */
void draw_map(SDL_Renderer *r, char *mappath);

#endif
