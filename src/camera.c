#include "definitions.h"
#include "camera.h"

void move_camera(Camera_T *cam, float x, float y)
{
	cam->x = x;
	cam->y = y;
}

void update_camera_from_player(Player_T *p)
{

}
