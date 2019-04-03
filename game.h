#ifndef GAME_H
#define GAME_H


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
    objectList * objects;

};

#endif // GAME_H
