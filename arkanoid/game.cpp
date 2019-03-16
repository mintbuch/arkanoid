#include "game.h"

#include <iostream>

#include "sdlhelper.h"

Game::Game()
{
    player = Player();
    gameLoop();
}
void Game::gameLoop()
{
    const float fps = 25;

    Uint32 ticks_last_millis = SDL_GetTicks();
    Uint32 ticks_now_millis;

    bool doQuit;
    while(true)
    {
        ticks_now_millis = SDL_GetTicks();

        Uint32 delta_t_ms = static_cast<float>(ticks_now_millis - ticks_last_millis);

        handleEvent(doQuit);
        if(doQuit)
        {
            return;
        }

        player.update(delta_t_ms);

        render();

        bool frames_dropped = true;
        // TODO: use something like SDL_Delay
        while (SDL_GetTicks() - ticks_last_millis < 1000.0 / fps)
        {
            // busy loop
            frames_dropped = false;
        }
        if (frames_dropped)
        {
            std::cerr << "warning: framedrop\n";
        }

        ticks_last_millis = ticks_now_millis;
    }
}

void Game::render()
{
    SDL_SetRenderDrawBlendMode(gRenderer, SDL_BLENDMODE_BLEND);

    SDL_SetRenderDrawColor(gRenderer, 0, 255, 0, 0);
    SDL_RenderClear(gRenderer);

    player.render(gRenderer);

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
        {
            SDL_Keycode kc = event.key.keysym.sym;
            switch(kc)
            {
            case SDLK_ESCAPE:
                doQuit = true;
                break;
            case SDLK_LEFT:
                player.moveLeft();
                break;
            case SDLK_RIGHT:
                player.moveRight();
                break;
            }

            break;
        }
        case SDL_KEYUP:
            player.stop();
        }
    }
}
