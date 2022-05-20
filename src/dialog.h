#ifndef MY_DIALOG_HEADER
#define MY_DIALOG_HEADER

#include "definitions.h"
#include "initstates.h"

/* Adds dialog to queue */
void queue_dialog(Dialog_T *d);

/* Removes first dialog from queue */
void remove_dialog(bool or);

/* Creates a new dialog */
void basic_new_dialog(Dialog_T *dialog);
void new_dialog(char *text);
void new_trivia_dialog(char *question, char *answers, char correct); /* Answers must be separated by a \n */

/* Free all dialog */
void free_dialog();

/* Render dialog (Uesd to fix Issue #4) */
void render_dialog();
void render_trivia_dialog(int yoff);

#endif
