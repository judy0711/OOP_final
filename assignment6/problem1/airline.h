#ifndef __AIRLINE_H__
#define __AIRLINE_H__

#include <iostream>
#include <cstdlib>
#include <string>

class Airline
{
    /*
        name: name of Airline (ex. Asiana, Lufthansa)
    */
    public:
        Airline(char *name);
        void setName(char *name); // set the name of Airline
        char* getName(); // get the name of Airline
    private:
};

#endif