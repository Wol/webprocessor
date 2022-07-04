
#ifndef AND_H
#define AND_H

#include "../Gate.h"


class And : public Gate {

public:
    And(std::string  name, CircuitItem *parent);

    void update(EventLoop &eventLoop) override;

public:

    Connection A;
    Connection B;
    Connection Out;


};


#endif
