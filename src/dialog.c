#include "dialog.h"
#include "definitions.h"
#include "initstates.h"

void queue_dialog(Dialog_T *d)
{
	int iter;
	iter = 0;
	while (dialog_queue[iter]!= NULL) { ++iter; }

	if (iter >= 16) return;
	dialog_queue[iter] = d;
}

void remove_dialog()
{
	if ((dialog_queue[0] == NULL) || (!dialog_queue[0]->quitable)) return;

	free(dialog_queue[0]->font);
	free(dialog_queue[0]);

	for (int i = 0; i < 16; ++i)
	{
		dialog_queue[i] = dialog_queue[i+1];
	}
	dialog_queue[15] = NULL;
}

void new_dialog(bool q, char *text)
{
	Dialog_T *dialog;
	dialog = malloc(sizeof(Dialog_T));
	dialog->quitable = q;

	dialog->img.texture = IMG_LoadTexture(RENDERER, DIALOG_BOX_PATH); 
	dialog->img.hitbox.x = (WIDTH - 600) / 2;
	dialog->img.hitbox.y = HEIGHT - 320;
	dialog->img.hitbox.w = 600 ;
	dialog->img.hitbox.h = 300;

	dialog->font = TTF_OpenFont(FONT_PATH, 20);

	SDL_Color color = {255, 250, 126};
	init_text(&dialog->text, text, dialog->font, dialog->img.hitbox.x + 20, dialog->img.hitbox.y + 20, color);

	queue_dialog(dialog);
}

