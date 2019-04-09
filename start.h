#ifndef START_H
#define START_H
#include "states.h"

class start : public States
{
public:
    start();

    void update() override;
    void insertObjects() override;
    void doGravity() override;
    bool checkCollision() override;

    void jump(Object *) override;

    objectList *getObjects() override;
};

#endif // START_H
