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

struct MapNode *head_node;
unsigned int map_width;
unsigned int map_height;
void init_startup_state()
{
	FILE *mapfile;
	char buff[255];
	int iter;

	map_width = 0;
	map_height = 0;

	mapfile = fopen(MAP_PATH, "r");
	fgets(buff, 255, mapfile); 

	/* Read the first line and get width, height of map */
	iter = 0;
	for (int i = 1; buff[iter] != 32; ++iter, i+=9) { map_width += (buff[iter] - 48) * i; }
	++iter;
	for (int i = 1; buff[iter] != 10; ++iter, i+=9) { map_height += (buff[iter] - 48) * i; }

	head_node = malloc(sizeof(struct MapNode));
	head_node = NULL;

	/* Using that width and height read the rest of the map and generate a linked list for rendering */
	for (iter = 0; iter < map_height; ++iter)
	{
		fgets(buff, 255, mapfile);	
		for (int k = 0; k < (map_width*3-1); k+=3)
		{
			TileAsset_T *tile;	
			tile = malloc(sizeof(TileAsset_T));
			tile->id = (buff[k+1] - 48) + ((buff[k] - 48) * 10);	
			load_asset(tile);

			struct MapNode *newnode;
			newnode = malloc(sizeof(struct MapNode));
			newnode->tile = tile;
			newnode->next = head_node;
			head_node = newnode;
		}

	}
	fclose(mapfile);

	/* Now reverse the linked list (alternative: rotating map.txt files 180deg) */
	struct MapNode *prev;
	struct MapNode *next;
	struct MapNode *current;
	prev = NULL;
	current = head_node;
	while (current != NULL)
	{
		next = current->next;
		current->next = prev;
		prev = current;
		current = next;
	}
	head_node = prev;

}

void init_game_state()
{

}

