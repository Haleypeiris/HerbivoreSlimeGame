#pragma once
#include "Game.h"
#include <Windows.h>

int main()
{
    Game game;

    //Hides the console
    HWND window;
    AllocConsole();
    window = FindWindowA("ConsoleWindowClass", NULL);
    ShowWindow(window, 0);


    //Main Loop
    while (game.getWindowIsOpen()) 
    {
        game.update();
        //Draws all the assists to the screen
        game.render(); 
    }
    return 0;
}

