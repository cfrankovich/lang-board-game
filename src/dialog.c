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

void remove_dialog(bool or)
{
	if ((dialog_queue[0] == NULL) || ((!dialog_queue[0]->quitable) && (!or))) return;

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

void basic_new_dialog(Dialog_T *dialog)
{
	dialog->img.hitbox.x = (WIDTH - 600) / 2;
	dialog->img.hitbox.w = 600 ;
	dialog->font = TTF_OpenFont(FONT_PATH, 20);
}

void new_dialog(char *text)
{
	Dialog_T *dialog;
	dialog = malloc(sizeof(Dialog_T));
	dialog->quitable = true;
	basic_new_dialog(dialog);

	dialog->img.texture = IMG_LoadTexture(RENDERER, DIALOG_BOX_PATH); 
	dialog->img.hitbox.y = HEIGHT - 220;
	dialog->img.hitbox.h = 200;

	dialog->text = text;
	dialog->answers = NULL;
	dialog->correct = 'X';

	queue_dialog(dialog);
}

void new_trivia_dialog(char *question, char *answers, char correct)
{
	Dialog_T *dialog;
	dialog = malloc(sizeof(Dialog_T));
	dialog->quitable = false;
	basic_new_dialog(dialog);

	dialog->img.texture = IMG_LoadTexture(RENDERER, LARGE_DIALOG_BOX_PATH); 
	dialog->img.hitbox.y = (HEIGHT - 600) / 2;
	dialog->img.hitbox.h = 600;

	dialog->text = question;
	dialog->answers = answers;
	dialog->correct = correct;

	queue_dialog(dialog);
}

void render_dialog()
{
	SDL_RenderCopy(RENDERER, dialog_queue[0]->img.texture, NULL, &dialog_queue[0]->img.hitbox);
	int iter, itertwo, limit, yoff;
	limit = 44;
	char buffer[limit+1]; /* +1 for null char */
	iter = 0;
	itertwo = 0;
	yoff = 0;
	while (dialog_queue[0]->text[itertwo] != '\0')
	{
		buffer[iter] = dialog_queue[0]->text[itertwo];
		if (iter >= limit || dialog_queue[0]->text[itertwo+1] == '\0')
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

	if (!dialog_queue[0]->quitable)
	{
		render_trivia_dialog(yoff);
		return;
	}

}

/* Written poorly works only for specific lengths lol */
void render_trivia_dialog(int yoff)
{
	int iter, itertwo, limit;
	iter = 4;
	itertwo = 0;
	yoff += 20;
	limit = 40; /* 40 cuz first four taken up by answer ex. "(a) " */
	char buffer[limit+1];

	buffer[0] = '(';	
	buffer[1] = 'a';
	buffer[2] = ')';	
	buffer[3] = ' ';	
	for (int i = 0; i < 4; ++i) 
	{
		while (dialog_queue[0]->answers[itertwo] != '\n')
		{
			buffer[iter] = dialog_queue[0]->answers[itertwo];
			++iter;
			++itertwo;
		}
		buffer[iter] = '\0';
		SDL_Color color = {255, 250, 126};
		Text_t text;
		init_text(&text, buffer, dialog_queue[0]->font, dialog_queue[0]->img.hitbox.x + 30, dialog_queue[0]->img.hitbox.y + 20 + yoff, color);
		SDL_RenderCopy(RENDERER, text.texture, NULL, &text.rect);
		iter = 4;
		yoff += 30;
		buffer[1]++;
		itertwo++;
	}
}

