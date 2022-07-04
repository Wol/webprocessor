
#ifndef EVENTLOOP_H
#define EVENTLOOP_H

#include "Bus.h"
#include "Connection.h"

#include <set>

class Circuit;

class EventLoop {

public:

    EventLoop(Circuit *circuit);


    void tick();


    void addBusToRecalculate(Bus *bus);
    void addGateToRecalculate(Gate *gate);


private:



    std::set<Bus*> changed_buses;
    std::set<Gate*> changed_gates;

    Circuit *circuit = nullptr;


};


#endif
