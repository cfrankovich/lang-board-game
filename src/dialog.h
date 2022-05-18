#ifndef MY_DIALOG_HEADER
#define MY_DIALOG_HEADER

#include "definitions.h"
#include "initstates.h"

/* Adds dialog to queue */
void queue_dialog(Dialog_T *d);

/* Removes first dialog from queue */
void remove_dialog();

/* Creates a new dialog */
void new_dialog(bool q, char *text);

/* Free all dialog */
void free_dialog();

/* Render dialog (Uesd to fix Issue #4) */
void render_dialog();

#endif
