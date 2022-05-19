#include <SDL2/SDL.h>
#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

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
					if (dialog_queue[0] == NULL) return 'G';
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

	/* players[0] */
	draw_tile(players[0]->bottomtile, players[0]->x, players[0]->y, players[0]->z);	
	draw_tile(players[0]->toptile, players[0]->x, players[0]->y, players[0]->z+1);	

	/* Dialog */
	if (dialog_queue[0] != NULL)
	{
		render_dialog();
	}

}

/* Game */
bool showresult;
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
					if (dialog_queue[0] != NULL) { break; }
					else if (showresult) { showresult = false; break; }
					else if ((players[turn-1]->spacestogo != 0) && (!rolling)) { break; }
					rolling = !rolling;
					if (!rolling)
					{
						time_t t;
						srand((unsigned) time(&t));
						players[turn-1]->spacestogo = rand() % 6 + 1; 
						showresult = true;
					}
					break;

				case SDLK_SPACE:
					remove_dialog();
					break;

			}
			break;
	}

	update_camera_from_player(players[0]);

	return 'G';
}

char buffer[255];
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

	/* oh god is this to many ifs LOL */

	/* Turn Stuff */
	if (changingturn)
	{
		sprintf(buffer, "It is now Player %ds turn. You are currently  located in [LOCATION]. %d moves to go to win.\0", turn, 0); 
		new_dialog(true, buffer);
		changingturn = false;
	}

	/* Player */
	if ((players[turn-1]->spacestogo != 0) && (!showresult))
	{
		players[turn-1]->timesincelastmove += ELAPSED;

		if (players[turn-1]->timesincelastmove > 0.5)
		{
			players[turn-1]->x -= 1;
			players[turn-1]->spacestogo -= 1;
			players[turn-1]->timesincelastmove = 0;
		}

	}

	

	draw_tile(players[turn-1]->bottomtile, players[turn-1]->x, players[turn-1]->y, players[turn-1]->z);	
	draw_tile(players[turn-1]->toptile, players[turn-1]->x, players[turn-1]->y, players[turn-1]->z+1);	

	/* Die */
	if (showresult)
	{
		dieface.src.x = ((players[turn-1]->spacestogo)-1) * 100;	
		SDL_RenderCopy(RENDERER, dieface.texture, &dieface.src, &dieface.dest);
	}

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
		render_dialog();
	}

}

