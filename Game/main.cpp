#pragma once
#include "Game.h"

int main()
{
    Game game;

    //Main Loop
    while (game.getWindowIsOpen()) 
    {
        game.update();
        //Draws all the assists to the screen
        game.render(); 
    }
    return 0;
}

