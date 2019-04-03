#include <iostream>

#include "objectlist.h"
#include "object.h"

objectList::objectList()
{
    this->length = 0;
    this->first = nullptr;
}

void objectList::insertObject(int x, int y,int velX,int velY, int sprite ,bool deathly, bool isStatic)
{
    Object * newObject = new Object(x, y, velX, velY, sprite, deathly, isStatic, this->first);
    this->first = newObject;
    length++;
}

void objectList::printObjects()
{
    Object * index = this->first;

    //while(index != nullptr)
    //{
       std::cout<< "x-as: "<<index->getX()<<std::endl;
       std::cout<< "y-as: "<<index->getY()<<std::endl;
       std::cout<< "sprite: "<<index->getSprite()<<std::endl;
       std::cout<< "is deathly: "<<index->getDeathly()<<std::endl;
       std::cout<< "is Static: "<<index->getIsStatic()<<std::endl<<std::endl;
       //index = index->getNext();
    //}
}

Object *objectList::getFirst()
{
    return this->first;
}
