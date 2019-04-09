#ifndef STATES_H
#define STATES_H


#include "object.h"
#include "objectlist.h"

class States
{
public:
    States();




    virtual void update()=0;
    virtual void insertObjects()=0;
    virtual void doGravity()=0;
    virtual bool checkCollision()=0;

    virtual void jump(Object *)=0;

    virtual objectList *getObjects()=0;

private:
    objectList * list;
};

#endif // STATES_H
