#include <SDL2/SDL.h>
#include <stdbool.h>

#include "definitions.h"
#include "gamestate.h"
#include "initstates.h"
#include "drawing.h"

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
	/* Now need to traverse through the linked list rendering the tiles */ 
	struct MapNode *current;
	current = head_node;
	int iter, x, y, z;
	iter = 1;
	x = -(map_width/2); 
	y = (map_height/2); 
	z = 0;
	while (current != NULL)
	{
		draw_tile(current->tile, x, y, z);
		if (iter % map_width == 0) { --y; x = -(map_width/2); }
		else { ++x; }
		current = current->next;
		++iter;
	}

	SDL_Rect rect = {WIDTH/2, HEIGHT/2, 5, 5}; 
	SDL_SetRenderDrawColor(RENDERER, 0xFF, 0x00, 0xFF, 0xFF);
	SDL_RenderFillRect(RENDERER, &rect);
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

