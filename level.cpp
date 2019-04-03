#include "level.h"
#include "object.h"
#include "objectlist.h"

Level::Level()
{
    list = new objectList;
    insertObjects();
}

void Level::update()
{
  Object * index = this->list->getFirst();

  while(index != nullptr)
  {
      index->doUpdate();

      index = index->getNext();
  }

}

void Level::insertObjects()
{
    for (int i = 0; i < 10; i++)
    {
            list->insertObject(i*10,100,0,0,0,false,true);
    }

    list->insertObject(30,0,0,0,0,false,false);

    list->insertObject(10,0,0,0,0,false,false);

}

void Level::doGravity()
{
    Object * index = this->list->getFirst();
    while(index != nullptr)
    {
        index->doGravity();
        index = index->getNext();
    }

}

bool Level::checkCollision()//+ directon
{
  Object * moving = list->getFirst();
  Object * index =list->getFirst();
  while(moving != nullptr)
  {
      while(index != nullptr)
      {
          if(index != moving)
          {
//              if(moving->getX() - index->getX() <= 10 && (moving->getY() - index->getY() < 10 && moving->getY() - index->getY() > -10 ))
//              {
//                  if(moving->getVelX()>0)
//                  {
//                      moving->setVelX(0);
//                  }
//                  //moving->direction =  static_cast<Object::Direction>(moving->direction & ~moving->E);
//              }

//              if(moving->getY() - index->getY() >= -10 && (moving->getX() - index->getX() < 10 && moving->getX() - index->getX() > -10 ))
//              {
//                 if(moving->getVelY() >0)
//                 {
//                     moving->setVelY(0);
//                 }
//                 //moving->direction = static_cast<Object::Direction>(moving->direction & ~moving->S);
//              }

//              if(moving->getX() - index->getX() >= -10 && (moving->getY() - index->getY() < 10 && moving->getY() - index->getY() > -10 ))
//              {
//                  if(moving->getVelX()<0)
//                  {
//                      moving->setVelX(0);
//                  }
//                  //moving->direction = static_cast<Object::Direction>(moving->direction & ~moving->W);
//              }

//              if(moving->getY() - index->getY() <= 10 && (moving->getX() - index->getX() < 10 && moving->getX() - index->getX() > -10 ))
//              {
//                  if(moving->getVelY() <0)
//                  {
//                      moving->setVelY(0);
//                  }
//                  //moving->direction = static_cast<Object::Direction>(moving->direction & ~moving->N);
//              }
  //vgv
              if((moving->getX()+ moving->getVelX()) - index->getX() <= 10 && (moving->getY() - index->getY() < 10 && moving->getY() - index->getY() > -10 ))
              {

                  if(moving->getVelX()<0 && moving->getX() > index->getX())
                  {
                     moving->setVelX(((moving->getX()-index->getX())-10)*-1);
                  }

                  //moving->direction =  static_cast<Object::Direction>(moving->direction & ~moving->E);
              }

              if((moving->getY() + moving->getVelY()) - index->getY()  >= -10 && (moving->getX() - index->getX() < 10 && moving->getX() - index->getX() > -10 ))
              {

                  if(moving->getVelY() >0 && moving->getY() < index->getY())
                  {
                      moving->setVelY(((moving->getY()-index->getY())+10)*-1);
                  }

                 //moving->direction = static_cast<Object::Direction>(moving->direction & ~moving->S);
              }

              if((moving->getX() + moving->getVelX()) - index->getX()  >= -10 && (moving->getY() - index->getY() < 10 && moving->getY() - index->getY() > -10 ))
              {

                  if(moving->getVelX()>0 && moving->getX() < index->getX())
                  {
                    moving->setVelX(((moving->getX()-index->getX())+10)*-1);
                  }

                  //moving->direction = static_cast<Object::Direction>(moving->direction & ~moving->W);
              }

              if((moving->getY() + moving->getVelY() ) - index->getY() <= 10 && (moving->getX() - index->getX() < 10 && moving->getX() - index->getX() > -10 ))
              {

                  if(moving->getVelY() < 0 && moving->getY() > index->getY())
                  {
                    moving->setVelY(((moving->getY()-index->getY())+10)*-1);
                  }

                  //moving->direction = static_cast<Object::Direction>(moving->direction & ~moving->N);
              }
          }
          index = index->getNext();
      }
      index = list->getFirst();
      moving = moving->getNext();
  }


}

void Level::jump(Object * moving)
{
    Object * index = this->list->getFirst();

    while(index != nullptr)
    {
        if(index != moving)
        {
            if(moving->getY()  - index->getY()  >= -10 && (moving->getX() - index->getX() < 10 && moving->getX() - index->getX() > -10 ))
            {
                moving->moveUp();
                return;
            }
        }

        index = index->getNext();
    }
}





objectList *Level::getObjects()
{
    return this->list;
}

