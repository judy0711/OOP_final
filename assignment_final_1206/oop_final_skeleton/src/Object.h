#ifndef _OBJECT_H
#define _OBJECT_H

#include "Grid.h"

class Object {
public:
    Object(int x, int y);

    /**
     * Returns corresponding symbol (char) of the object. (P=player, G=goal, E=enemy)
     * Implement this method in the derived classes.
     * @return
     */
    virtual char getSymbol() = 0;

    /**
     * Returns corresponding color (int) of the object. (COLOR_SET_PLAYER, COLOR_SET_GOAL, COLOR_SET_ENEMY)
     * Implement this method in the derived classes.
     * @return
     */
    virtual int getColor() = 0;

    /**
     * Returns the x coordinate of the object.
     * @return
     */
    inline int getX() { return x; }

    /**
     * Returns the y coordinate of the object.
     * @return
     */
    inline int getY() { return y; }

    /**
     * Moves the object to the given direction. (x + diffX, y + diffY)
     * You can check whether new position is valid or not by using occupiedArea.
     * @param x
     * @param y
     * @param occupiedArea
     * @return true if the object is moved, false otherwise.
     */
    bool updatePosition(int diffX, int diffY, Grid2D<bool> *occupiedArea);

private:
    int x, y;
};

#endif
