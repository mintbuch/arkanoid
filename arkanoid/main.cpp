#include <iostream>
#include "sdlhelper.h"
#include "game.h"

int main(int, char*[])
{
    try
    {
        init(640, 480);
        Game game;

    }
    catch (std::runtime_error& e)
    {
        std::cerr << e.what() << '\n';
    }

    close();
    return 0;
}
