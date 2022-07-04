
#ifndef ALU_H
#define ALU_H

#include "../Pin.h"
#include "../Bus.h"

#include "NBitAdder.h"
#include "../SimpleGates/Not.h"

class ALU : public CircuitItem {

public:
    ALU(std::string  name, CircuitItem *parent);

    Pin A{8};
    Pin B{8};
    Pin DataBus{8};

    Pin Subtract{1};
    Pin B_Bus_Enable{1}; // Otherwise B = 1.


private:

    NBitAdder Adder;

    XOr B_Input_Xors[8];
    Or B_Input_Or; // We use one OR gate for bit 0 so we can force the value to 1
    And B_Input_Ands[7];

    Bus B_Xored; // The B input is then Xored to possibly invert it.
    Bus B_Anded; // The input is ANDed so we can set B to 1 if needs be

    Bus B_Bus_Enable_Inverted;
    Not B_Bus_Enable_Not;

};


#endif
