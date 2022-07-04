
#ifndef OR_H
#define OR_H

#include "../Gate.h"


class Or : public Gate {

public:
    Or(std::string  name, CircuitItem *parent);

    void update(EventLoop &eventLoop) override;

public:

    Connection A;
    Connection B;
    Connection Out;


};


#endif
