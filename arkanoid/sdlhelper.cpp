#include "sdlhelper.h"

#include <stdexcept>

#include <SDL.h>

SDL_Window* gWindow = NULL;
SDL_Surface* gScreenSurface = NULL;
SDL_Renderer* gRenderer = NULL;

void init(int width, int height)
{
    if(SDL_Init( SDL_INIT_VIDEO ) < 0)
    {
        throw std::runtime_error(std::string("SDL could not initialize! SDL_Error: ") + SDL_GetError());
    }

    //Create window
    gWindow = SDL_CreateWindow("Arkanoid", SDL_WINDOWPOS_UNDEFINED, SDL_WINDOWPOS_UNDEFINED, width, height, SDL_WINDOW_SHOWN );
    if(gWindow == NULL)
    {
        throw std::runtime_error(std::string("Window could not be created! SDL_Error: ") + SDL_GetError());
    }

    //Get window surface
    gScreenSurface = SDL_GetWindowSurface(gWindow);
    gRenderer = SDL_CreateRenderer(gWindow, 0, 0);
}

void close()
{
    //Destroy window
    SDL_DestroyWindow(gWindow);
    gWindow = NULL;

    //Quit SDL subsystems
    SDL_Quit();
}
