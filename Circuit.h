
#ifndef CIRCUIT_H
#define CIRCUIT_H

#include <list>
#include "Bus.h"
#include "Connection.h"
#include "CircuitItem.h"

class Circuit : public CircuitItem {


public:


    Circuit(std::string mName);

    void tick();


    static std::vector<CircuitItem*> Items;
    static std::list<CircuitItem*> ItemsToRecalculate;
    static Bus* Ground_Bus;
    static Bus* Power_Bus;


    static void debugAllItems();

protected:

};


#endif
