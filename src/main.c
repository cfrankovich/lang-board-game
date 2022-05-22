#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <getopt.h>

#include <SDL2/SDL.h>

#include "definitions.h"
#include "text.h"
#include "assets.h"
#include "drawing.h"

#include "menustate.h"
#include "gamestate.h"
#include "initstates.h"

SDL_Renderer *RENDERER;
Camera_T CAMERA;
float NOW;  
float ELAPSED;  
float LASTTIME;
int main(int argc, char **argv)
{
	/* Basic SDL Stuff */
	SDL_Event event;
	SDL_Window *window = NULL;
	RENDERER = NULL;
	SDL_Init(SDL_INIT_VIDEO);
	window = SDL_CreateWindow("Lang Board Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, 0);
	RENDERER = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);
	SDL_ShowCursor(SDL_DISABLE);
	CAMERA.x = 0.0f; 
	CAMERA.y = 0.0f; 

	/* Parse Args */ 
	bool FPS_FLAG = false;
	bool DEBUG_FLAG = false;

	static struct option long_options[] = {
		{"debug",  no_argument, 0, 'D'},
		{"show-fps",  no_argument, 0, 'F'}
	};

	int opt_indx;
	int opt_char;
	while ((opt_char = getopt_long(argc, argv, OPT_LIST, long_options, &opt_indx)) != -1)
	{
		switch(opt_char)
		{
			case 'D':
			case 'd':
				DEBUG_FLAG = !DEBUG_FLAG;
				FPS_FLAG = !FPS_FLAG;
				break;

			case 'F':
			case 'f':
				FPS_FLAG = !FPS_FLAG;
				break;

			case '?':
				break;
		}
	}

	/* Create Fonts */
	TTF_Init();
	TTF_Font *font12px = TTF_OpenFont(FONT_PATH, 12);

	/* Colors */
	SDL_Color white = { 255, 255, 255 };

	/* Frame Rate Stuff */
	NOW = 0;
	LASTTIME = 0;
	ELAPSED = 0;
	int frametime = 0;
	char framecount[16] = "FPS: 0\0";
	int updates, count;
	Text_t frametext; 
	init_text(&frametext, framecount, font12px, 0, 0, white);
	updates = count = 0;

	/* Cursor Img */
	MyImage_T cursorimg;
	cursorimg.texture = IMG_LoadTexture(RENDERER, CURSOR_IMG_PATH);
	cursorimg.hitbox.x = 0;
	cursorimg.hitbox.y = 0;
	cursorimg.hitbox.w = 30;
	cursorimg.hitbox.h = 30;

	/* Game Loop */
	bool running; 
	running = true;
	char state;
	state = 'S';
	init_state(state);

	while (running)
	{
		NOW = SDL_GetTicks();
		ELAPSED = (NOW - LASTTIME) / 1000;
		LASTTIME = NOW;

		/* Background */
		SDL_SetRenderDrawColor(RENDERER, 0x00, 0x00, 0x00, 0xFF);
		SDL_RenderClear(RENDERER);

		/* State Manager Thing */ 
		switch (state)
		{
			case 'M':
				/* menu state - basic menu upon launch */	
				state = tick_menu_state(event, &running);
				render_menu_state();
				if (state != 'M') init_state(state);
				break;

			case 'S':
				/* startup state - sets up the game */
				state = tick_startup_state(event, &running);
				render_startup_state();
				if (state != 'S') init_state(state);
				break;

			case 'G':
				/* game state - actual gameplay */ 
				state = tick_game_state(event, &running);
				render_game_state();
				if (state != 'G') init_state(state);
				break;
		}

		/* Cursor Stuff */
		int mposx, mposy;
		SDL_GetMouseState(&mposx, &mposy);
		cursorimg.hitbox.x = mposx;
		cursorimg.hitbox.y = mposy;
		SDL_RenderCopy(RENDERER, cursorimg.texture, NULL, &cursorimg.hitbox);

		/* FPS Counter */
		if (FPS_FLAG) 
		{
			updates++;
			if (NOW >= 1000*count)
			{
				sprintf(framecount, "FPS: %d", updates);
				count++;
				updates = 0;
				init_text(&frametext, framecount, font12px, 0, HEIGHT-10, white);
			}
			SDL_RenderCopy(RENDERER, frametext.texture, NULL, &frametext.rect);

		}

		SDL_RenderPresent(RENDERER);

		frametime = SDL_GetTicks() - NOW;
		if (1000 / FPS > frametime) SDL_Delay((1000 / FPS) - frametime);
	}

	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}

