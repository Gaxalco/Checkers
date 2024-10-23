#include "constants.h"


/* gcc main.c -g -o main -Wall -std=c99 -lSDL2 ; ./main */


//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia() {
    // Placeholder function, returns true for now
    return true;
}

//Frees media and shuts down SDL
void close2();

App game = {NULL, NULL};

bool init() {
    //Initialization flag
    bool success = true;

    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 ) {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        success = false;
    } else {
        //Create window
        game.window = SDL_CreateWindow("Checkers", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
        if (game.window == NULL) {
            printf("Window could not be created! SDL_Error: %s\n", SDL_GetError());
            success = false;
        } else {
            //Get window surface
            game.screen = SDL_GetWindowSurface(game.window);
        }
    }

    return success;
}



void close2() {
    //Deallocate surface
    if (game.screen != NULL) {
        SDL_FreeSurface(game.screen);
        game.screen = NULL;
    }

    //Destroy window
    if (game.window != NULL) {
        SDL_DestroyWindow(game.window);
        game.window = NULL;
    }

    //Quit SDL subsystems
    SDL_Quit();
}



int main(int argc, char* argv[]) {
    
    if (!init()) {
        printf("SDL_Init Error: %s\n", SDL_GetError());
        return 1;
    } else {
        //Fill the screen white
        SDL_FillRect(game.screen, NULL, SDL_MapRGB(game.screen->format, 0xFF, 0xFF, 0xFF));

        // Update the window
        SDL_UpdateWindowSurface(game.window);

        //Hack to get window to stay up
        SDL_Event e; bool quit = false; while( quit == false ){ while( SDL_PollEvent( &e ) ){ if( e.type == SDL_QUIT ) quit = true; } }
    }

    close();

    return 0;
}