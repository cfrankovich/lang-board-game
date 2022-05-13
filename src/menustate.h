#ifndef MY_MENUSTATE_HEADER
#define MY_MENUSTATE_HEADER

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdbool.h>

#include "menustate.h"
#include "assets.h"
#include "definitions.h"

/* Handle All Updates */
char tick_menu_state(SDL_Event e, bool *running);

/* Handle All Rendering */
void render_menu_state(SDL_Renderer *r);

#endif
