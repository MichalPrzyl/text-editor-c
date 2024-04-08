#include <stdio.h>
#include <SDL2/SDL.h>
#include <SDL2/SDL_ttf.h>
#include <dirent.h> 
// #include <SDL/include/SDL.h>
// #include "SDL/include/SDL"

void read_directory_files(){
    DIR *d;
    struct dirent *dir;
    d = opendir(".");
    if (d) {
    while ((dir = readdir(d)) != NULL) {
        printf("%s\n", dir->d_name);
    }
    closedir(d);
    }
}

void get_text_and_rect(SDL_Renderer *renderer, int x, int y, char *text,
        TTF_Font *font, SDL_Texture **texture, SDL_Rect *rect) {
    int text_width;
    int text_height;
    SDL_Surface *surface;
    SDL_Color textColor = {255, 255, 255, 0};

    surface = TTF_RenderText_Solid(font, text, textColor);
    *texture = SDL_CreateTextureFromSurface(renderer, surface);
    text_width = surface->w;
    text_height = surface->h;
    SDL_FreeSurface(surface);
    rect->x = x;
    rect->y = y;
    rect->w = text_width;
    rect->h = text_height;
}


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

// print text in window

    //this opens a font style and sets a size
    TTF_Init();
    // TTF_Font* Sans = TTF_OpenFont("CascadiaMono.ttf", 24);
    TTF_Font *font = TTF_OpenFont("CascadiaMono.ttf", 24);

// this is the color in rgb format,
// maxing out all would give you the color white,
// and it will be your text's color
SDL_Color White = {255, 255, 255};

// as TTF_RenderText_Solid could only be used on
// SDL_Surface then you have to create the surface first

// now you can convert it into a texture


    SDL_RenderClear(renderer);
    SDL_RenderPresent(renderer);
    if (window == NULL){
        puts("cant create window");
        return 1;
    }
    read_directory_files();
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