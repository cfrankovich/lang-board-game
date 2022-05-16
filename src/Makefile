CC = gcc
CFLAGS = -O2 -Wall
LDFLAGS =
NAME = game 
SDL_CFLAGS := $(shell pkg-config --cflags sdl2 SDL2_ttf SDL2_image)
SDL_LIBS := $(shell pkg-config --libs sdl2 SDL2_ttf SDL2_image)
override CFLAGS += $(SDL_CFLAGS)
override LIBS += $(SDL_LIBS)

all: create 
	@echo "Done!"

create: main.o text.o drawing.o assets.o initstates.o menustate.o gamestate.o 
	$(CC) $(LDFLAGS) -o $(NAME) $^ $(LIBS)

main.o: main.c 
	$(CC) $(LDFLAGS) -o $@ -c $^ $(LIBS)

text.o: text.c 
	$(CC) $(LDFLAGS) -o $@ -c $^ $(LIBS)

drawing.o: drawing.c 
	$(CC) $(LDFLAGS) -o $@ -c $^ $(LIBS)

assets.o: assets.c
	$(CC) $(LDFLAGS) -o $@ -c $^ $(LIBS)

initstates.o: initstates.c
	$(CC) $(LDFLAGS) -o $@ -c $^ $(LIBS)

menustate.o: menustate.c
	$(CC) $(LDFLAGS) -o $@ -c $^ $(LIBS)

gamestate.o: gamestate.c
	$(CC) $(LDFLAGS) -o $@ -c $^ $(LIBS)

clean:
	rm -f $(NAME) *.o
	@echo "Cleaned!"

