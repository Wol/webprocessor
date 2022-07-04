
#ifndef EIGHTBITADDER_H
#define EIGHTBITADDER_H

#include "../Pin.h"
#include "FullAdder.h"
#include "../Bus.h"
#include "../SimpleGates/LogicLevel.h"

class EightBitAdder : public CircuitItem {

public:
    EightBitAdder(std::string  name, CircuitItem *parent);


    Pin A{8};
    Pin B{8};
    Pin Sum{8};

    Pin Carry_Out{1};
    Pin Carry_In{1};

private:


    FullAdder Adders[8];
    Bus Adder_Carry[7];
};


#endif
