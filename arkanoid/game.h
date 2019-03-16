#ifndef GAME_H
#define GAME_H


class Game
{
public:
    Game();
private:
    void gameLoop();
    void render();
    void handleEvent(bool& doQuit);
};

#endif // GAME_H
