#include <SDL2/SDL.h>
#include <stdbool.h>

#include "definitions.h"
#include "gamestate.h"
#include "initstates.h"
#include "drawing.h"
#include "camera.h"

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

				case SDLK_h:
					CAMERA.x -= 10;
					break;

				case SDLK_l:
					CAMERA.x += 10;
					break;

				case SDLK_j:
					CAMERA.y += 10;
					break;

				case SDLK_k:
					CAMERA.y -= 10;
					break;
			}
			break;
	}

	//printf("CAMERA POS (%f, %f)\n", CAMERA.x, CAMERA.y);

	update_camera_from_player(&player);

	return 'S';
}

void render_startup_state()
{
	/* Map */
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

	/* Player */
	draw_tile(player.bottomtile, player.x, player.y, player.z);	
	draw_tile(player.toptile, player.x, player.y, player.z+1);	

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


