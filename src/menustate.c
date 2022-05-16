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
				case SDLK_q:
					printf("Exiting...\n");
					*running = false;
					break;

			}
			break;

		case SDL_MOUSEBUTTONDOWN:
			SDL_Rect playrect = {33, 375, 236, 81};
			SDL_Rect instrect = {294, 375, 221, 86};
			SDL_Rect exitrect = {552, 384, 202, 82};

			int mposx, mposy;
			SDL_GetMouseState(&mposx, &mposy);
			SDL_Rect mousrect = {mposx, mposy, 1, 1};

			if (SDL_HasIntersection(&mousrect, &playrect))
			{
				return 'S';
			}
			else if (SDL_HasIntersection(&mousrect, &instrect)) 
			{
				/* open browser to instructions */
			}
			else if (SDL_HasIntersection(&mousrect, &exitrect))
			{
				printf("Exiting...\n");
				*running = false;
			}
			break;

	}

	return 'M';
}

void render_menu_state()
{
	SDL_RenderCopy(RENDERER, menuimage.texture, NULL, &menuimage.hitbox);
}

