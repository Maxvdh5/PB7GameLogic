#include "game.h"
#include "objectlist.h"
#include "object.h"
#include "level.h"
#include "states.h"


Game::Game()
{
    this->exit = false;
    states[0] = new Level();
    vectCount = 1;
    this->objects = nullptr;
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
    for( int i = 0; i < 100; i++){
        this->states[0]->doGravity();
        this->states[0]->checkCollision();
        this->states[0]->update();
       // writeFrame();
    }

    this->objects = this->states[0]->getObjects();
    Object * player =  this->states[0]->getObjects()->getFirst();

    for( int i = 0; i < 40; i++){

        player->moveRight();
        this->states[0]->doGravity();
        this->states[0]->checkCollision();
        this->states[0]->update();
        writeFrame();
    }

     this->states[0]->jump(player);

    for( int i = 0; i < 40; i++){

        player->moveRight();
        this->states[0]->doGravity();
        this->states[0]->checkCollision();
        this->states[0]->update();
        writeFrame();
    }

}

void Game::writeFrame()
{
    this->objects = this->states[0]->getObjects();
    this->objects->printObjects();
    this->exit = true;
}

//void Game::doSomething()
//{
//    for(int i =0; i< 10; i++)
//    {
//        std::cout << i << std::endl;

//    }
//    this->exit = true;
//}
