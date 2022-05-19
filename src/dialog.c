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

void free_dialog()
{
	for (int i = 0; i < 16; ++i)
	{
		free(dialog_queue[i]);
		dialog_queue[i] = NULL;
	}
	dialog_queue[0] = NULL;
}

void new_dialog(bool q, char *text)
{
	Dialog_T *dialog;
	dialog = malloc(sizeof(Dialog_T));
	dialog->quitable = q;

	dialog->img.texture = IMG_LoadTexture(RENDERER, DIALOG_BOX_PATH); 
	dialog->img.hitbox.x = (WIDTH - 600) / 2;
	dialog->img.hitbox.y = HEIGHT - 220;
	dialog->img.hitbox.w = 600 ;
	dialog->img.hitbox.h = 200;

	dialog->font = TTF_OpenFont(FONT_PATH, 20);

	dialog->text = text;

	queue_dialog(dialog);
}

void render_dialog()
{
	SDL_RenderCopy(RENDERER, dialog_queue[0]->img.texture, NULL, &dialog_queue[0]->img.hitbox);
	int iter, itertwo, limit, yoff;
	limit = 44;
	char *string = dialog_queue[0]->text;	
	char buffer[limit+1]; /* +1 for null char */
	iter = 0;
	itertwo = 0;
	yoff = 0;
	while (string[itertwo] != '\0')
	{
		buffer[iter] = string[itertwo];
		if (iter >= limit || string[itertwo+1] == '\0')
		{
			buffer[iter+1] = '\0';
			SDL_Color color = {255, 250, 126};
			Text_t text;
			init_text(&text, buffer, dialog_queue[0]->font, dialog_queue[0]->img.hitbox.x + 30, dialog_queue[0]->img.hitbox.y + 20 + yoff, color);
			SDL_RenderCopy(RENDERER, text.texture, NULL, &text.rect);
			iter = -1;
			yoff += 30;
		}
		++iter;
		++itertwo;
	}

}

