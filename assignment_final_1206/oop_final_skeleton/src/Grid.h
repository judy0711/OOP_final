#ifndef _GRID_H
#define _GRID_H

template<typename T>
class Grid2D {
public:
    Grid2D(int width, int height) {
        // TODO: write your code here
    }

    Grid2D(int width, int height, T defaultValue) {
        // TODO: write your code here
    }

    ~Grid2D();

    /**
     * Get the value at the given position.
     * @param x
     * @param y
     * @return
     */
    T &get(int x, int y) {
        // TODO: write your code here
    }

    /**
     * Set the value of the grid at the given position.
     * @param x
     * @param y
     * @param value
     */
    void set(int x, int y, T value);

    /**
     * Fill all cells in the grid to the given value.
     * @param value
     */
    void fill(T value) {
        // TODO: write your code here
    }

    inline int getWidth() { return width; }

    inline int getHeight() { return height; }

private:
    T *grid;
    int width, height;
};

#endif
