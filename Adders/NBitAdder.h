
#ifndef NBITADDER_H
#define NBITADDER_H

#include "../Pin.h"
#include "FullAdder.h"
#include "../Bus.h"
#include "../SimpleGates/LogicLevel.h"

class NBitAdder : public CircuitItem {

public:
    NBitAdder(std::string  name, CircuitItem *parent, uint8_t size);


    Pin A;
    Pin B;
    Pin Sum;

    Pin Carry_Out{"Carry_Out", this, 1};
    Pin Carry_In{"Carry_In", this, 1};

private:


    std::vector<FullAdder *> Adders;
    std::vector<Bus *> Adder_Carry;
};


#endif
