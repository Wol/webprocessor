
#ifndef AND_H
#define AND_H

#include "../CircuitItem.h"
#include "../Connection.h"


class And : public CircuitItem {

public:
    And(std::string  name, CircuitItem *parent);

    void update() override;

public:

    Connection A;
    Connection B;
    Connection Out;


};


#endif
