#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdbool.h>

#include "menustate.h"
#include "assets.h"
#include "definitions.h"
#include "initstates.h"

char tick_menu_state(SDL_Event e, bool *running)
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
				case SDLK_ESCAPE:
					printf("Exiting...\n");
					*running = false;
					break;

				case SDLK_RETURN:
					return 'S';

			}
			break;

	}

	return 'M';
}

void render_menu_state()
{
	SDL_RenderCopy(RENDERER, menuimage.texture, NULL, &menuimage.hitbox);
}

