//#include <iostream>

#include "objectlist.h"
#include "object.h"
#include <iostream>

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

    while(index != nullptr)
    {
       std::cout<< "x-as: "<<index->getX()<<std::endl;
       std::cout<< "y-as: "<<index->getY()<<std::endl;
       std::cout<< "sprite: "<<index->getSprite()<<std::endl;
       std::cout<< "is deathly: "<<index->getDeathly()<<std::endl;
       std::cout<< "is Static: "<<index->getIsStatic()<<std::endl;
       std::cout<<"is Selected: "<<index->getIsSelected()<<std::endl<<std::endl;
       index = index->getNext();
    }
}

Object *objectList::getFirst()
{
    return this->first;
}
