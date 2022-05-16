#include <SDL2/SDL.h>
#include <stdbool.h>

#include "definitions.h"
#include "gamestate.h"

/* Startup */
char tick_startup_state(SDL_Event e, bool *running)
{
	SDL_PollEvent(&e);
	switch (e.type)
	{
		case SDL_QUIT:
			printf("Exiting...\n");
			*running = false;
			break;

		case SDL_KEYDOWN:
			switch (e.key.keysym.sym)
			{
				case SDLK_q:
					printf("Exiting...\n");
					*running = false;
					break;

			}
			break;
	}

	return 'S';
}

void render_startup_state()
{
	
}

/* Game */
char tick_game_state(SDL_Event e, bool *running)
{
	SDL_PollEvent(&e);
	switch (e.type)
	{
		case SDL_QUIT:
			printf("Exiting...\n");
			*running = false;
			break;

		case SDL_KEYDOWN:
			switch (e.key.keysym.sym)
			{
				case SDLK_q:
					printf("Exiting...\n");
					*running = false;
					break;

			}
			break;
	}

	return 'G';
}

void render_game_state()
{
	
}

