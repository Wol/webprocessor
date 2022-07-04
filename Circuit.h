
#ifndef CIRCUIT_H
#define CIRCUIT_H

#include "Bus.h"
#include "Connection.h"
#include "EventLoop.h"
#include "CircuitItem.h"

class Circuit : public CircuitItem {


public:


    Circuit(std::string mName);

    void tick();


    static std::vector<CircuitItem*> Items;
    static Bus* Ground_Bus;
    static Bus* Power_Bus;


    static void debugAllItems();

protected:
    EventLoop eventloop;





};


#endif
