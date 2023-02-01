#ifndef _GRID_H
#define _GRID_H

#include <vector>


template<typename T>
class Grid2D {
public:
    Grid2D(int width, int height) : width(width), height(height) {
        int length = width * height;
        std::vector<T> grid(length);
    }

    Grid2D(int width, int height, T defaultValue) : width(width), height(height) {
        // Good job. Let's do the get method next
        int length = width * height;
        std::vector<T> grid(length, defaultValue);
    }

    ~Grid2D();

    /**
     * Get the value at the given position.
     * @param x
     * @param y
     * @return
     */
    T &get(int x, int y) {
        // formula is y*width+x if you need a reminder
        // TODO: write your code here
        int cor = y * this->width + x;
        // correct, now we just need to index grid
        //perfect!
        return this->grid[cor];

        // the dereferencing for the grid[cor] is an address?? 

        // This method would be called like grid_variable_name.get(1, 2);
        // Since the variable you want, "grid" is owned by "grid_variable_name" and not provided as a variable or something,
        // you need to tell the computer that we're access the version of "grid" owned by the variable calling this method.
        // We do that with the "this" keyword, which returns a pointer to the caller. You can't call a method for T on a T*,
        // so we dereference it first. -> is a shorthand for dereferencing, then calling a method/member
        // Does that make sense? yes
        // Do you have any more questions about this method? No, it's clear now.
        // Yay. Let's do the "set" method next, it'll be pretty similar

        // need help?
        // yes, I am stucked.
        // There's a keyword you're missing for accessing variables owned by a struct/class
        // Do you know what that keyword is?
        // this.width
        // No that is for accessing a method (and i dont think it would work that way either)
        // the keyword is "this"
        // So close. C++ is weird. "this" is a pointer to what you want. So you can either do:
        //    (*this).width
        //or  this->width
        // Most people prefer ->
        // -> is the same thing as dereferencing, then calling a method/member
        // perfect!
        // Now for the return value
        // Grid is a member of an instance of Grid2D, so we're going to need to use "this" again
    }

    /**
     * Set the value of the grid at the given position.
     * @param x
     * @param y
     * @param value
     */
    void set(int x, int y, T value){
        // Logic is perfect there, but remember, "this" is a pointer, it can't be used with a "."
        // perfect!
        // Any questions?
        // I kind of start to get the pointer thing now. 
        // yay
        // Wanna try to implement the fill method now?
        int cor = y * this->width + x;
        this->grid[cor] = value;
    }

    /**
     * Fill all cells in the grid to the given value.
     * @param value
     */
    void fill(T value) {
        // TODO: write your code here
        // You're on the right track with "for"
        // What are we going to iterate over?
        // Do you know how to iterator over a vector without indexes?
        // What do you mean? like a  while loop?
        // No a for loop, but with no adding and stuff, just saying "for everything in x, do {stuff}"
        // Have you used Python?
        // Yes
        // So in Python, you can do:
        // for x in list_name:
            // stuff
        // You can do something like that in C++. Do you know how?
        // for(T& x : this->grid)
        // Pretty much, you just need to define the type of x
        // not int. What is grid a vector of? exactly! 
        // and how do we access grid? it's owned by an instance of Grid2D.
        // this?
        // yep! exactly!
        // Oh btw, T is a T&, we're getting a reference to the value in the grid so we can modify it
        // What do you put after the () section of a for loop? yep!
        // You don't need to access this in there,
        // x is a reference to what you need to modify
        // It's a reference, so you don't need to dereference it (even though the naming of it sounds like you do)
        // You only need to dereference pointers
        // yep! that should work!
        for(T& x : this->grid){
            x = value;
        }
    }

    inline int getWidth() { return width; }

    inline int getHeight() { return height; }

private:
    std::vector<T> grid;
    int width, height;
    int length;
};

#endif
