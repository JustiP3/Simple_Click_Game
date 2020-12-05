#include <iostream>
#include "Game.h" 

int main()
{
    //init srand
    std::srand(static_cast<unsigned>(time(NULL)));
 
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