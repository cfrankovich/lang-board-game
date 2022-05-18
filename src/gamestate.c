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

				case SDLK_RETURN:
					return 'G';
					break;

				case SDLK_SPACE:
					remove_dialog();
					break;
			}
			break;
	}


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

	/* Dialog */
	if (dialog_queue[0] != NULL)
	{
		SDL_RenderCopy(RENDERER, dialog_queue[0]->img.texture, NULL, &dialog_queue[0]->img.hitbox);
		SDL_RenderCopy(RENDERER, dialog_queue[0]->text.texture, NULL, &dialog_queue[0]->text.rect);
	}

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

				case SDLK_RETURN:
					rolling = !rolling;
					if (!rolling)
					{
						/* random number here */
					}
					break;

			}
			break;
	}

	update_camera_from_player(&player);

	return 'G';
}

void render_game_state()
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

	/* Die */
	if (rolling)
	{
		dieanim.timesincelast += ELAPSED;

		if (dieanim.timesincelast > dieanim.animtime)
		{
			if (dieanim.idx < 4) dieanim.idx++;
			else dieanim.idx = 0;

			dieanim.timesincelast = 0;
		}

		dieanim.src.x = dieanim.idx * 100;
		SDL_RenderCopy(RENDERER, dieanim.texture, &dieanim.src, &dieanim.dest);

	}

	/* Dialog */
	if (dialog_queue[0] != NULL)
	{
		SDL_RenderCopy(RENDERER, dialog_queue[0]->img.texture, NULL, &dialog_queue[0]->img.hitbox);
		SDL_RenderCopy(RENDERER, dialog_queue[0]->text.texture, NULL, &dialog_queue[0]->text.rect);
	}

}

