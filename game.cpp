#include "game.h"
#include "objectlist.h"
#include "object.h"
#include "level.h"
#include "start.h"
#include "highscore.h"
#include "states.h"


Game::Game()
{
    this->exit = false;
    states = new start();
    this->objects = nullptr;
    this->index = 0;
    this->locIndex = 0;
}

Game::~Game()
{

}

bool Game::getExit()
{
    return this->exit;
}

void Game::runFrame()
{
    index = locIndex;

    switch(index)
    {
    case 0: locIndex = startState();  delete states; states = new start(); break;
    case 1: levelState(); delete states; states = new Level() ; break;
    case 99: break;
    }


}

void Game::writeFrame()
{
    this->objects = this->states->getObjects();
    this->objects->printObjects();
       this->exit = true;
}

int Game::startState()
{
    //do interupt stuff
    return this->states->doSelected();
}

void Game::levelState()
{

}

int Game::highscoreState()
{
    return 0;
}

//void Game::doSomething()
//{
//    for(int i =0; i< 10; i++)
//    {
//        std::cout << i << std::endl;

//    }
//    this->exit = true;
//}
