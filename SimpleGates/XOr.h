
#ifndef XOR_H
#define XOR_H

#include "../CircuitItem.h"
#include "../Connection.h"


class XOr : public CircuitItem {

public:
    XOr(std::string  name, CircuitItem *parent);

    void update() override;

    std::string status() override;

public:

    Connection A;
    Connection B;
    Connection Out;


};


#endif
