//#include <iostream>

#include "objectlist.h"
#include "object.h"

objectList::objectList()
{
    this->length = 0;
    this->first = nullptr;
}

objectList::~objectList()
{
    while(this->first != nullptr)
    {
        Object * del = this->first;
        this->first = this->first->getNext();
        delete del;
    }
}

void objectList::insertObject(int x, int y,int velX,int velY, int sprite ,bool deathly, bool isStatic,bool isSelected)
{
    Object * newObject = new Object(x, y, velX, velY, sprite, deathly, isStatic,isSelected, this->first);
    this->first = newObject;
    length++;
}

void objectList::printObjects()
{
    Object * index = this->first;

    //while(index != nullptr)
    //{
       xil_printf("x-as: %d",index->getX());
       xil_printf("y-as:  %d",index->getY());
       xil_printf("sprite: %d",index->getSprite());
       //index = index->getNext();
    //}
}

Object *objectList::getFirst()
{
    return this->first;
}
