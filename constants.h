#include <SDL2/SDL.h>
#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>

#define WINDOW_WIDTH 1500
#define WINDOW_HEIGHT 1500

typedef struct {
    SDL_Window *window;
    SDL_Surface *screen;
} App;