#ifndef __AIRPORT_H__
#define __AIRPORT_H__

#include <iostream>
#include <cstdlib>
#include <string>

class Flight;

class Airport
{
    /*
        code: code of Airport (ex. LAX, ICN) -> len: 3
        name: name of Airport (ex. Incheon, Gimpo) -> len < 20
        
        Arrival flights of the airport are always fewer than 10.
        Departure flights of the airport are always fewer than 10.

    */
    public:
        Airport(char *code, char *name);
        char* getName(); // get the name of Airport
        char* getCode(); // get the code of Airport
        void show(); 
        /*
            It shows all arrival flights and departure flights.
            All schedules have to be sorted in accending order by the time.
                departure list is ordered by departure time.
                arrival list is ordered by arrival time.
            If the informations of flights are updated, it should reflect that.

            You must keep the below format

            ====== Fligh Schedule ({Airport name}) ======
            [departure]
            {Flight code} {Source Airport code} {Depart time} {Destination Airport code} {Arrive time} (Airline name)
            {\new line}
            {\new line}
            [arrival]
            {Flight code} {Source Airport code} {Depart time} {Destination Airport code} {Arrive time} (Airline name)
            {\new line}
            {\new line}

            !! (example)
            ====== Fligh Schedule (Incheon) ======
            [departure]
            AA298 ICN 0900 LAX 1200 (American)


            [arrival]
            OZ365 LAX 1000 ICN 0800 (Asiana)
            BA110 LHR 1800 ICN 0840 (British)


        */
    private:
};

#endif