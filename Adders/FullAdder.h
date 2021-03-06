
#ifndef FULLADDER_H
#define FULLADDER_H


#include "../Bus.h"
#include "../Pin.h"
#include "../SimpleGates/XOr.h"
#include "../SimpleGates/And.h"
#include "../SimpleGates/Or.h"

class FullAdder : public CircuitItem {

public:
    FullAdder(std::string  name, CircuitItem *parent);



public:


    Pin A{"A", this, 1};
    Pin B{"B", this, 1};
    Pin Carry_In{"Carry_In", this, 1};

    Pin Sum{"Sum", this, 1};
    Pin Carry_Out{"Carry_Out", this, 1};

private:

    XOr AB_Xor;
    And AB_And;
    XOr AB_C_Xor;
    And AB_C_And;
    Or Carry_Or;

    Bus AB_Xor_Out;
    Bus AB_And_Out;
    Bus AB_C_And_Out;

};


#endif
