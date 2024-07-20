#ifndef __FLIGHT_H__
#define __FLIGHT_H__

#include <iostream>
#include <cstdlib>
#include <string>

class Airport;
class Airline;

class Flight
{
    /*
        code: code of Flight (ex. OZ868, KA375) -> len: 5

        departure time : time of depature
        arrival time   : time of arrival
            time format: HHMM (ex. 0500, 2359) -> len: 4
    */
    public:
        Flight(char *code, Airline *airline, Airport *departure, char *departure_time, Airport *arrival, char *arrival_time); // contructor with departure airport and arrival airport
        ~Flight(); // detructor. It should print out "delete {Flight code}" (ex. deleted OZ868)
        void setSchedule(char *departure_time, char *arrival_time); // set the schedule of the flight
        char* getDepartureTime(); // get the time of departure
        char* getArrivalTime(); // get the time of arrival
        char* getCode(); // get the code of Flight
    private:
};

#endif