#include "constants.h"


/* gcc main.c -o main -Wall -std=c99 -lSDL2 ; ./main */

//Starts up SDL and creates window
bool init();

//Loads media
bool loadMedia();

//Frees media and shuts down SDL
void close();

App game;

SDL_Surface *imgWhitePiece = NULL;
SDL_Surface *imgBlackPiece = NULL;

bool init() {
    //Initialization flag
    bool success = true;

    //Initialize SDL
    if( SDL_Init( SDL_INIT_VIDEO ) < 0 )
    {
        printf( "SDL could not initialize! SDL_Error: %s\n", SDL_GetError() );
        success = false;
    }
    else
    {
        //Create window
        game.window = SDL_CreateWindow( "SDL Tutorial", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN );
        if( game.window == NULL )
        {
            printf( "Window could not be created! SDL_Error: %s\n", SDL_GetError() );
            success = false;
        }
        else
        {
            //Get window surface
            game.screen = SDL_GetWindowSurface( game.window );
        }
    }

    return success;
}


bool loadMedia(SDL_Surface *img, char path[]) {
    //Loading success flag
    bool success = true;

    //Load splash image
    img = SDL_LoadBMP( path );
    if( img == NULL )
    {
        printf( "Unable to load image %s! SDL Error: %s\n", path, SDL_GetError() );
        success = false;
    }

    return success;
}


void close() {
    //Deallocate surface
    SDL_FreeSurface( imgWhitePiece );
    imgWhitePiece = NULL;

    SDL_FreeSurface( imgBlackPiece );
    imgBlackPiece = NULL;

    //Destroy window
    SDL_DestroyWindow( game.window );
    game.window = NULL;

    //Message to console
    printf("Game closed\n");

    //Quit SDL subsystems
    SDL_Quit();
}


int main(int argc, char* argv[]) {

    if (init() == false) {
        printf("Failed to initialize!\n");
    } else {
        //Load media
        if( !loadMedia(imgWhitePiece, "whitePiece.bmp") )
        {
            printf( "Failed to load media!\n" );
        } else {
            printf("Media loaded\n");

            // Update the window
            SDL_UpdateWindowSurface(game.window);

            //Hack to get window to stay up
            SDL_Event e; bool quit = false; while( quit == false ){ while( SDL_PollEvent( &e ) ){ if( e.type == SDL_QUIT ) quit = true; } }

            close();
        }
    }



    return 0;
}