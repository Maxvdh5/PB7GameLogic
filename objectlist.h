#ifndef OBJECTLIST_H
#define OBJECTLIST_H

#include "object.h"

class objectList
{
public:
    objectList();
    ~objectList();
    void insertObject(int,int,int,int,int,bool,bool,bool);

    void printObjects();
    Object * getFirst();

private:
    int length;
    Object * first;
};

#endif // OBJECTLIST_H
