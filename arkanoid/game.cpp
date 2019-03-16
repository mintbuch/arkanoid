#include "game.h"

#include "sdlhelper.h"

Game::Game()
{
    gameLoop();
}
void Game::gameLoop()
{
    bool doQuit;
    while(true)
    {
        handleEvent(doQuit);
        if(doQuit)
        {
            return;
        }

        render();
    }
}

void Game::render()
{
    SDL_SetRenderDrawBlendMode(gRenderer, SDL_BLENDMODE_BLEND);

    SDL_SetRenderDrawColor(gRenderer, 0, 255, 0, 0);
    SDL_RenderClear(gRenderer);

    SDL_SetRenderDrawColor(gRenderer, 0, 0, 255, 100);
    SDL_Rect rect{100, 100, 200, 50};
    SDL_RenderFillRect(gRenderer, &rect);

    SDL_RenderPresent(gRenderer);
}

void Game::handleEvent(bool& doQuit)
{
    SDL_Event event;

    doQuit = false;
    while(SDL_PollEvent(&event) != 0)
    {
        switch(event.type)
        {
        case SDL_QUIT:
            doQuit = true;
            break;
        case SDL_KEYDOWN:
            SDL_Keycode kc = event.key.keysym.sym;
            if(kc == SDLK_ESCAPE)
            {
                doQuit = true;
            }
            break;
        }
    }
}
