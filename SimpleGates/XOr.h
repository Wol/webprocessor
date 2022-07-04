
#ifndef XOR_H
#define XOR_H

#include "../Gate.h"


class XOr : public Gate {

public:
    XOr(std::string  name, CircuitItem *parent);

    void update(EventLoop &eventLoop) override;

    std::string status() override;

public:

    Connection A;
    Connection B;
    Connection Out;


};


#endif
