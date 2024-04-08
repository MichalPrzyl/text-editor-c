#include <stdio.h>
#include <SDL2/SDL.h>

// #include <SDL/include/SDL.h>
// #include "SDL/include/SDL"

int main(int argc, char *argv[]){
    int WIDTH = 400;
    int HEIGHT = 400;
    // return 0;
    SDL_Init( SDL_INIT_EVERYTHING );
    puts("Starting program...");

    SDL_Window *window = SDL_CreateWindow( "Hello SDL WORLD", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, WIDTH, HEIGHT, SDL_WINDOW_ALLOW_HIGHDPI );
    SDL_Renderer* renderer;
    renderer = SDL_CreateRenderer(window, -1, 0);
    // draw color
    SDL_SetRenderDrawColor(renderer, 235, 168, 52, 255);

    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
    if (window == NULL){
        puts("cant create window");
        return 1;
    }

    SDL_Event windowEvent;
    while (1)
    {
        if(SDL_PollEvent(&windowEvent))
        {
            if (windowEvent.type == SDL_QUIT)
            {break;}
        }
    }

    
    SDL_DestroyWindow( window );
    SDL_Quit( );
}