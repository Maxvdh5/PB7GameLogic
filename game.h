#ifndef GAME_H
#define GAME_H

#include "states.h"

class Level;
class objectList;

class Game
{
public:
    Game();
    ~Game();

   bool getExit();

   void doSomething();

   void runFrame();
   void writeFrame();

private:
    bool exit;
    //Level * level;
    States * states[5];
    int vectCount;
    objectList * objects;

};

#endif // GAME_H
