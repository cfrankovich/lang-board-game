#ifndef MY_INITSTATES_HEADER
#define MY_INITSTATES_HEADER

#include <stdio.h>
#include <SDL2/SDL.h>

#include "definitions.h"
#include "assets.h"
#include "camera.h"
#include "text.h"
#include "dialog.h"

/* Properly calls which state needs to be initialized */
void init_state(char newstate); 

/* Meu State */
extern MyImage_T menuimage; 
void init_menu_state();

/* Startup State */
extern struct MapNode *head_node;
extern unsigned int map_height;
extern unsigned int map_width;
extern Player_T *players[3];
extern Dialog_T *dialog_queue[16];
void init_startup_state();

/* Game State */
extern unsigned int turn;
extern unsigned int dierollcount; 
extern MyAnimation_T dieanim;
extern MyAnimation_T dieface;
extern bool rolling;
extern bool changingturn;
void init_game_state();

#endif
