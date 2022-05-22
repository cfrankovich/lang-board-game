#include "definitions.h"
#include "camera.h"

void move_camera(Camera_T *cam, float x, float y)
{
	cam->x = x;
	cam->y = y;
}

void update_camera_from_player(Player_T *p)
{
	/* LMFAOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOOO I HATE THIS */
	int i;
	i = 167 - (p->totalspacestogo);

	if (i < 40 && i >= 20 && p->updatecam == 0)
	{
		CAMERA.x -= 800;
		CAMERA.y -= 400;
		p->updatecam += 1;
	}
	else if (i < 60 && i >= 40 && p->updatecam == 1)
	{
		CAMERA.x -= 800;
		CAMERA.y -= 400;
		p->updatecam += 1;
	}
	else if (i < 80 && i >= 60 && p->updatecam == 2)
	{
		CAMERA.x -= 800;
		CAMERA.y -= 400;
		p->updatecam += 1;
	}
	else if (i < 100 && i >= 80 && p->updatecam == 3)
	{
		CAMERA.x -= 800;
		p->updatecam += 1;
		CAMERA.y -= 400;
	}
}
