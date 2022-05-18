#ifndef MY_DEFINITIONS_HEADER
#define MY_DEFINITIONS_HEADER

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#define FPS 60 
#define WIDTH 800
#define HEIGHT 600
#define SCALE 1.5
#define TOTAL_SPACES 160
#define OPT_LIST "dDfF"
#define FONT_PATH "/usr/share/fonts/liberation-fonts/LiberationMono-Regular.ttf"
#define MAP_PATH "../assets/map.txt"

typedef struct
{
	SDL_Texture *texture;
	SDL_Rect hitbox;
} MyImage_T;

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

extern Camera_T CAMERA;
extern SDL_Renderer *RENDERER;

#endif 
