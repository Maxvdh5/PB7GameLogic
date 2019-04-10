//#include <iostream>
#include "game.h"

//using namespace std;

int main()
{
    Game game;

//    while(!game.getExit())
//    {
//        game.runFrame();
//        game.writeFrame();
//    }

    for(int i = 0; i<10; i++)
    {
        game.runFrame();
        game.writeFrame();
    }
    return 0;
}
