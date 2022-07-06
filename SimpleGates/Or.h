
#ifndef OR_H
#define OR_H

#include "../CircuitItem.h"
#include "../Connection.h"


class Or : public CircuitItem {

public:
    Or(std::string  name, CircuitItem *parent);

    void update() override;

public:

    Connection A;
    Connection B;
    Connection Out;


};


#endif
