#ifndef PROCESSOR_NOT_H
#define PROCESSOR_NOT_H


#include "../CircuitItem.h"
#include "../Connection.h"

class Not : public CircuitItem {

public:
    Not(std::string name, CircuitItem *parent);

    void update() override;

public:

    Connection In;
    Connection Out;
};


#endif //PROCESSOR_NOT_H
