#ifndef _ENEMY_H
#define _ENEMY_H

#include "Grid.h"
#include "Object.h"

class Enemy : public Object {
public:
    Enemy(int x, int y, int moveInterval);

    char getSymbol();

    int getColor();

    /**
     * Moves the enemy to the next position.
     * You should implement the own movements of the enemy in the derived classes.
     * @param occupiedArea
     */
    virtual void move(Grid2D<bool> *occupiedArea) = 0;

    virtual void guard(Grid2D<bool> *guardArea, Grid2D<bool> *occupiedArea) = 0;

private:
    int moveInterval;
    int currentTick;
};

class VerticalEnemy;

class HorizontalEnemy;

class StandingEnemy;

#endif