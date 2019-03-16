#ifndef SDLHELPER_H
#define SDLHELPER_H

#include <SDL.h>

extern SDL_Window* gWindow;
extern SDL_Surface* gScreenSurface;
extern SDL_Renderer* gRenderer;


void init(int width, int height);
void close();

#endif // SDLHELPER_H
