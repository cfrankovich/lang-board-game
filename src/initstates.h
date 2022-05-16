#ifndef MY_INITSTATES_HEADER
#define MY_INITSTATES_HEADER

#include <stdio.h>
#include <SDL2/SDL.h>
#include "definitions.h"
#include "assets.h"

/* Properly calls which state needs to be initialized */
void init_state(char newstate, SDL_Renderer *r); 

/* Meu State */
extern MyImage_T menuimage; 
void init_menu_state(SDL_Renderer *r);

/* Startup State */
void init_startup_state();

/* Game State */
void init_game_state();

#endif
