#ifndef PROCESSOR_NOT_H
#define PROCESSOR_NOT_H


#include "../Gate.h"

class Not : public Gate {

public:
    Not(std::string name, CircuitItem *parent);

    void update(EventLoop &eventLoop) override;

public:

    Connection A;
    Connection Out;
};


#endif //PROCESSOR_NOT_H
