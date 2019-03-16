#ifndef GAMEOBJECT_H
#define GAMEOBJECT_H

#include <SDL.h>

class GameObject
{
public:
    GameObject();
    virtual ~GameObject();

    virtual void update(Uint32 delta_t_ms) = 0;
    virtual void render(SDL_Renderer* gRenderer) = 0;
};

#endif // GAMEOBJECT_H
