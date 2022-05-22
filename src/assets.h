#ifndef MY_ASSETS_HEADER
#define MY_ASSETS_HEADER

#include <SDL2/SDL.h>
#include <SDL2/SDL_image.h>

#include "definitions.h"

#define MENU_SCREEN_PATH "../assets/menuscreen.png"
#define DIALOG_BOX_PATH "../assets/dialogboxwithprompt.png"
#define LARGE_DIALOG_BOX_PATH "../assets/bigassdialogbox.png"
#define CURSOR_IMG_PATH "../assets/cursor.png"
#define DIE_ANIMATION_PATH "../assets/dicerollanimation.png"
#define DIE_FACES_PATH "../assets/diestages.png"

#define GRASS_TILE_PATH "../assets/tiles/grass.png"
#define DARK_GRASS_TILE_PATH "../assets/tiles/darkgrass.png"
#define STONE_TILE_PATH "../assets/tiles/stone.png"
#define DARK_STONE_TILE_PATH "../assets/tiles/darkstone.png"
#define PLAYER_TOP_TILE_PATH "../assets/tiles/playertop.png"
#define PLAYER_BOTTOM_TILE_PATH "../assets/tiles/playerbottom.png"
#define VOID_TILE_PATH "../assets/tiles/void.png"
#define TEMPLATE_TILE_PATH "../assets/tiles/template.png"
#define TRIVIA_SPACE_TILE "../assets/tiles/triviaspace.png"

#define RED_PATH_TILE "../assets/tiles/redpath.png"
#define ORANGE_PATH_TILE "../assets/tiles/orangepath.png"
#define YELLOW_PATH_TILE "../assets/tiles/yellowpath.png"
#define GREEN_PATH_TILE "../assets/tiles/greenpath.png"
#define BLUE_PATH_TILE "../assets/tiles/bluepath.png"
#define PURPLE_PATH_TILE "../assets/tiles/purplepath.png"
#define PINK_PATH_TILE "../assets/tiles/pinkpath.png"

#define SCHOOL_FLOOR_ONE "../assets/tiles/schoolfloorone.png"
#define SCHOOL_FLOOR_TWO "../assets/tiles/schoolfloortwo.png"

int load_asset(TileAsset_T *tile);

#endif 
