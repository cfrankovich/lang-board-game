#ifndef MY_DEFINITIONS_HEADER
#define MY_DEFINITIONS_HEADER

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>
#include <stdbool.h>

#include "text.h"

#define FPS 60 
#define WIDTH 1280 
#define HEIGHT 720 
#define SCALE 2
#define TOTAL_SPACES 160
#define OPT_LIST "dDfF"
#define FONT_PATH "/usr/share/fonts/liberation-fonts/LiberationMono-Regular.ttf"
#define MAP_PATH "../assets/map.txt"

typedef struct
{
	SDL_Texture *texture;
	SDL_Rect hitbox;
} MyImage_T;

typedef struct 
{
	SDL_Texture *texture;
	SDL_Rect src;
	SDL_Rect dest;
	float animtime;
	unsigned short idx;
	float timesincelast; 
} MyAnimation_T;

/* width and height are not exact pixels   */
/* for example, player is two hight (96px) */
typedef struct 
{
	unsigned short id;
	SDL_Texture *texture;
	unsigned short height;
	unsigned short width;
} TileAsset_T; 

struct MapNode
{
	TileAsset_T *tile;
	struct MapNode *next;
};

typedef struct
{
	TileAsset_T *bottomtile;
	TileAsset_T *toptile;
	float x, y, z;
	unsigned int spacestogo;
} Player_T; 

typedef struct
{
	float x;
	float y;
} Camera_T;

typedef struct
{
	bool quitable;
	MyImage_T img;
	TTF_Font *font;
	Text_t text;
} Dialog_T;

extern Camera_T CAMERA;
extern SDL_Renderer *RENDERER;
extern float NOW;  
extern float ELAPSED;  
extern float LASTTIME;

#endif 
