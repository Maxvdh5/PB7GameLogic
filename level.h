#ifndef LEVEL_H
#define LEVEL_H

class objectList;
class Object;
#include "states.h"

class Level : public States
{
public:
    Level();

    void update();
    void insertObjects();
    void doGravity();
    bool checkCollision();

    void jump(Object *);

    objectList *getObjects();

private:
    objectList * list;
};

#endif // LEVEL_H
