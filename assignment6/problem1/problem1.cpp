#include <iostream>
#include <cstdlib>
#include <string>

#include "airport.h"
#include "flight.h"
#include "airline.h"

using namespace std;

int main() {
    Airport *lax = new Airport("LAX", "LA"); // LA airport
    Airport *icn = new Airport("ICN", "Incheon"); // Incheon airport
    Airport *gmp = new Airport("GMP", "Gimpo"); // Gimpo airport
    Airport *jfk = new Airport("JFK", "New York"); // New York airport
    Airport *lhr = new Airport("LHR", "London"); // London airport

    Airline *oz = new Airline("Asiana");
    Airline *aa = new Airline("American");
    Airline *ba = new Airline("British");
    Airline *ka = new Airline("Korean");
    Airline *lh = new Airline("Lufthansa");

    Flight *ba110 = new Flight("BA110", ba, lhr, "1800", icn, "0840");
    Flight *oz365 = new Flight("OZ365", oz, lax, "1000", icn, "0800");
    Flight *aa298 = new Flight("AA298", aa, icn, "0900", lax, "1200");

    icn->show();

    oz365->setSchedule("0900", "2350");

    icn->show();

    lax->show();

    delete aa298;
}