#include "game.h"
#include "objectlist.h"
#include "object.h"
#include "level.h"
#include <iostream>

Game::Game()
{
    this->exit = false;
    level = new Level();
    this->objects = nullptr;
}

bool Game::getExit()
{
    return this->exit;
}

void Game::runFrame()
{
    for( int i = 0; i < 100; i++){
        this->level->doGravity();
        this->level->checkCollision();
        this->level->update();
       // writeFrame();
    }

    this->objects = this->level->getObjects();
    Object * player =  this->objects->getFirst();

    for( int i = 0; i < 40; i++){

        player->moveRight();
        this->level->doGravity();
        this->level->checkCollision();
        this->level->update();
        writeFrame();
    }

     this->level->jump(player);

    for( int i = 0; i < 40; i++){

        player->moveRight();
        this->level->doGravity();
        this->level->checkCollision();
        this->level->update();
        writeFrame();
    }

}

void Game::writeFrame()
{
    this->objects = this->level->getObjects();
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
