#include <stdio.h>
#include <SDL2/SDL.h>

#include "definitions.h"
#include "initstates.h"

void init_state(char newstate)
{
	switch (newstate)
	{
		case 'M':
			init_menu_state();
			break;

		case 'S':
			init_startup_state();
			break;

		case 'G':
			init_game_state();
			break;
	}
}

MyImage_T menuimage;
void init_menu_state()
{
	menuimage.texture = IMG_LoadTexture(RENDERER, MENU_SCREEN_PATH);
	menuimage.hitbox.x = 0;
	menuimage.hitbox.y = 0;
	menuimage.hitbox.w = WIDTH;
	menuimage.hitbox.h = HEIGHT;
}

void init_startup_state()
{
	printf("initstartup!\n");

	FILE *mapfile;
	char buff[255];
	mapfile = fopen(MAP_PATH, "r");

	fgets(buff, 255, mapfile); 

	fclose(mapfile);

}

void init_game_state()
{

}

