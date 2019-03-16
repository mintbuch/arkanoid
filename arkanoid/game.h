#ifndef GAME_H
#define GAME_H

#include "player.h"

class Game
{
public:
    Game();
private:
    void gameLoop();
    void render();
    void handleEvent(bool& doQuit);
    Player player;
};

#endif // GAME_H
