#include <stdio.h>
#include <SDL2/SDL.h>
#include <stdbool.h>

#include "definitions.h"
#include "initstates.h"
#include "assets.h"
#include "camera.h"
#include "text.h"
#include "dialog.h"

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
	menuimage.hitbox.w = 800;
	menuimage.hitbox.h = 600;
}

struct MapNode *head_node;
unsigned int map_width;
unsigned int map_height;
Player_T *players[3]; /* max three players (charlie, patrick, or sam) */
Dialog_T *dialog_queue[16];
void init_startup_state()
{
	/* Map Stuff */
	FILE *mapfile;
	char buff[255];
	int iter;

	map_width = 0;
	map_height = 0;

	mapfile = fopen(MAP_PATH, "r");
	fgets(buff, 255, mapfile); 

	/* Read the first line and get width, height of map */
	map_width = ((buff[0] - 48) * 10) + (buff[1] - 48);	
	map_height = ((buff[3] - 48) * 10) + (buff[4] - 48);	

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
			tile->width = 1;
			tile->height = 1;
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

	/* Player Stuff */
	Player_T *player;
	player = malloc(sizeof(Player_T));
	TileAsset_T *bottile, *toptile;
	bottile = malloc(sizeof(TileAsset_T));
	toptile = malloc(sizeof(TileAsset_T));
	bottile->id = 3;
	toptile->id = 2;
	load_asset(bottile);
	load_asset(toptile);
	player->bottomtile = bottile;	
	player->toptile = toptile;	
	players[0] = player;

	player->x = 15;
	player->y = -16;
	player->z = 1;

	/* Camera Stuff */
	move_camera(&CAMERA, 0, 500);

	/* Dialog Box Stuff */
	new_dialog(true, "Welcome to \"The Perks of Being a Wallflower, The Board Game.\"\0");
	new_dialog(true, "To skip the tutorial at anytime, press [RETURN].\0");
	new_dialog(true, "This game is very simple to play. Pay attention to these instructions.\0");
	new_dialog(true, "The goal of the game is to reach the end of the board or story if you will, in the least amount of moves possible.\0");
	new_dialog(true, "If you are playing with multiple people, the first one to the end wins!\0");
	new_dialog(true, "When prompted, press [RETURN] to roll the dice. This will move you that number of spaces.\0");
	new_dialog(true, "When landing on a trivia square, you are required to answer the question given.\0");
	new_dialog(true, "These questions are related to the area of the map in which you are located in.\0");
	new_dialog(true, "If the question is answered correctly, you can roll again.\0");
	new_dialog(true, "If answered incorrectly, you roll the die how many spaces you go back.\0");
	new_dialog(true, "Good luck :)\0");

}

unsigned int turn;
unsigned int dierollcount; 
MyAnimation_T dieanim;
MyAnimation_T dieface;
bool rolling;
bool changingturn;
void init_game_state()
{
	/* Free Dialog */
	free_dialog();

	/* Turn Stuff */
	turn = 1;
	changingturn = true;

	/* Dice Stuff */
	dierollcount = 50;

	dieanim.texture = IMG_LoadTexture(RENDERER, DIE_ANIMATION_PATH);

	dieanim.src.x = 0;
	dieanim.src.y = 0;
	dieanim.src.w = 100;
	dieanim.src.h = 100;

	dieanim.dest.x = WIDTH/2 - 75;
	dieanim.dest.y = 150;
	dieanim.dest.w = 150;
	dieanim.dest.h = 150;

	dieanim.animtime = 0.1;

	dieface.texture = IMG_LoadTexture(RENDERER, DIE_FACES_PATH); 
	dieface.src.x = 0;
	dieface.src.y = 0;
	dieface.src.w = 100;
	dieface.src.h = 100;

	dieface.dest.x = WIDTH/2 - 75;
	dieface.dest.y = 150;
	dieface.dest.w = 130;
	dieface.dest.h = 130;

	dieface.animtime = 0.5;

	rolling = false;

}

