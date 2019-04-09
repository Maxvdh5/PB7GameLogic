#ifndef GAME_H
#define GAME_H

#include <iostream>
#include <vector>
#include "states.h"

class Level;
class objectList;

class Game
{
public:
    Game();
    //~Game();

   bool getExit();

   void doSomething();

   void runFrame();
   void writeFrame();

private:
    bool exit;
    Level * level;
    std::vector<States*> states;
    objectList * objects;

};

#endif // GAME_H
