#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define PATH_TO_IMAGES "assets/images/"

#define WINDOW_WIDTH 1500
#define WINDOW_HEIGHT 1500

#define PLAYER_WHITE -1
#define PLAYER_BLACK 1

typedef struct {
    SDL_Window *window;
    SDL_Surface *screen;
} App;