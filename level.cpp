#include "level.h"
#include "object.h"
#include "objectlist.h"

Level::Level()
{
    list = new objectList;
    insertObjects();
    nextState = 98;
}

Level::~Level()
{
    delete this->list;
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
    for (int i = 0; i < 63; i++)
    {
            list->insertObject(i*10,390,0,0,0,false,true,false);

    }
    for (int j = 0; j < 5; j++)
    {
        for ( int k = j ; k < 9-j; k++)
        {
            list->insertObject(50+(k*10),j*20,0,0,0,false,false,false);
        }
    }

   for(int m = 0; m < 37; m++)
   {
         list->insertObject(60,m*10,0,0,0,false,true,false);
   }



    list->insertObject(10,0,0,0,0,false,false,false);

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
              if((moving->getX()+ moving->getVelX()) - index->getX() <= 10 && (moving->getY() - index->getY() < 10 && moving->getY() - index->getY() > -10 ))
              {

                  if(moving->getVelX()<0 && moving->getX() > index->getX())
                  {
                     moving->setVelX(((moving->getX()-index->getX())-10)*-1);
                     if((moving == list->getFirst() || moving == list->getFirst()->getNext()) && index->getDeathly()){
                         //do player killed stuff
                     }
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

void Level::goLeft()
{
    Object * player = this->list->getFirst();
    player->moveLeft();
}

void Level::goRight()
{
    Object * player = this->list->getFirst();
    player->moveRight();
}

void Level::goStop()
{
    Object * player = this->list->getFirst();
    player->moveStop();
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

void Level::createObjects()
{

}

void Level::goDown()
{

}



void Level::switchSelected(Object *)
{

}

int Level::doSelected()
{
    return nextState;
}

void Level::setSelected()
{

}

