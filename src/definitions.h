#ifndef MY_DEFINITIONS_HEADER
#define MY_DEFINITIONS_HEADER

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#define FPS 30 
#define WIDTH 800
#define HEIGHT 600
#define OPT_LIST "dDfF"
#define FONT_PATH "/usr/share/fonts/liberation-fonts/LiberationMono-Regular.ttf"
#define MAP_PATH "../assets/map.txt"

typedef struct
{
	SDL_Texture *texture;
	SDL_Rect hitbox;
} MyImage_T;

extern SDL_Renderer *RENDERER;

#endif 
