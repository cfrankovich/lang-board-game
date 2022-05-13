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

int main(int argc, char **argv)
{
	/* Basic SDL Stuff */
	SDL_Event event;
	SDL_Window *window = NULL;
	SDL_Renderer *renderer = NULL;
	SDL_Init(SDL_INIT_VIDEO);
	window = SDL_CreateWindow("Lang Board Game", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, 0);
	renderer = SDL_CreateRenderer(window, -1, SDL_RENDERER_ACCELERATED);

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
	TTF_Font *font20px = TTF_OpenFont(FONT_PATH, 20);

	/* Colors */
	SDL_Color white = { 255, 255, 255 };
	SDL_Color red = { 226, 44, 44 };
	SDL_Color blue = { 44, 44, 226 };

	/* Frame Rate Stuff */
	int32_t elapsed = 0;
	int frametime = 0;
	char framecount[16] = "Frames: 0\0";
	int updates, count;
	Text_t frametext; 
	init_text(&frametext, framecount, font12px, 0, 0, white, renderer);
	updates = count = 0;

	/* Game Loop */
	bool running; 
	running = true;
	char state;
	state = 'M';

	while (running)
	{
		elapsed = SDL_GetTicks();

		/* Background */
		SDL_SetRenderDrawColor(renderer, 0x00, 0x00, 0x00, 0xFF);
		SDL_RenderClear(renderer);

		/* State Manager Thing */ 
		switch (state)
		{
			case 'M':
				/* menu state */	
				state = tick_menu_state(event, &running);
				render_menu_state(renderer);
				break;

			case 'G':
				/* game state */ 
				break;
		}

		/* FPS Counter */
		if (FPS_FLAG) 
		{
			updates++;
			if (elapsed >= 1000*count)
			{
				sprintf(framecount, "Frames: %d\0", updates);
				count++;
				updates = 0;
				init_text(&frametext, framecount, font12px, 0, HEIGHT-10, white, renderer);
			}
			SDL_RenderCopy(renderer, frametext.texture, NULL, &frametext.rect);

		}

		SDL_RenderPresent(renderer);

		frametime = SDL_GetTicks() - elapsed;
		if (1000 / FPS > frametime) SDL_Delay((1000 / FPS) - frametime);
	}

	SDL_DestroyWindow(window);
	SDL_Quit();

	return 0;
}

