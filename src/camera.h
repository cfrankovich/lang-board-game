#ifndef MY_CAMERA_HEADER
#define MY_CAMERA_HEADER

#include "definitions.h"

/* Moves camera to *x, y) */
void move_camera(Camera_T *cam, float x, float y);

/* Checks to see if given player toggles the trigger */
void update_camera_from_player(Player_T *p);

#endif
