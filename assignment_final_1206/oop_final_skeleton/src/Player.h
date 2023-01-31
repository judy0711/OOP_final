#ifndef _PLAYER_H
#define _PLAYER_H

#include "variables.h"
#include "Object.h"
#include "Grid.h"

class Player : public Object {
public:
    Player(int x, int y);

    /**
     * Move player to the given direction.
     * @param direction ("MOVE_UP", "MOVE_DOWN", "MOVE_LEFT", "MOVE_RIGHT", "INPUT_NONE". See variables.h)
     * @param occupiedArea
     */
    void move(int direction, Grid2D<bool> *occupiedArea);

    char getSymbol();

    int getColor();
};

#endif
