#ifndef MY_GAMESTATE_HEADER
#define MY_GAMESTATE_HEADER

#include <SDL2/SDL.h>
#include <stdbool.h>

#include "definitions.h"
#include "gamestate.h"
#include "initstates.h"
#include "drawing.h"
#include "camera.h"

/* Handles all updates */
char tick_game_state(SDL_Event e, bool *running);
char tick_startup_state(SDL_Event e, bool *running);

/* Handles all rendering */
void render_game_state();
void render_startup_state();

#endif
