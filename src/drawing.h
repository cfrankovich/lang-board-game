#ifndef MY_DRAWING_HEADER
#define MY_DRAWING_HEADER

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "definitions.h"
#include "assets.h"

/* (0, 0, 0) IS THE CENTER OF THE SCREEN */

/* Draws specific tile at coordinate (x, y, z) */
void draw_tile(TileAsset_T *tile, int x, int y, int z);

#endif
