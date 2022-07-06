#ifndef PROCESSOR_H
#define PROCESSOR_H


#include "Circuit.h"
#include "Bus.h"
#include "SimpleGates/And.h"
#include "SimpleGates/LogicLevel.h"
#include "Adders/FullAdder.h"
#include "Adders/NBitAdder.h"
#include "Adders/ALU.h"

class Processor : public Circuit {
public:
    Processor();


    LogicLevel A;
    LogicLevel B;
    LogicLevel Sum;

    ALU alu;

    LogicLevel X;
    LogicLevel Y;
    LogicLevel Z;


    Bus a;
    Bus b;
    Bus sum_bus;

    Bus x_bus;
    Bus y_bus;
    Bus z_bus;



    void setInputs(BusValue i, BusValue i1, BusValue x, BusValue y, BusValue z);

    // So what does a processor consist of.



    BusValue getSumOutput();
    BusValue getCarryOutput();
};


#endif
