#ifndef PLAYER_H
#define PLAYER_H

#include "gameobject.h"

class Player : public GameObject
{
public:
    Player();
    void update(Uint32 delta_t_millis) override;
    void render(SDL_Renderer *gRenderer) override;

    void moveLeft();
    void moveRight();
    void stop();

private:
    float motionKeyX;
    float motionX;
    float boost;

    float posX;
    float posY;

    float width;
    float height;
};

#endif // PLAYER_H
