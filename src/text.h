#ifndef MY_TEXT_HEADER
#define MY_TEXT_HEADER

#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>

typedef struct
{
	char *string;
	SDL_Surface *surface;
	SDL_Texture *texture;
	SDL_Rect rect;
	SDL_Color color;
	TTF_Font *font;
} Text_t;

/* Returns the text type based on parameters given */
void init_text(Text_t *thetext, char *textstring, TTF_Font *font, int x, int y, SDL_Color color);

#endif
