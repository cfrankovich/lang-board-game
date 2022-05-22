CC = gcc
CFLAGS = -O1 -Wall -g $(shell pkg-config --cflags sdl2 SDL2_ttf SDL2_image)
LDFLAGS =
NAME = game 
SDL_LIBS := $(shell pkg-config --libs sdl2 SDL2_ttf SDL2_image)
override LIBS += $(SDL_LIBS)

# Is there a beter way to write this?????? #

all: create 
	@echo "Done!"

create: main.o text.o drawing.o assets.o initstates.o menustate.o gamestate.o camera.o dialog.o 
	$(CC) $(CFLAGS) -o $(NAME) $^ $(LIBS)

main.o: main.c 
	$(CC) $(CFLAGS) -o $@ -c $^ $(LIBS)

text.o: text.c 
	$(CC) $(CFLAGS) -o $@ -c $^ $(LIBS)

drawing.o: drawing.c 
	$(CC) $(CFLAGS) -o $@ -c $^ $(LIBS)

assets.o: assets.c
	$(CC) $(CFLAGS) -o $@ -c $^ $(LIBS)

initstates.o: initstates.c
	$(CC) $(CFLAGS) -o $@ -c $^ $(LIBS)

menustate.o: menustate.c
	$(CC) $(CFLAGS) -o $@ -c $^ $(LIBS)

gamestate.o: gamestate.c
	$(CC) $(CFLAGS) -o $@ -c $^ $(LIBS)

camera.o: camera.c 
	$(CC) $(CFLAGS) -o $@ -c $^ $(LIBS)

dialog.o: dialog.c 
	$(CC) $(CFLAGS) -o $@ -c $^ $(LIBS)

clean:
	rm -f $(NAME) *.o
	@echo "Cleaned!"

