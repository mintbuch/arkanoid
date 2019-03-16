#include "player.h"

#include <algorithm>
#include <iostream>

Player::Player()
    : GameObject()
{
    motionKeyX = 0.0;
    motionX = 0.0;

    posX = 50;
    posY = 300;

    width = 50;
    height = 20;
}

void Player::update(Uint32 delta_t_ms)
{
    float mot = motionX + motionKeyX;
    posX += mot * delta_t_ms;
    motionX = mot * 0.96;

    //std::cout << v << " " << mot << " " << motionX << std::endl;

    /*const float mu = 1.0f;
    float a;

    if (v < 0)
    {
        a = motionX + mu;
    }
    else if (v > 0)
    {
        a = motionX - mu;
    }

    const float v_max = 500.0 / 1000; // [px/ms] // TODO
    // posX += motionX * delta_t_ms;
    const auto t = delta_t_ms;
    // posX += v * t + 0.5 * motionX * delta_t_ms * delta_t_ms;
    v = v + a * delta_t_ms;
    v = std::max(-v_max, std::min(v, v_max));
    posX += v * t;
    std::cout << v << '\n';*/
}

void Player::render(SDL_Renderer *gRenderer)
{
    SDL_SetRenderDrawColor(gRenderer, 0, 0, 255, 100);
    SDL_Rect rect{static_cast<int>(posX), static_cast<int>(posY), static_cast<int>(width), static_cast<int>(height)};
    SDL_RenderFillRect(gRenderer, &rect);
}

void Player::moveLeft()
{
    motionKeyX = -0.05;
}
void Player::moveRight()
{
    motionKeyX = 0.05;
}

void Player::stop()
{
    motionKeyX = 0;
}
