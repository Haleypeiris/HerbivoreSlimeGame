#pragma once
#include "Game.h"

int main()
{
    Game game;

    while (game.getWindowIsOpen()) //Main Loop
    {
        game.update();
        game.render();
    }
    return 0;
}

