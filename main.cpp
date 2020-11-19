#include <iostream>
#include "Game.h" 

int main()
{
 
    //Initialize Game

    Game game;

    while (game.getWindowIsOpen())
    {
        game.update();

        game.render();     
    }

    // End of application 
    return 0;
}