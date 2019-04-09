//#include <iostream>
#include "game.h"

//using namespace std;

int main()
{
    Game game;

    while(!game.getExit())
    {
        game.runFrame();
        game.writeFrame();
    }
    return 0;
}
